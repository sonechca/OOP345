// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Nov 11, 2019
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
        std::string tmpLength = "";
        tmpLength = line.substr(80,5);
        tmpLength.erase(0,tmpLength.find_first_not_of(" "));
        tmpLength.erase(tmpLength.find_last_not_of(" ") + 1);
        tmp.s_length = stoi(tmpLength);
        
        tmp.m_price = stod(line.substr(85,5));
        s_Song.push_back(tmp);
    }

}

void SongCollection::display(std::ostream& out) const{
    size_t totalTime = 0;
    size_t hour = 0;
    size_t min = 0;
    size_t sec = 0;
    std::string t_min;
    std::string t_sec;
    for_each(s_Song.begin(),s_Song.end(),[&](const Song& str){
        out << str << std::endl;
        totalTime += str.s_length;
    });
    out <<"----------------------------------------------------------------------------------------" << std::endl;
    out << "|                                                        Total Listening Time: ";
    while(totalTime >= 3600){
        hour++;
        totalTime -= 3600;
    }
    min = totalTime/60;
    sec = totalTime%60;
    if(sec < 10){
        t_sec = "0" + std::to_string(sec);
    }
    else {
        t_sec = std::to_string(sec);
    }
    if(min < 10){
        t_min = "0" + std::to_string(min);
    }
    else {
        t_min = std::to_string(min);
    }
    out << std::to_string(hour) << ":" << t_min << ":" << t_sec;
    out << " |" << std::endl;
    

}

std::ostream& operator<<(std::ostream& out, const Song& theSong){
    out << "| " << std::left << std::setw(20) << theSong.s_title
        << " | " <<std::setw(15) << theSong.s_artist
        << " | " << std::setw(20) << theSong.s_album
        << " | " << std::right << std::setw(6) << theSong.s_relYears;
    out << " | " << theSong.s_length/60 << ":";
    if(theSong.s_length%60 < 10){
        out << "0" << theSong.s_length%60;
    }
    else{
        out << theSong.s_length%60;
    }
    
    out << " | " << theSong.m_price << " |";
    
    return out;
}
    
void SongCollection::sort(std::string str){
    if(str[0] == 't'){
        std::sort(s_Song.begin(), s_Song.end(),[](const Song &lhs, const Song &rhs){
            return lhs.s_title < rhs.s_title;
        });
    }
    else if(str[0] == 'a'){
        std::sort(s_Song.begin(), s_Song.end(),[](const Song &lhs, const Song &rhs){
            return lhs.s_album < rhs.s_album;
        });
    }
    else if(str[0] == 'l'){
        std::sort(s_Song.begin(), s_Song.end(),[](const Song &lhs, const Song &rhs){
            return lhs.s_length < rhs.s_length;
        });
    }
    
}
void SongCollection::cleanAlbum() {
    for_each(s_Song.begin(),s_Song.end(),[&](Song& str){
        if(str.s_album == "[None]"){
            str.s_album = "";
        }
    });
}
bool SongCollection::inCollection(std::string str) const {
    bool result = false;
    for_each(s_Song.begin(), s_Song.end(),[&](const Song& song){
        if(song.s_artist == str)
            result = true;
    });
    return result;
}
std::list<Song> SongCollection::getSongsForArtist(std::string str) const{
    std::list<Song> t_song;
    for_each(s_Song.begin(), s_Song.end(), [&](const Song& song){
        if(song.s_artist == str){
            t_song.push_back(song);
        }
    });
    return t_song;
}
}
