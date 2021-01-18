// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email: jpkoradiya@myseneca.ca
// Date of completion: 14/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H

#include <string>

class Station {
	int s_id{ 0 };
	std::string s_name{ "" };
	std::string s_desc{ "" };
	int m_serialNumber{ 0 };
	int s_items{ 0 };
	static size_t m_widthField;
	static size_t s_idgen;

public:
	Station(const std::string& str);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif