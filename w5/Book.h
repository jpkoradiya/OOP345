/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 27/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {
	class Book
	{
		std::string b_author{ "" };
		std::string b_title{ "" };
		std::string b_country{ "" };
		size_t b_year{ 0u };
		double b_price{ 0 };
		std::string b_desc{ "" };
		std::string trim(std::string& str);
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(b_desc);
		};

		//std::ostream& operator()(std::string) {
			
		//};
		friend std::ostream& operator<<(std::ostream&, const Book&);
	};
}
#endif //!SDDS_BOOK_H