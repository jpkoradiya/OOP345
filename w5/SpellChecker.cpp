/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 27/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <algorithm>
#include <fstream>

#include "SpellChecker.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename){
		
			std::ifstream file(filename);
		if(!file)
			throw "Bad file name!";
		else {
			std::string str{ "" };

			size_t i = 0u;
			do {
				std::getline(file, str);

				if (file) {
					size_t index = str.find(' ');
					m_badWords[i] = str.substr(0, index);
					str.erase(0, index);
					str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
					m_goodWords[i] = str;
					i++;
				}
			} while (file);

		}		
	}
	void SpellChecker::operator()(std::string& text) const {
		size_t found = 0;
		for (size_t i = 0; i < 5; i++) {
			while ((found = text.find(m_badWords[i])) != std::string::npos) {
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}
