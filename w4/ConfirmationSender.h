/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 17/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender{
		const Reservation** resptr;
		size_t noOfRes;
	public:
		ConfirmationSender() {};//no implementation
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		//copy constructors and assignment operators
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		//move
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		friend std::ostream& operator<<(std::ostream&, ConfirmationSender&);
	};

}

#endif //!SDDS_CONFIRMATIONSENDER_H