/* Name: Jigarkumar Pritamkumar Koradiya
Email: jpkoradiya@myseneca.ca
Seneca Id: 164861189
Date: 02/10/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__

#include <chrono>
#include <string>

#define MAX_RECORDS 7
namespace sdds {
	class TimedEvents {
		int te_currentRecords;
		std::chrono::system_clock::time_point te_startTime;
		std::chrono::system_clock::time_point te_endTime;
		struct {
			std::string eventName;
			std::string timeUnit; 
			std::chrono::steady_clock::duration duration;
		}te_records[MAX_RECORDS];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(std::string);
		

		friend std::ostream& operator<<(std::ostream&, TimedEvents&);
	};
}

#endif // !SDDS_TIMEDEVENTS_H__

