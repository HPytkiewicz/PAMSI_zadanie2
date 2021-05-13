#include "MovieEntry.hh"
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>


int main() {
    std::fstream fileRanking;

    fileRanking.open("projekt2_dane.csv", std::ios::in);

    std::string x;

    getline(fileRanking, x, '\n');

    std::vector<MovieEntry> movieList;

    movieList.clear();
    
    MovieEntry film1;
    for(int i=0;i<15;i++)
    {
    getline(fileRanking,x,',');
    getline(fileRanking,x,'\n');
    std::string str1;
    str1 = x.substr(x.rfind(',')+1);
    film1.score = (std::stof(str1));
    x.erase(x.rfind(','));
    film1.movieName = x;
    movieList.push_back(film1);
    std::cout << "Title: " << movieList[i].movieName << std::endl;
    std::cout << "Score: " << movieList[i].score << std::endl;
    }

/*
    MovieEntry *film2 = new MovieEntry();
    getline(fileRanking,x,',');
    getline(fileRanking,x,',');
    film2->setName(x);
    getline(fileRanking,x,'\n');
    film2->setScore(std::stod(x));
    film2->display();

    getline(fileRanking,x,',');
    getline(fileRanking,x,',');
    std::cout << "Title: " << x << std::endl;
    getline(fileRanking,x,'\n');
    std::cout << "Score (string for now): " << x << std::endl;
*/

    return 0;
}