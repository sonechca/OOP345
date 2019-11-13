// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Dec 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"
namespace sdds {

SongCollection::SongCollection(const char* is){
    std::ifstream file(is);
    
    if(!file){
        throw "Invalid file";
    }
    while(!file.eof()){

        std::string line;
        getline(file, line, '\n');
        struct Song tmp;
        tmp.s_title = line.substr(0,25);
        tmp.s_title.erase(0,tmp.s_title.find_first_not_of(" "));
        tmp.s_title.erase(tmp.s_title.find_last_not_of(" ") + 1);
        
        tmp.s_artist = line.substr(25,25);
        tmp.s_artist.erase(0,tmp.s_artist.find_first_not_of(" "));
        tmp.s_artist.erase(tmp.s_artist.find_last_not_of(" ") + 1);
        
        tmp.s_album = line.substr(50,25);
        tmp.s_album.erase(0,tmp.s_album.find_first_not_of(" "));
        tmp.s_album.erase(tmp.s_album.find_last_not_of(" ") + 1);
        
        tmp.s_relYears = line.substr(75,5);
        tmp.s_relYears.erase(0,tmp.s_relYears.find_first_not_of(" "));
        tmp.s_relYears.erase(tmp.s_relYears.find_last_not_of(" ") + 1);
        
        tmp.s_length = line.substr(80,5);
        tmp.s_length.erase(0,tmp.s_length.find_first_not_of(" "));
        tmp.s_length.erase(tmp.s_length.find_last_not_of(" ") + 1);
        size_t tmpLength = stod(tmp.s_length);
        size_t min = tmpLength/60;
        size_t sec = tmpLength%60;
        std::string t_sec = "";
        if(sec < 10){
            t_sec = "0" + std::to_string(sec);
        }
        else {
            t_sec = std::to_string(sec);
        }
        tmp.s_length = std::to_string(min) + ":" + t_sec;
        
        tmp.s_price = stod(line.substr(85,5));
        s_Song.push_back(tmp);
    }

}

void SongCollection::display(std::ostream& out) const{
    for_each(s_Song.begin(),s_Song.end(),[&](const Song& str){
        out << str << std::endl;
    });
}

std::ostream& operator<<(std::ostream& out, const Song& theSong){
    out << "| " << std::left << std::setw(20) << theSong.s_title << " | " <<std::setw(15) << theSong.s_artist << " | " << std::setw(20) << theSong.s_album << " | " << std::right << std::setw(6) << theSong.s_relYears << " | " << theSong.s_length << " | " << theSong.s_price << " |";
    return out;
}
}


