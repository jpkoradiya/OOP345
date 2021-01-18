#include <iostream>
#include <iomanip>
#include "event.h"

int g_sysClock = 0;
namespace sdds {

	void Event::setEmpty() {
		e_desc = nullptr;
		e_time = 0;
	}

	Event& Event::operator=(const Event& copy){
		e_time = copy.e_time;
		if (copy.e_desc != nullptr) {
			delete[] e_desc;
			int len = strlen(copy.e_desc);
			e_desc = new char[len + 1];
			std::strncpy(e_desc,copy.e_desc,len+1);
		}
		else {
			this->setEmpty();
		}
		return *this;
	}
	
	Event::Event() {
		setEmpty();
	}

	Event::Event(const Event& copy) {
		*this = copy;//using the operator overload 
	}
	void Event::display() {
		int hrs = 0, min = 0, sec = 0;
		hrs = e_time / 3600;
		min = (e_time % 3600)/60;
		sec = (e_time % 3600) % 60;

		static int count = 1;
		if (e_desc[0]!='\0') {
			std::cout << count << ". ";
			std::cout << std::setfill('0') << std::setw(2) << hrs << ":";
			std::cout << std::setfill('0') << std::setw(2) << min << ":";
			std::cout << std::setfill('0') << std::setw(2) << sec << " -> ";
			std::cout << e_desc << std::endl;
		}
		else {
			std::cout << count << ". [ No Event ]"<< std::endl;
		}
		count++;
	}

	void Event::setDescription(char* desc) {
		if (desc != nullptr && desc[0] != '\0') {
			delete e_desc;
			e_desc = nullptr;
			e_desc = new char[strlen(desc)+1];
			strncpy(e_desc,desc, strlen(desc)+1);
			e_time = g_sysClock;
		}
		else {
			e_desc[0] = '\0';
		}
	}
}