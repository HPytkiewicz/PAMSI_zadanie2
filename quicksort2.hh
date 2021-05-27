#ifndef QUICK2_HH
#define QUICK2_HH

#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>


int inPlacePartition(std::vector<MovieEntry>& movieList,int first, int last)
{
   int pivot = movieList[first].score;
   int l = first-1;
   int r = last + 1;

   while(1)
   {
       do{
        l++;
       }while (movieList[l].score<pivot);
       do{
        r--;
       }while(movieList[r].score>pivot);
       
       if(l>=r)
        return r;

       std::swap(movieList[l], movieList[r]);
   }

}

void quicksort2(std::vector<MovieEntry>& movieList, int first, int last)
{
    if(first<last)
    {

        int l = inPlacePartition(movieList, first, last);
        quicksort2(movieList, first,l);
        quicksort2(movieList,l+1,last);
    }
    
}


#endif