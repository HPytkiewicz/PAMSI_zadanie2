#ifndef MERGE_HH
#define MERGE_HH

#include "MovieEntry.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

void merge(std::vector<MovieEntry>& movieList, int  l, int m, int r)
{
    int sizeLeft = m-l+1;
    int sizeRight = r-m;

    std::vector<MovieEntry> leftVector, rightVector;

    for(int i = 0; i < sizeLeft; i++)
    {
        leftVector.push_back(movieList[l+i]);
    }
    for(int i = 0; i<sizeRight; i++)
    {
        rightVector.push_back(movieList[m+i+1]);
    }

    int leftIterator = 0;
    int rightIterator = 0;
    int movieListIterator = l;

    while(leftIterator < sizeLeft && rightIterator < sizeRight)
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

    while(leftIterator < sizeLeft)
    {
        movieList[movieListIterator] = leftVector[leftIterator];
        leftIterator++;
        movieListIterator++;
    }

    while(rightIterator < sizeRight)
    {
        movieList[movieListIterator] = rightVector[rightIterator];
        rightIterator++;
        movieListIterator++;
    }
}

void mergesort(std::vector<MovieEntry> movieList, int l, int r)
{
    int medium = l + (r-l)/2;
    mergesort(movieList, l, medium);
    mergesort(movieList, medium+1, r);
    merge(movieList, l, medium, r);
}

#endif