#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

bool isBigger(MovieEntry movie1, MovieEntry movie2) {movie1.score > movie2.score;}  // binarna funkcja do sortowania

void bucketSort(std::vector<MovieEntry>& movieList)
{
    
    
    float nBuckets = 5;   // ilosc kubelkow
    float max = 10;   // maksymalna ocena filmu, w naszym przypadku 10
    float min = 1;    // minimalna ocena filmu, w naszym przypadku 0
    float range = static_cast<float>((max-min)/nBuckets);     // przedzial wartosci kubelka
    std::cout << "Range: " << range << std::endl;
    
    std::vector<std::vector<MovieEntry>> buckets;
    std::vector<MovieEntry> bucket0, bucket1, bucket2, bucket3, bucket4, bucket5;
    buckets.push_back(bucket0);
    buckets.push_back(bucket1);
    buckets.push_back(bucket2);
    buckets.push_back(bucket3);
    buckets.push_back(bucket4);
    buckets.push_back(bucket5);
    
    for (int i = 0; i < movieList.size(); i++)      // umieszczanie elementow w poszczegolnych kubelkach
    {
        int whichBucket = (movieList[i].score/range);
        std::cout << "i: " << whichBucket << std::endl;
        buckets[whichBucket].push_back(movieList[i]);
        for(int j = 0; j < buckets[whichBucket].size(); j++)
            std::cout << j << " " << buckets[whichBucket][j].movieName << std::endl;
    }

    /*
    for (int i = 0; i < nBuckets; i++)
    {
        for(int j = 0; j < buckets[i].size(); j++)
        {
            std::cout << buckets[i][j].score << std::endl;
        }
    }
    */
   std::cout << "Buckets size: " << buckets.size() << std::endl;
   for (int i = 0; i < nBuckets; i++)
    std::cout << "Bucket size: " << buckets[0].size() << std::endl;
    for(int i = 0; i < nBuckets; i++)
    {
        for(int j = 0; j<buckets[i].size(); j++)     // sortowanie poszczegolnych kubelkow z pomoca funkcji 
        {
            if(buckets[i][j].score>buckets[i][j+1].score)
            {
                MovieEntry temp;
                temp.movieName = buckets[i][j].movieName;
                temp.score = buckets[i][j].score;
                buckets[i][j] = buckets[i][j+1];
                buckets[i][j+1] = temp;
            }
        }
    }                                                             // sort() i wlasnej funkcji isBigger()

    int x = 0;  // indeks docelowej tablicy
    for (int i = 0; i < nBuckets; i++)
    {
        for(int j = 0; j < buckets[i].size(); j++)
        {
            movieList[x++] = buckets[i][j];
        }
    }
    
}