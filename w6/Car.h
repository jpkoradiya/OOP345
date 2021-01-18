/*
Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
	class Car :public Vehicle{
		std::string c_maker{ "" };
		char c_condition{ ' ' };
		double c_topspeed{ 0 };
	public:
		Car() {};
		~Car() {};
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif