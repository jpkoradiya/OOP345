/*Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_H__
#define SDDS_SET_H__

namespace sdds {
	template <typename T, int N>
	class Set {
		T arraySet[N];
		int currentElements;

	public:
		//default constructor
		Set() : arraySet{}, currentElements{ 0 } {};
		size_t size() const {
			return currentElements;
		};
		const T& operator[](size_t idx) const {
			return arraySet[idx];
		};
		void operator+=(const T& item) {
			if (currentElements < N) {
				arraySet[currentElements] = item;
				currentElements++;
			}
		};
	};

}

#endif // !SDDS_SET_H__