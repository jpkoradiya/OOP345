// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email: jpkoradiya@myseneca.ca
// Date of completion: 19/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <vector>
#include <iostream>
#include <iomanip>

#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField{ 0u };

CustomerOrder::CustomerOrder(std::string& record) {
	if (!record.empty()) {
		bool more = true;
		size_t pos = 0;
		Utilities token;
		std::vector<std::string> it;//to store items
		m_name = token.extractToken(record, pos, more);

		if (more) {
			m_product = token.extractToken(record, pos, more);
		}
		while (more) {
			it.push_back(token.extractToken(record, pos, more));
		}

		m_lstItem = new Item * [it.size()];
		for (size_t i = 0; i < it.size(); i++) {
			m_lstItem[i] = new Item(it[i]);
		}

		m_cntItem = it.size();

		more = false;
		if (token.getFieldWidth() > this->m_widthField) {
			m_widthField = token.getFieldWidth();
		}
	}
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}

	delete[] m_lstItem;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const CustomerOrder& source) {
	throw std::string("Exception from copy constructor!");
}

CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
	m_lstItem = nullptr;
	*this = std::move(order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
	if (this != &order) {
		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}

			delete[] m_lstItem;
			m_lstItem = nullptr;
		}

		m_name = order.m_name;
		m_product = order.m_product;
		m_cntItem = order.m_cntItem;
		m_lstItem = order.m_lstItem;

		order.m_cntItem = 0;
		order.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::isOrderFilled() const {
	bool ret = true;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_isFilled)
			ret = false;
	}
	return ret;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool ret = true;

	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			ret = m_lstItem[i]->m_isFilled;
		}
	}
	return ret;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (station.getItemName() == m_lstItem[i]->m_itemName) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();

				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;

				os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
			}
			else {
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::left << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_isFilled)
			os << "FILLED" << std::endl;
		else {
			os << "MISSING" << std::endl;
		}
	}
}
