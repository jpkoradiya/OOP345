// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email: jpkoradiya@myseneca.ca
// Date of completion: 19/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include "Station.h"

struct Item
{
	std::string m_itemName{ "" };
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name{ "" };
	std::string m_product{ "" };
	unsigned int m_cntItem{ 0u };
	Item** m_lstItem{ nullptr };
	static size_t m_widthField;

public:
	CustomerOrder() {};
	CustomerOrder(std::string& record);
	~CustomerOrder();

	//copy constructor to throw an exception
	CustomerOrder(const CustomerOrder& source);
	//deleting the copy operator
	CustomerOrder operator=(const CustomerOrder& source) = delete;
	//move constructor
	CustomerOrder(CustomerOrder&&) noexcept;
	//move operator
	CustomerOrder& operator=(CustomerOrder&&) noexcept;

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif