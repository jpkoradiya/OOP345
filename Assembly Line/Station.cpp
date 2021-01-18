// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email: jpkoradiya@myseneca.ca
// Date of completion: 14/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>

#include "Station.h"
#include "Utilities.h"

//initializing the static variables
size_t Station::m_widthField{ 1u };
size_t Station::s_idgen{ 0u };

Station::Station(const std::string& str) {
	if (!str.empty()) {
		bool more = true;
		size_t pos = 0;
		Utilities token;
		while (more) {
			s_name = token.extractToken(str, pos, more);
			if (s_name.size() > m_widthField)
				m_widthField = s_name.size();
			m_serialNumber = std::stoi(token.extractToken(str, pos, more));
			s_items = std::stoi(token.extractToken(str, pos, more));
			s_desc = token.extractToken(str, pos, more);
			s_idgen++;
			s_id = s_idgen;
			more = false;
		}
	}
}

const std::string& Station::getItemName() const {
	return s_name;
}
unsigned int Station::getNextSerialNumber() {
	unsigned int temp = m_serialNumber;
	m_serialNumber++;
	return temp;
}
unsigned int Station::getQuantity() const {
	return s_items;
}
void Station::updateQuantity()
{
	if (getQuantity() > 0) {
		s_items--;
	}
}
void Station::display(std::ostream& os, bool full) const
{
	if (!full) {
		os << "[" << std::setw(3) << std::setfill('0') << std::right << s_id << "]" << " Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << s_name << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::endl;
	}
	else {
		os << "[" << std::setw(3) << std::setfill('0') << std::right << s_id << "]" << " Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << s_name << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << " Quantity: " << std::setw(m_widthField) << std::setfill(' ') << std::left << s_items << " Description: " << s_desc << std::endl;
	}
}
