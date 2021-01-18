/*Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__

namespace sdds {
	template<typename K, typename V>
	class Pair {
		K m_key;
		V m_value;

	public:
		Pair() : m_key{}, m_value{} {};
		Pair(const K& k, const V& v) : m_key{ k }, m_value{ v } {};
		const K& key() const {
			return m_key;
		};
		const V& value() const {
			return m_value;
		};
		virtual void display(std::ostream& os) const {
			os << key() << " : " << value() << std::endl;
		};
	
	};
	//helper function
	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	};
	
}

#endif // !SDDS_PAIR_H__