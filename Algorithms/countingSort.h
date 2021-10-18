#pragma once

#include <vector>
#include <iostream>

#include "commonFunctions.h"

/*
Counting Sort

This algorithm works by knowing the range of the values of the input array
    for example, if you know your array has elements from 0 to 30, then you can use this algorithm

It works by creating two new arrays, finalArray and countingArray (or vector if you use those)
Then, it counts :)

*/

namespace countingSort{

std::vector<int> countingSort(std::vector<int> vectorToSort, int maxRangeValue){
    std::vector<int> countingVector(maxRangeValue+1);
    std::vector<int> finalVector(vectorToSort.size());

    // inizializing the counting vector to 0
    for(int i = 0; i < countingVector.size(); i++){
        countingVector[i] = 0;
    }

    for(int j= 0; j < vectorToSort.size(); j++){
        countingVector[vectorToSort[j]] = countingVector[vectorToSort[j]] + 1;
    }
    for(int k = 1; k <= maxRangeValue; k++){
        countingVector[k] = countingVector[k] + countingVector[k-1];
    }
    for(int i = vectorToSort.size()-1; i >= 0; i--){
        finalVector[countingVector[vectorToSort[i]]-1] = vectorToSort[i];
        countingVector[vectorToSort[i]] -= 1;
    }

    return finalVector;
}

}