// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/*Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca
Date of copmletion: 22/11/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++) {
			bool match = false;//to make the search efficient
			for (size_t j = 0; j < price.size() && !match; j++) {
				if (desc[i].code == price[j].code) {
					match = true;
					Product* temp = new Product(desc[i].desc, price[j].price);//using Product's overoaded constructor
					temp->validate();
					priceList += temp;//using += to append the list
					delete temp;
					temp = nullptr;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {
			bool match = false;//to make the search efficient
			for (size_t j = 0; j < price.size() && !match; j++) {
				if (desc[i].code == price[j].code) {
					match = true;
					
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					priceList += temp;//using += to append the list
				}
			}
		}


		return priceList;
	}
}