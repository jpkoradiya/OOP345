// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email: jpkoradiya@myseneca.ca
// Date of completion: 14/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

class Utilities {
	size_t m_widthField{ 1u };
	static char m_delimiter;
public:
	Utilities() {};
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char newDelimiter);
	static char getDelimiter();
};

#endif