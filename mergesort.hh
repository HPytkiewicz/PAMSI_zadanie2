#ifndef MERGE_HH
#define MERGE_HH

#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

void merge(std::vector<MovieEntry>& movieList, int  l, int m, int r)
{
    
    std::vector<MovieEntry> leftVector;
    std::vector<MovieEntry> rightVector;

    for(int i = l; i < m+1; i++)
    {
        leftVector.push_back(movieList[i]);
    }
    for(int i = m+1; i < r+1; i++)
    {
        rightVector.push_back(movieList[i]);
    }
    //std::cout << "Vector 1 size: " << leftVector.size() << std::endl;
    int leftIterator = 0;
    int rightIterator = 0;
    int movieListIterator = l;

    while(leftIterator < leftVector.size() && rightIterator < rightVector.size())
    {
        if(leftVector[leftIterator].score <= rightVector[rightIterator].score)
        {
            movieList[movieListIterator] = leftVector[leftIterator];
            leftIterator++;
        }
        else
        {
            movieList[movieListIterator] = rightVector[rightIterator];
            rightIterator++;
        }

        movieListIterator++;
    }

    while(leftIterator < leftVector.size())
    {
        movieList[movieListIterator] = leftVector[leftIterator];
        leftIterator++;
        movieListIterator++;
    }

    while(rightIterator < rightVector.size())
    {
        movieList[movieListIterator] = rightVector[rightIterator];
        rightIterator++;
        movieListIterator++;
    }
}


void mergesort(std::vector<MovieEntry>& movieList, int l, int r)
{
    if(l<r){
        int medium = (l+r)/2;
        mergesort(movieList, l, medium);
        mergesort(movieList, medium+1, r);
        merge(movieList, l, medium, r);
    }
}

#endif