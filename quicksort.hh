#ifndef QUICK_HH
#define QUICK_HH

#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <cmath>

long partition(std::vector<MovieEntry>& movieList, long low, long high)
{
    int pivot = movieList[high].score;

    long i = low -1;

    for(long j = low; j<=high-1; j++)
    {
        if(movieList[j].score<pivot)
        {
            i++;
            MovieEntry temp = movieList[i];
            movieList[i] = movieList[j];
            movieList[j] = temp;
        }
    }
    MovieEntry temp = movieList[i+1];
    movieList[i+1] = movieList[high];
    movieList[high] = temp;

    return (i+1);
}

void quickSort(std::vector<MovieEntry>& movieList, long low, long high)
{
    if(low<high)
    {
        long x = partition(movieList, low, high);
        quickSort(movieList, low, x-1);
        quickSort(movieList, x+1, high);
    }
}

#endif