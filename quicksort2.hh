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
    int r = last;
    int pivot = first + (last - first)/2;

    while (l <= r)
    {
        while(movieList[l].score<movieList[pivot].score)
        {
            l++;
        }
        while (movieList[r].score>movieList[pivot].score)
        {
            r--;
        }        
        if(l<=r)
        {
            std::swap(movieList[l],movieList[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quicksort2(std::vector<MovieEntry>& movieList, int first, int last)
{
    if(first<last)
    {
        //srand(time(NULL));
        //int pivot = first + (last - first)/2;

        //std::swap(movieList[pivot],movieList[last]);

        int l = inPlacePartition(movieList, first, last);
        quicksort2(movieList, first,l-1);
        quicksort2(movieList,l,last);
    }
    
}


#endif