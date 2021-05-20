#ifndef BUCKET_HH
#define BUCKET_HH

#include "MovieEntry.hh"
#include "quicksort.hh"
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

void bucketSort(std::vector<MovieEntry>& movieList)
{
    float nBuckets = 6;   // ilosc kubelkow
    float max = 10;   // maksymalna ocena filmu, w naszym przypadku 10
    float min = 1;    // minimalna ocena filmu, w naszym przypadku 0
    //float range = static_cast<float>((max-min)/nBuckets);     // przedzial wartosci kubelka
    float range = 1.8;
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
        int whichBucket = (movieList[i].score-1)/range;
        buckets[whichBucket].push_back(movieList[i]);
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
   for (int i = 0; i < 6; i++)
    std::cout << "Bucket size: " << buckets[i].size() << std::endl;
    quickSort(buckets[0],0, buckets[0].size()-1);
    std::cout << 0 << std::endl;                                  
    quickSort(buckets[1],0, buckets[1].size()-1);
    std::cout << 1 << std::endl;                                  
    quickSort(buckets[2],0, buckets[2].size()-1);
    std::cout << 2 << std::endl;                                  
    quickSort(buckets[3],0, buckets[3].size()-1);
    std::cout << 3 << std::endl;                                  
    quickSort(buckets[4],0, buckets[4].size()-1);
    std::cout << 4 << std::endl;                                  
    quickSort(buckets[5],0, buckets[5].size()-1);
    std::cout << 5 << std::endl;                                  

    long x = 0;  // indeks docelowej tablicy
    for (int i = 0; i < nBuckets; i++)
    {
        for(int j = 0; j < buckets[i].size(); j++)
        {
            movieList[x++] = buckets[i][j];
        }
    }
    
}

#endif