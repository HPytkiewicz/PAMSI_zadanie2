#include "linkedList.hh"
#include <fstream>


int main() {
    std::fstream fileRanking;

    fileRanking.open("projekt2_dane.csv", ios::in);

    string x;

    getline(fileRanking, x);

    
    MovieEntry *film1 = new MovieEntry();
    for(int i=0;i<16;i++)
    {
    getline(fileRanking,x,',');
    getline(fileRanking,x,',');
    film1->setName(x);
    getline(fileRanking,x,'\n');
    film1->setScore(std::stof(x));
    film1->display();
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