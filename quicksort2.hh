#ifndef QUICK2_HH
#define QUICK2_HH

#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>


int inPlacePartition(std::vector<MovieEntry>& movieList,int first, int last)
{
    int l = first;
    int r = last - 1;

    while (l <= r)
    {
        if(movieList[l].score>movieList[r].score)
            std::swap(movieList[l],movieList[r]);
        l++;
        r++;
    }

    return l;
}

void quicksort2(std::vector<MovieEntry>& movieList, int first, int last)
{
    int l;
    if(first<=last)
    {
        //srand(time(NULL));
        int pivot = last-1; //rand() % (last-first) + first;

        std::swap(movieList[pivot],movieList[last]);

        l = inPlacePartition(movieList, first, last);
        quicksort2(movieList, first,l-1);
        quicksort2(movieList,l+1,last);
    }
    
}


#endif