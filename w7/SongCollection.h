/*
Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca
Date of completion: 14/11/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <list>

namespace sdds {
	struct Song{
		std::string artist{ "" };
		std::string title{ "" };
		std::string album{ "" };
		double m_price{ 0 };
		int year{ 0 };
		int length{ 0 };
	};

	class SongCollection {
		std::vector<Song> c_collection;
		//private function to help us extract tokens
		std::string trimstr(std::string& str);
		std::string trimnum(std::string& str);
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(std::string artist) const;
		std::list<Song> getSongsForArtist(std::string artist) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif