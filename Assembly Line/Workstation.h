// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email:jpkoradiya@myseneca.ca
// Date of completion: 25/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <queue>
#include "Station.h"
#include "CustomerOrder.h"

class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;
	Station* m_pNextStation{ nullptr };
public:
	Workstation(const std::string&);

	//copy constructor and operator
	Workstation(Workstation&) = delete;
	Workstation& operator=(Workstation&) = delete;

	//move constructor and operator
	Workstation(Workstation&&) = delete;
	Workstation& operator=(Workstation&&) = delete;

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};

#endif