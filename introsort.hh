#ifndef INTRO_HH
#define INTRO_HH

#include "MovieEntry.hh"
#include "quicksort.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>


void heapify(std::vector<MovieEntry>& movieList, int first, int last, int i)
{
    int x;
    int y = i;

    do{
        x = y;
        if((2*(x-first)) + first <= last && movieList[(2*(x-first)) + first].score > movieList[y].score)
            y = 2*(x-first) + first;
        if((2*(x-first)) + first + 1 <= last && movieList[(2*(x-first)) + first + 1].score > movieList[y].score)
            y = 2*(x-first) + first + 1;
        std::swap(movieList[x], movieList[y]);
    } while(x != y);
}


void heapsort(std::vector<MovieEntry>& movieList, int first, int last)
{
    for(int i = first + (last-first)/2; i >= first; i--)
    {
        heapify(movieList, first, last, i);
    }
    for(int i = last; i > first; i--)
    {
        std::swap(movieList[first], movieList[i]);
        heapify(movieList, first, i-1, first);
    }
}

// Napisana nowa funkcja do dzielenia tablicy, gdyz ta z quicksort sprawiala niewyjasniony 
// problem
int partition(std::vector<MovieEntry>& movieList, int first, int last)
{
    int pivot = first + (last-first)/2;
    int pivotScore = movieList[pivot].score;
    std::swap(movieList[pivot], movieList[last]);

    int x = first;
    for(int i = first; i<last; i++)
    {
        if(movieList[i].score < pivotScore)
        {
            std::swap(movieList[x], movieList[i]);
            x++;
        }
    }
    std::swap(movieList[x], movieList[last]);
    return x;
}

void introsort(std::vector<MovieEntry>& movieList, int first, int last, int depth)
{
    if(last-first+1 > 1)
    {
        if(depth<=0)
            heapsort(movieList, first, last);
        else
        {
            int x = partition(movieList, first, last);
            introsort(movieList, first, x-1, depth-1); 
            introsort(movieList, x+1, last, depth-1); 
        }
    }
}
#endif