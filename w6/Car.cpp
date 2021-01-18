/*
Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <string>
#include <iomanip>
#include <exception>

#include "Car.h"
namespace sdds {
	
	Car::Car(std::istream& is){
		 std::string temp;//temp string
		 std::getline(is,temp,',');

		 c_maker = trim(temp);

		 std::getline(is, temp, ',');
		 temp = trim(temp);
		 if (temp.empty()) 
			c_condition = 'n';
		 else {
			 c_condition = temp[0];
			 if (c_condition != 'u' && c_condition != 'n' && c_condition != 'b') {
				 throw std::invalid_argument("the record is invalid");
			 }
		 }


		 try {
			 std::getline(is, temp, ',');
			 c_topspeed = stod(trim(temp));
		 }
		catch (std::invalid_argument & e) {
			 throw e;
		}
	}
	
	std::string Car::condition() const
	{
		std::string condition;
		if (c_condition == 'n') {
			condition = "new";
		}
		else if(c_condition == 'u') {
			condition = "used";
		}
		else if (c_condition == 'b') {
			condition = "broken";
		}
		return condition;
	}
	double Car::topSpeed() const
	{
		return c_topspeed;
	}
	void Car::display(std::ostream& out) const{
		out << "| " << std::setw(10) << std::right  << c_maker;
		out << " | " << std::setw(6) << std::left << condition();
		out << " | " << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
	}
	
}