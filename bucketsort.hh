#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

bool isBigger(MovieEntry movie1, MovieEntry movie2) {movie1.score < movie2.score;}  // binarna funkcja do sortowania

void bucketSort(std::vector<std::shared_ptr<MovieEntry>> movieList)
{
    int nBuckets = 5;   // ilosc kubelkow
    int max = 10;   // maksymalna ocena filmu, w naszym przypadku 10
    int min = 1;    // minimalna ocena filmu, w naszym przypadku 0
    float range = (max-min)/nBuckets;     // przedzial wartosci kubelka

    std::vector<MovieEntry> buckets[nBuckets];
    for (int i = 0; i < movieList.size(); i++)      // umieszczanie elementow w poszczegolnych kubelkach
    {
        int whichBucket = (movieList[i]->score/range);
        buckets[whichBucket]->push_back(movieList[i]);
    }

    for (int i = 0; i < nBuckets; i++)
    {
        for(int j = 0; j < buckets[i].size(); j++)
        {
            std::cout << buckets[i][j].score << std::endl;
        }
    }

    for(int i = 0; i < nBuckets; i++)
    {
        sort(buckets[i].begin(), buckets[i].end(), isBigger);     // sortowanie poszczegolnych kubelkow z pomoca funkcji 
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