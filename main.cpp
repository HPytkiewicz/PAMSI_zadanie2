//#include "MovieEntry.hh"

#include "bucketsort.hh"
#include "buckersort2.hh"
#include "quicksort.hh"
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

    std::vector<MovieEntry> movieList;

    movieList.clear();

    long movieNumber = 1000000;

    movieList.resize(movieNumber);
    
    MovieEntry tempMovie;
    auto start_pt = std::chrono::high_resolution_clock::now();
    for(int i=0;i<movieNumber;i++)
    {
        getline(fileRanking,x,',');
        getline(fileRanking,x,'\n');
        std::string str1;
        str1 = x.substr(x.rfind(',')+1);
        if(str1.length()<3)
            tempMovie.score = 1.0f;        // w przypadku braku oceny, przyjmuje ocene 1
        else
            tempMovie.score = (std::stof(str1));
        x.erase(x.rfind(','));
        tempMovie.movieName = x;
        movieList[i] = tempMovie;
    }
    auto stop_pt = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_pt - start_pt);

    std::cout << "Duration: " << duration.count() << std::endl;
    std::cout << "Sorting..." << std::endl;

    //bucketSort(movieList);
    auto start_pt2 = std::chrono::high_resolution_clock::now();
    bucketSort2(movieList);
    auto stop_pt2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_pt2 - start_pt2);

    bool isSorted = true;
    std::vector<int> linia;
    for (int i = 0; i<movieList.size(); i++)
    {
        std::cout << "Title: " << movieList[i].movieName << std::endl;
        std::cout << "Score: " << movieList[i].score << std::endl;
        if(i>0)
        {
            if(movieList[i].score<movieList[i-1].score)
            {
                isSorted = false;
                linia.push_back(i);
            }
        }
    }
    std::cout << "Stan posortowania: " << int(isSorted) << std::endl;
    std::cout << "Sorting duration: " << duration2.count() << std::endl;
    for (int i = 0; i < linia.size(); i++)
        std::cout << "Linia " << linia[i] << std::endl;
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