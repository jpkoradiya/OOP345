/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 17/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>

namespace sdds {
	class Reservation {
		std::string rs_RegId;
		std::string rs_name;
		std::string rs_email;
		int rs_partySize;
		int rs_day;
		int rs_hour;

	public:

		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream&, Reservation&);
	};
}

#endif //!SDDS_RESERVATION_H