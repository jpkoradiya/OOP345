// Name: Jigarkumar Pritamkumar Koradiya
// Seneca Student ID: 164861189
// Seneca email:jpkoradiya@myseneca.ca
// Date of completion: 25/11/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <iostream>

#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& workaddress, std::vector<CustomerOrder>& custorder) {
	std::fstream file(filename);

	if (!file)
		throw std::string("Unable to open [") + filename + "] file.";

	std::string record;
	while (!file.eof())
	{
		bool more = true;
		size_t pos = 0;
		Utilities token;
		token.setDelimiter('|');

		std::getline(file, record);

		std::string station = "";
		station = token.extractToken(record, pos, more);

		std::string nextstation = "";
		if (more)
			nextstation = token.extractToken(record, pos, more);

		for (size_t i = 0; i < workaddress.size(); i++) {
			if (station == workaddress[i]->getItemName()) {
				for (size_t j = 0; j < workaddress.size(); j++) {
					if (workaddress[j]->getItemName() == nextstation)
						workaddress[i]->setNextStation(*workaddress[j]);
				}
			}
		}
	}

	for (size_t i = 0; i < custorder.size(); i++)
		ToBeFilled.push_back(std::move(custorder[i]));

	AssemblyLine = workaddress;
	m_cntCustomerOrder = custorder.size();
}

bool LineManager::run(std::ostream& os) {
	bool filled = false;
	static size_t count = 1;//static count so that it is initialized only once
	os << "Line Manager Iteration: " << count << std::endl;
	count++;

	//arranging the workstation in order
	Workstation* ptr = nullptr;
	std::deque<Workstation*> stations;

	while (stations.size() != AssemblyLine.size()) {
		for (auto i : AssemblyLine) {
			if (i->getNextStation() == ptr) {
				stations.push_front(i);
				ptr = i;
			}
		}
	}

	if (!ToBeFilled.empty()) {
		*stations.front() += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (auto i : AssemblyLine) {
		i->runProcess(os);
	}

	for (auto i : AssemblyLine) {
		i->moveOrder();
	}

	CustomerOrder temp;
	for (auto i : AssemblyLine) {
		if (i->getIfCompleted(temp))
			Completed.push_back(std::move(temp));
	}

	if (Completed.size() == m_cntCustomerOrder)
		filled = true;
	return filled;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++)
		Completed[i].display(os);
}

void LineManager::displayStations() const {
	for (auto i : AssemblyLine)
		i->display(std::cout);
}

void LineManager::displayStationsSorted() const {
	Workstation* ptr = nullptr;
	std::deque<Workstation*> stations;

	while (stations.size() != AssemblyLine.size()) {
		for (auto i : AssemblyLine) {
			if (i->getNextStation() == ptr) {
				stations.push_front(i);
				ptr = i;
			}
		}
	}

	for (auto i : stations)
		i->display(std::cout);
}

