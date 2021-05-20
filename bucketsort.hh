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
    for(int i = 0; i < nBuckets; i++)
    {
        quickSort(buckets[i],0, buckets[i].size()-1);
        std::cout << i << std::endl;
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

#endif