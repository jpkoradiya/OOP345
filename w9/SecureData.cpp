 /*Name: Jigarkumar Pritamkumar Koradiya
 Seneca Student ID: 164861189
 Seneca email: jpkoradiya@myseneca.ca
 Date of completion: 28/11/2020
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/



// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(ostream& os) const {
		if (text && !encoded)
			os << text << endl;
		else if (encoded)
			throw string("\n***Data is encoded***\n");
		else
			throw string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());
		//taking 4 threads
		const int noOfThreads = 4;
		//splitting
		int split = nbytes / noOfThreads;
		thread t[noOfThreads];
		Cryptor cryptors[noOfThreads];
		for (int i = 0; i < noOfThreads; i++) {
			//setting condition for last thread to capture all the text if in case the number is not divisible by the number of threads
			t[i] = thread(bind(converter, text + i * split, key, i + 1 < noOfThreads ? split : (nbytes - i * split), cryptors[i]));
		}
		//joining all the threads
		for (int i = 0; i < noOfThreads; i++)
			t[i].join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw string("\n***No data stored***\n");
		else if (!encoded)
			throw string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			ofstream binFile(file, ios::binary);
			if (!binFile)
				throw string("Unable to open [") + file + "] file.";

			// TODO: write data into the binary file
			//         and close the file
			binFile.write(this->text, this->nbytes);
			binFile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		ifstream binFile(file, ios::binary);
		if (!binFile)
			throw string("Unable to open [") + file + "] file.";

		// TODO: - allocate memory here for the file content
		//to get a file's size, we will seek the file to the end. After that, tellg() will give us the size of the file
		binFile.seekg(0, ios::end);
		this->nbytes = binFile.tellg();

		//deallocating the memory
		if (this->text)
			delete[] this->text;

		//allocating new memory
		this->text = new char[this->nbytes];

		// TODO: - read the content of the binary file
		//setting file pointer back to start
		binFile.seekg(0);
		binFile.read(this->text, this->nbytes);
		binFile.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	ostream& operator<<(ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}