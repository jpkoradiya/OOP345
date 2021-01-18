/*
Name: Jigarkumar Pritamkumar Koradiya
Seneca Id: 164861189
Seneca email: jpkoradiya@myseneca.ca
Date of completion: 14/11/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(const char* filename){
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			return;
		}
		while (file) {
			std::string temp;//temp string
			std::getline(file,temp,'\n');

			Song s;

			s.title = trimstr(temp);
			s.artist = trimstr(temp);
			s.album = trimstr(temp);

			std::string numcheck;//a string to verify the numbers to avaoid exceptions

			numcheck = trimnum(temp);
			if (numcheck != "") {
				s.year = stoi(numcheck);
			}
			numcheck = trimnum(temp);
			if (numcheck != "") {
				s.length = stoi(numcheck);
			}
			numcheck = trimnum(temp);
			if (numcheck != "") {
				s.m_price = stod(numcheck);
			}

			if (s.title != "") {
				c_collection.push_back(s);
			}
		}
	}
	void SongCollection::display(std::ostream& out) const{
		int length = 0;
		std::for_each(c_collection.begin(), c_collection.end(), [&](const Song& s) {
			out << s << std::endl;
			length += s.length;
		});
		int hours = length / 3600;
		int minutes = (length % 3600) / 60;
		int seconds = (length % 60);
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|";
		out << std::setw(78) << std::right << "Total Listening Time: " << hours << ":" << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds << " |" << std::setfill(' ') << std::endl;
	}
	void SongCollection::sort(const std::string& field){
		if (field == "title") {
			std::sort(c_collection.begin(), c_collection.end(), [](const Song& s1, const Song& s2) {
					return s1.title < s2.title;
				});
		}
		else if (field == "album") {
			std::sort(c_collection.begin(), c_collection.end(), [](const Song& s1, const Song& s2) {
				return s1.album < s2.album;
				});
		}
		else if (field == "length") {
			std::sort(c_collection.begin(), c_collection.end(), [](const Song& s1, const Song& s2) {
				return s1.length < s2.length;
				});
		}
	}
	void SongCollection::cleanAlbum(){
		std::for_each(c_collection.begin(), c_collection.end(), [&](Song& s) {
			//we have none in only 1 field, album
			if (s.album == "[None]")
				s.album = "";
		});
	}
	bool SongCollection::inCollection(std::string artist) const
	{
		bool ret = false;
		std::for_each(c_collection.begin(), c_collection.end(), [&](const Song& s) {
			if (s.artist == artist)
				ret = true;
		});
		return ret;
	}
	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const
	{
		std::list<Song> songlist;
		std::for_each(c_collection.begin(), c_collection.end(), [&](const Song& s) {
			if (s.artist == artist)
				songlist.push_back(s);
			});
		return songlist;
	}
	std::ostream& operator<<(std::ostream& out,const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.title << " | ";
		out << std::setw(15) << std::left << theSong.artist << " | ";
		out << std::setw(20) << std::left << theSong.album << " | ";
		
		//because we have an empty year in the collection
		if (theSong.year == 0) {
			//out << std::setfill(' ') << std::setw(6) << " | "; didn't work!
			out << "      " << " | ";
		}
		else {
			out << std::setw(6) << std::right << theSong.year << " | ";
		}
		out << (theSong.length) / 60 << ":" << std::setw(2) << std::setfill('0') << (theSong.length) % 60 << " | " << std::setfill(' ');
		out << std::fixed << std::setprecision(2) <<theSong.m_price << " |";
		return out;
	}
	std::string SongCollection::trimstr(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string temp;
		temp = str.substr(0, 25);
		temp.erase(0, temp.find_first_not_of(spaces));
		temp.erase(temp.find_last_not_of(spaces) + 1);
		str.erase(0, 25);

		return temp;
	}

	std::string SongCollection::trimnum(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string temp;
		temp = str.substr(0, 5);
		temp.erase(0, temp.find_first_not_of(spaces));
		temp.erase(temp.find_last_not_of(spaces) + 1);
		str.erase(0, 5);

		return temp;
	}
}