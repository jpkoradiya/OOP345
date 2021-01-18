/*Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PairSummable_H__
#define SDDS_PairSummable_H__
#include <string>
#include <iostream>

#include "Pair.h"

namespace sdds {

		template<typename K, typename V>
		class PairSummable : public Pair<K, V> {
			
			static V initial;
			static size_t fieldWidth;
			
		public:
			PairSummable() {
				//initial = "";
				fieldWidth = 0;
			}
			PairSummable(const K& k, const V& v = initial) : Pair<K, V>(k, v) {
				if (k.size() > fieldWidth)
					fieldWidth = k.size();
			}

			PairSummable& operator+=(const PairSummable& p1) {
				if (this != &p1 && this->key()==p1.key()) {
					PairSummable p(this->key(), this->value() + p1.value());
					*this = p;
				}
				return *this;
			}
			void display(std::ostream& os) const {
				os.setf(std::ios::left);
				os.width(fieldWidth);
				Pair<K, V>::display(os);
				os.unsetf(std::ios::left);
			};
		};

		template <typename K,typename V>
		size_t PairSummable<K, V>::fieldWidth = 0;


		template<>
		int PairSummable<std::string, int>::initial = 0;


		template<>
		std::string PairSummable<std::string, std::string>::initial = "";

		template<>
		PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable < std::string, std::string>&  p1) {
			if (this != &p1 && Pair<std::string, std::string>::key() == p1.key()) {
				*this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string>::value() == "" ? p1.value() : Pair<std::string, std::string>::value() + ", " + p1.value());
			}
			return *this;
		};
	

}
#endif // !SDDS_PairSummable_H__