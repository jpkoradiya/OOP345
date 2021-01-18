/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 17/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::~ConfirmationSender(){
		if (resptr != nullptr) {
			delete[]resptr;
			resptr = nullptr;
			noOfRes = 0;
		}
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag = false; 
		for (size_t i = 0; i < noOfRes && !flag; i++) {
			if (&res == this->resptr[i]) {
				flag = true;
			}
		}

		if (!flag) {
			size_t size = noOfRes + 1;
			const Reservation** temp = new const Reservation * [size];
			for (size_t i = 0; i < noOfRes; i++) {
				temp[i] = resptr[i];
			}
			temp[noOfRes] = &res;

			noOfRes++;
			delete[] resptr;
			resptr = nullptr;
			resptr = temp;	
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < noOfRes; i++) {
			if (resptr[i] == &res) { 
				resptr[i] = nullptr;
				noOfRes--;
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& other){
		*this = other;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other)
	{
		if (this != &other) {
			this->noOfRes = other.noOfRes;
			delete[] resptr; 

			resptr = new const Reservation * [noOfRes];
			for (size_t i = 0; i < noOfRes; i++) {
				this->resptr[i] = other.resptr[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& other){
		*this = std::move(other);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other){
		if (this != &other) {
			this->noOfRes = other.noOfRes;
			delete[] resptr; 
			this->resptr = other.resptr;
			other.resptr = nullptr;
			other.noOfRes = 0;
		}
		return *this;
	}
	
	std::ostream& operator<<(std::ostream & os, ConfirmationSender & obj) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (obj.noOfRes==0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < obj.noOfRes; i++) {
				os << *obj.resptr[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}

	}
