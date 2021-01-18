/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 27/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {
	template<typename T>
	class Collection{
		std::string c_name{ "" };
		T* c_arr{ nullptr };
		size_t c_size{ 0u };
		//pointer to function
		void (*observer)(const Collection<T>&, const T&) {
			nullptr
		};

	public:
		Collection(std::string name) {
			c_name = name;
		}
		Collection(const Collection& source) = delete;
		Collection& operator=(const Collection& source) = delete;
		~Collection() {
			delete[] c_arr;
			c_arr = nullptr;
		};
		const std::string& name() const {
			return c_name;
		};
		size_t size() const {
			return c_size;
		};
		void setObserver(void (*observer)(const Collection<T>&, const T& item)) {
			this->observer = observer;
		};
		Collection<T>& operator+=(const T& item) {
			bool flag = false;
			for (size_t i = 0u; i < c_size; i++) {
				if (item.title() == c_arr[i].title())
					flag = true;
			}
			if (!flag) {
				T* temp = new T[c_size + 1];
				for (size_t i = 0u; i < c_size; i++) {
					temp[i] = c_arr[i];
				}
				temp[c_size] = item;
				c_size++;

				delete[] c_arr;
				c_arr = nullptr;

				c_arr = new T[c_size];
				for (size_t i = 0u; i < c_size; i++) {
					c_arr[i] = temp[i];
				}
				delete[] temp;
				temp = nullptr;

				if (observer != nullptr)
					observer((*this), item);
			}
			return *this;
		};
		T& operator[](size_t idx) const {
			std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
			if (idx >= size()) 
				throw std::out_of_range(err);
				
			else {
				return c_arr[idx];
			}
		};

		T* operator[](std::string title) const {
			bool found = false;
			T* ret = nullptr;
			for (size_t i = 0u; i < c_size && !found; i++) {
				if (title == c_arr[i].title()) {
					ret = &c_arr[i];
					found = true;
				}
			}
			return ret;
		};

		friend std::ostream& operator<<(std::ostream& os, const Collection& obj) {
			for (size_t i = 0u; i < obj.size(); i++) {
				os << obj[i];
			}
			return os;
		}
	};
}

#endif //!SDDS_COLLECTION_H