/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 17/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
namespace sdds {
	class Restaurant{
		Reservation* rsp;
		size_t rs_noOfRes{0};
	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		
		//copy 
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		//move
		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		friend std::ostream& operator<<(std::ostream&, Restaurant&);
	};
}

#endif //!SDDS_RESTAURANT_H
