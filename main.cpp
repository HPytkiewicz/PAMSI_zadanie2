//#include "MovieEntry.hh"

#include "bucketsort.hh"
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
    std::cout << "Sorting." << std::endl;

    //bucketSort(movieList);
    /*
    quickSort(movieList,0,100000);
    quickSort(movieList,100001,200000);
    quickSort(movieList,200001,300000);
    quickSort(movieList,300001,400000);
    quickSort(movieList,400001,500000);
    quickSort(movieList,500001,600000);
    quickSort(movieList,700001,800000);
    quickSort(movieList,800001,900000);
    quickSort(movieList,900001,1000000);
    */
    
    std::vector<MovieEntry> bucket0, bucket1, bucket2, bucket3, bucket4, bucket5;

    for(int i = 500000; i<600000; i++)
    {
        int temp = movieList[i].score;
        switch (temp)
        {
        case 1:
            bucket0.push_back(movieList[temp]);
            break;
        case 2:
            bucket0.push_back(movieList[temp]);
            break;
        case 3:
            bucket1.push_back(movieList[temp]);
            break;
        case 4:
            bucket1.push_back(movieList[temp]);
            break;
        case 5:
            bucket2.push_back(movieList[temp]);
            break;
        case 6:
            bucket2.push_back(movieList[temp]);
            break;
        case 7:
            bucket3.push_back(movieList[temp]);
            break;
        case 8:
            bucket3.push_back(movieList[temp]);
            break;
        case 9:
            bucket4.push_back(movieList[temp]);
            break;
        case 10:
            bucket4.push_back(movieList[temp]);
            break;
        default:
            break;
        }
    }
    
    quickSort(bucket0,0, bucket0.size()-1);
    std::cout << 0 << std::endl;                                  
    //quickSort(bucket1,0, bucket1.size()-1);
    std::cout << 1 << std::endl;                                  
    //quickSort(bucket2,0, bucket2.size()-1);
    std::cout << 2 << std::endl;                                  
    //quickSort(bucket3,0, bucket3.size()-1);
    std::cout << 3 << std::endl;                                  
    //quickSort(bucket4,0, bucket4.size()-1);
    std::cout << 4 << std::endl;                                  

    movieList.clear();
    for(int i = 0; i < bucket0.size(); i++)
        movieList.push_back(bucket0[i]);
        /*
    for(int i = 0; i < bucket1.size(); i++)
        movieList.push_back(bucket1[i]);
    for(int i = 0; i < bucket2.size(); i++)
        movieList.push_back(bucket2[i]);
    for(int i = 0; i < bucket3.size(); i++)
        movieList.push_back(bucket3[i]);
    for(int i = 0; i < bucket4.size(); i++)
        movieList.push_back(bucket4[i]);
        */

    for (int i = 50000; i<movieNumber; i++)
    {
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