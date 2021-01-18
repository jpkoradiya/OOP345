/*Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SetSummable_H__
#define SDDS_SetSummable_H__

#include "Set.h"

namespace sdds {
	template <typename T, int N>
	class SetSummable : public Set<T, N> {
	public:

		T accumulate(const std::string& filter) const {
			T temp(filter);

			for (size_t i = 0; i < N; i++) {
				if ((*this)[i].key() == filter) {
					temp += (*this)[i];
				}
			}
			return temp;
		}

	};
}

#endif // !SDDS_SetSummable_H__