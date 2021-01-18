// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email:jpkoradiya@myseneca.ca
// Date of completion: 25/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Workstation.h"

Workstation::Workstation(const std::string& str) : Station(str) {}

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder() {
	bool ret = false;

	if (!m_orders.empty()) {
		if (m_pNextStation && m_orders.front().isItemFilled(this->getItemName())) {
			*(Workstation*)m_pNextStation += std::move(m_orders.front());
			m_orders.pop_front();
			ret = true;
		}
	}
	return ret;
}

void Workstation::setNextStation(Station& station) {
	if (station.getQuantity() > 0) {
		m_pNextStation = &station;
	}
}

const Workstation* Workstation::getNextStation() const {
	return (Workstation*)m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool ret = false;
	if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
		order = std::move(m_orders.front());
		m_orders.pop_front();
		ret = true;
	}
	return ret;
}

void Workstation::display(std::ostream& os) const {
	os << getItemName() << " --> " << (m_pNextStation ? m_pNextStation->getItemName() : "END OF LINE") << std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& obj) {
	m_orders.push_back(std::move(obj));
	return *this;
}