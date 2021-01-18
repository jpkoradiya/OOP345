/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 02/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__

#include <string>

namespace sdds {
	class RecordSet {
		std::string *rs_strArr;
		std::string rs_filename;//to store the filename - added
		size_t rs_noOfStr;

	public:
		void setEmpty();
		RecordSet();
		RecordSet(const std::string&);
		RecordSet(RecordSet&);

		//move constructor
		RecordSet(RecordSet&&);

		//move assignment operator
		RecordSet& operator=(RecordSet&&);
		//copy assignment operator
		RecordSet& operator=(const RecordSet&);

		~RecordSet();
		size_t size();

		std::string getRecord(size_t);
	};
}



#endif // !SDDS_RECORDSET_H__
