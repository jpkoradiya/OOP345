/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 02/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include<iostream>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents(){
		te_currentRecords = 0;
		for (int i = 0; i < MAX_RECORDS; i++) {
			te_records[i].eventName = "";
			te_records[i].timeUnit = "";
		}
	}

	void TimedEvents::startClock(){
		te_startTime = std::chrono::system_clock::now();
	}

	void TimedEvents::stopClock(){
		te_endTime = std::chrono::system_clock::now();
	}

	void TimedEvents::recordEvent(std::string eventName){
		int index = -1;
		for (int i = 0; i < MAX_RECORDS; i++) {
			if (te_records[i].eventName == "") {
				index = i;
				break;
			}
		}
		if (index != -1) {
			te_records[index].eventName = eventName;
			te_records[index].timeUnit = "nanoseconds";
			te_records[index].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(te_endTime - te_startTime);
		}
	}

	std::ostream& operator<<(std::ostream& os, TimedEvents& obj) {
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl << "--------------------------" << std::endl;

		for (int i=0; i < MAX_RECORDS; i++) {
			os << std::setw(20) << std::left << obj.te_records[i].eventName;
			os << std::setw(12) << std::right << obj.te_records[i].duration.count() << " " << obj.te_records[i].timeUnit << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
