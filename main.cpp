#include "bucketsort.hh"
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    std::fstream fileRanking;

    fileRanking.open("projekt2_dane.csv", std::ios::in);

    std::string x;

    getline(fileRanking, x, '\n');

    std::vector<std::shared_ptr<MovieEntry>> movieList;

    movieList.clear();
    
    std::shared_ptr<MovieEntry> tempMovie;
    auto start_pt = std::chrono::high_resolution_clock::now();
    for(int i=0;i<100;i++)
    {
        getline(fileRanking,x,',');
        getline(fileRanking,x,'\n');
        std::string str1;
        str1 = x.substr(x.rfind(',')+1);
        if(str1.length()<3)
            tempMovie->score = 1.0f;        // w przypadku braku oceny, przyjmuje ocene 1
        else
            tempMovie->score = (std::stof(str1));
        x.erase(x.rfind(','));
        tempMovie->movieName = x;
        movieList.push_back(tempMovie);
        std::cout << "Title: " << movieList[i]->movieName << std::endl;
        std::cout << "Score: " << movieList[i]->score << std::endl;
    }
    auto stop_pt = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_pt - start_pt);

    std::cout << "Duration: " << duration.count() << std::endl;

    bucketSort(movieList);

    for(int i = 0; i < movieList.size(); i++)
    {
        std::cout << "Title: " << movieList[i]->movieName << std::endl;
        std::cout << "Score: " << movieList[i]->score << std::endl;
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