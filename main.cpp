#include "MovieEntry.hh"
#include <fstream>

int main() {
    std::fstream fileRanking;

    fileRanking.open("projekt2_dane.csv", ios::in);

    string x;

    getline(fileRanking, x);

    std::cout << x << std::endl;

    getline(fileRanking,x,',');
    std::cout << x << std::endl;


    getline(fileRanking,x,',');
    std::cout << "Title: " << x << std::endl;
    getline(fileRanking,x,',');
    std::cout << "Score (string for now): " << x << std::endl;

    getline(fileRanking,x,',');
    std::cout << "Title: " << x << std::endl;
    getline(fileRanking,x,',');
    std::cout << "Score (string for now): " << x << std::endl;

    return 0;
}