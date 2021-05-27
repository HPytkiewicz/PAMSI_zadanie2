//#include "MovieEntry.hh"

#include "bucketsort.hh"
#include "mergesort.hh"
#include "quicksort.hh"
#include "introsort.hh"
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <chrono>
#include <list>


void displayList(std::vector<MovieEntry> movieList)
{
    for (int i = 0; i<movieList.size(); i++)
    {
        std::cout << "Title: " << movieList[i].movieName << std::endl;
        std::cout << "Score: " << movieList[i].score << std::endl;
    }
}

bool isInOrder(std::vector<MovieEntry> movieList)
{
    bool isSorted = true;
    for (int i = 0; i < movieList.size() - 1; i++)
    {
        if(i>0)
        {
            if(movieList[i].score<movieList[i-1].score)
            {
                isSorted = false;
            }
        }
    }
    return isSorted;
}

void displayMenu()
{
    std::cout << "Available options: " << std::endl;
    std::cout << "1. bucketsort" << std::endl;
    std::cout << "2. quicksort" << std::endl;
    std::cout << "3. mergesort" << std::endl;
    std::cout << "4. introsort" << std::endl;
    std::cout << "5. display current Movie List" << std::endl;
    std::cout << "6. quit" << std::endl;
}


int main() {
    std::fstream fileRanking;

    fileRanking.open("projekt2_dane.csv", std::ios::in);

    std::string x;

    getline(fileRanking, x, '\n');

    std::vector<MovieEntry> movieList;

    long movieNumber = 10000;

    movieList.resize(movieNumber);
    
    MovieEntry tempMovie;   // stworzenie pomocniczej zmienniej do dodawania filmow do wektora
     
    auto start_pt = std::chrono::high_resolution_clock::now();  // mierzenie czasu wczytania danych
    
    // wczytywanie danych do wektora 
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
        movieList.push_back(tempMovie);
    }
    auto stop_pt = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_pt - start_pt);

    std::cout << "Elements inserting duration: " << duration.count() << std::endl;

    bool quit = false;

    while(!quit)
    {
        int answer;
        displayMenu();
        std::cin >> answer;
        switch(answer)
        {
            case 1:
            {
            auto start_ptb = std::chrono::high_resolution_clock::now(); // mierzenie czasu sortowania
            bucketsort(movieList);
            auto stop_ptb = std::chrono::high_resolution_clock::now();
            auto durationb = std::chrono::duration_cast<std::chrono::microseconds>(stop_ptb - start_ptb);
            std::cout << "Sorting duration: " << durationb.count() << std::endl;
            break;
            }
            case 2:
            {
            auto start_ptq = std::chrono::high_resolution_clock::now(); // mierzenie czasu sortowania
            quicksort(movieList,0,movieList.size()-1);
            auto stop_ptq = std::chrono::high_resolution_clock::now();
            auto durationq = std::chrono::duration_cast<std::chrono::microseconds>(stop_ptq - start_ptq);
            std::cout << "Sorting duration: " << durationq.count() << std::endl;
            break;
            }
            case 3:
            {
            auto start_ptm = std::chrono::high_resolution_clock::now(); // mierzenie czasu sortowania
            mergesort(movieList,0,movieList.size()-1);
            auto stop_ptm = std::chrono::high_resolution_clock::now();
            auto durationm = std::chrono::duration_cast<std::chrono::microseconds>(stop_ptm - start_ptm);
            std::cout << "Sorting duration: " << durationm.count() << std::endl;
            break;
            }
            case 4:
            {
            auto start_pti = std::chrono::high_resolution_clock::now(); // mierzenie czasu sortowania
            int depth = (int)floor(2*log(movieList.size())/M_LN2);
            introsort(movieList, 0, movieList.size()-1, depth);
            auto stop_pti = std::chrono::high_resolution_clock::now();
            auto durationi = std::chrono::duration_cast<std::chrono::microseconds>(stop_pti - start_pti);
            std::cout << "Sorting duration: " << durationi.count() << std::endl;
            break;
            }
            case 5:
            {
            displayList(movieList);
            std::cout << "Number of elements: " << movieNumber << std::endl;
            std::cout << "Is list sorted? " << isInOrder(movieList) << " (1 means it is in order, 0 otherwise)" << std::endl;
            break;
            }
            case 6:
            {
            quit = true;
            break;
            }
            default:
            {
            std::cout << "Invalid command" << std::endl;
            break;
            }
        }
    }

    return 0;
}