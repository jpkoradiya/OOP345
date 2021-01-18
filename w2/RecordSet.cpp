/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 02/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include "RecordSet.h"


namespace sdds {
	void RecordSet::setEmpty() {
		rs_noOfStr = 0;
		rs_strArr = nullptr;
		rs_filename = "";
	}

	RecordSet::RecordSet() {
		setEmpty();
	}

	RecordSet::RecordSet(const std::string& fn): rs_strArr{nullptr}, rs_noOfStr{0} {
		if (!fn.empty()) {

			rs_filename = fn;
			std::string temp;
			std::ifstream is(fn);

			while (getline(is, temp, ' ')) {
				rs_noOfStr++;
			}

			if (rs_noOfStr > 0) {
				is.clear();
				is.seekg(0);//moving the file pointer back to start

				rs_strArr = new std::string[rs_noOfStr];
				size_t strIndex{ 0 };
				while (getline(is, rs_strArr[strIndex], ' ')) {
					strIndex++;
				}
			}
			is.close();//closing the file reference
		}
		else {
			setEmpty();
		}
	}


	RecordSet::RecordSet(RecordSet& cpy) { //copy constructor
		*this = cpy;
	}

	RecordSet::RecordSet(RecordSet&& mv) {
		*this = std::move(mv);
	}

	RecordSet& RecordSet::operator=(RecordSet&& mv) {
		if (this != &mv) {
			
			rs_filename = mv.rs_filename;
			mv.rs_filename = "";
			rs_noOfStr = mv.rs_noOfStr;
			mv.rs_noOfStr = 0;
			
			rs_strArr = mv.rs_strArr;
			mv.rs_strArr = nullptr;


		}
		return *this;
	}

	RecordSet& RecordSet::operator=(const RecordSet& cpy) {
		if (this != &cpy) {//checking that it's not the same
			if (cpy.rs_strArr != nullptr) {  //checking if the copy is valid
				
				rs_filename = cpy.rs_filename;
				rs_noOfStr = cpy.rs_noOfStr;
				rs_strArr = new std::string[rs_noOfStr];
				for (size_t i = 0; i < cpy.rs_noOfStr; i++) {
					rs_strArr[i] = cpy.rs_strArr[i];
				}

			}
		}
		return *this;
	}
	RecordSet::~RecordSet() {
		delete[] rs_strArr;
	}
	size_t RecordSet::size() {
		return rs_noOfStr;
	}
	std::string RecordSet::getRecord(size_t pos) {
		std::string ret = "";
		if (pos < rs_noOfStr) {
			ret = rs_strArr[pos];
		}
		return ret;
	}
}
