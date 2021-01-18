// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email: jpkoradiya@myseneca.ca
// Date of completion: 19/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>

#include "Utilities.h"

char Utilities::m_delimiter = '\0';//initializing the static variable

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	more = false;
	size_t i = str.find(m_delimiter, next_pos);

	std::string tokenstr{ "" };//temp string to store the extracted token
	if (i != std::string::npos) {
		tokenstr = str.substr(next_pos, i - next_pos);
		next_pos = i + 1;
		more = true;
		if (tokenstr.size() > m_widthField)
			m_widthField = tokenstr.size();
	}
	else {
		i = str.find_last_of(m_delimiter) + 1;
		tokenstr = str.substr(i);
		more = false;
	}

	if (tokenstr.empty())
		more = false;

	return tokenstr;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}
char Utilities::getDelimiter() {
	return m_delimiter;
}