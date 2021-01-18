/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 17/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include<iostream>
#include <algorithm>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() {
		rs_RegId = "";
		rs_name = "";
		rs_email = "";
		rs_partySize = 0;
		rs_day = 0;
		rs_hour = 0;
	}
	Reservation::Reservation(const std::string& str) {

		std::string res = str;//temp string

		res.erase(std::remove(res.begin(), res.end(), ' '), res.end());

		int ind1 = res.find(':');
		rs_RegId = res.substr(0, ind1);

		res.erase(0, ind1 + 1);
		ind1 = res.find(',');
		rs_name = res.substr(0, ind1);

		res.erase(0, ind1 + 1);
		ind1 = res.find(',');
		rs_email = res.substr(0, ind1);

		res.erase(0, ind1 + 1);
		ind1 = res.find(',');
		rs_partySize = std::stoi(res);

		res.erase(0, ind1 + 1);
		ind1 = res.find(',');
		rs_day = std::stoi(res);

		res.erase(0, ind1 + 1);
		ind1 = res.find(',');
		rs_hour = std::stoi(res);

	}
	//Reservation::Reservation(const Reservation& obj){
	//	rs_RegId = obj.rs_RegId;
	//	rs_name = obj.rs_name;
	//	rs_email = obj.rs_email;
	//	rs_partySize = obj.rs_partySize;
	//	rs_day = obj.rs_day;
	//	rs_hour = obj.rs_hour;
	//}
	///*Reservation& Reservation::operator=(const Reservation& obj){
	//	if (this != &obj) {

	//	}
	//	return *this;
	//}*/
	std::ostream& operator<<(std::ostream& os, Reservation& obj) {
		os << "Reservation " << obj.rs_RegId + ": ";
		os << std::setw(10) << std::right << obj.rs_name << "  ";

		os << std::setw(20) << std::left << "<" + obj.rs_email + ">" << "    ";

		if (obj.rs_hour >= 6 && obj.rs_hour <= 9) {
			os << "Breakfast on day " << obj.rs_day << " @ " << obj.rs_hour << ":00 for " << obj.rs_partySize << " people." << std::endl;
		}
		else if (obj.rs_hour >= 11 && obj.rs_hour <= 15) {
			os << "Lunch on day " << obj.rs_day << " @ " << obj.rs_hour << ":00 for " << obj.rs_partySize << " people." << std::endl;
		}
		else if (obj.rs_hour >= 17 && obj.rs_hour <= 21) {
			os << "Dinner on day " << obj.rs_day << " @ " << obj.rs_hour << ":00 for " << obj.rs_partySize << " people." << std::endl;
		}
		else {
			os << "Drinks on day " << obj.rs_day << " @ " << obj.rs_hour << ":00 for " << obj.rs_partySize << " people." << std::endl;
		}
		return os;
	}
}