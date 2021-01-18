/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 17/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
		rs_noOfRes = cnt;
		//delete[] rsp;
		rsp = nullptr;

		if (reservations!=nullptr) {
			rsp = new Reservation[cnt];
			for (size_t i = 0; i < rs_noOfRes; i++) {
				rsp[i] = *reservations[i];
			}
		}
	}

	size_t Restaurant::size() const{
		return rs_noOfRes;
	}
	Restaurant::Restaurant(const Restaurant& obj){
		if (this!=&obj) {
			//delete[] this->rsp;
			this->rsp = nullptr;

		}
	}
	Restaurant& Restaurant::operator=(const Restaurant& other){
		if (this != &other) {
			delete[] rsp;
			rsp = nullptr;
			rs_noOfRes = other.rs_noOfRes;
			rsp = new Reservation[rs_noOfRes];
			for (size_t i = 0; i <rs_noOfRes; i++) {
				rsp[i] = other.rsp[i];
			}
			
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& other){
		//delete[] rsp;
		rsp = nullptr;
		this->rs_noOfRes = other.rs_noOfRes;
		rsp = new Reservation[rs_noOfRes];
		for (size_t i = 0; i < rs_noOfRes; i++) {
			rsp[i] = other.rsp[i];
		}
		delete[] other.rsp;
		other.rsp = nullptr;
		other.rs_noOfRes = 0;
	}
	Restaurant& Restaurant::operator=(Restaurant&& other){
		if (this != &other) {
			delete[] rsp;
			rsp = nullptr;
			this->rs_noOfRes = other.rs_noOfRes;
			rsp = new Reservation[rs_noOfRes];
			for (size_t i = 0; i < rs_noOfRes; i++) {
				rsp[i] = other.rsp[i];
			}
			delete[] other.rsp;
			other.rsp = nullptr;
			other.rs_noOfRes = 0;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, Restaurant& obj){
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;
		if (obj.rs_noOfRes==0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < obj.rs_noOfRes; i++) {
				os << obj.rsp[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}