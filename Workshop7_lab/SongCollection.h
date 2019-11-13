// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Dec 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
namespace sdds {
struct Song{
    std::string s_artist;
    std::string s_title;
    std::string s_album;
    double s_price;
    std::string s_relYears;
    std::string s_length;
};
class SongCollection {
    std::vector<Song> s_Song;
public:
    SongCollection(const char* is);
    void display(std::ostream& out) const;
};
std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif /* SongCollection_hpp */
