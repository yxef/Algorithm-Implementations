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

    std::cout << "---vectorToSort size: "<< vectorToSort.size() << std::endl;
    std::cout << "---countingVector size: "<< countingVector.size() << std::endl;
    std::cout << "---finalVector size: " << finalVector.size() << std::endl;

    // inizializing the counting vector to 0
    for(int i = 0; i < countingVector.size(); i++){
        countingVector[i] = 0;
    }

    std::cout << "\033[31m";
    for(int j= 0; j < vectorToSort.size(); j++){
        std::cout << "j = " << j << ". adding 1 countingVector[vectorToSort[j]] = "<<countingVector[vectorToSort[j]] << " vectorToSort[j] = " << vectorToSort[j]<< std::endl;
        countingVector[vectorToSort[j]] = countingVector[vectorToSort[j]] + 1;
    }
    std::cout << "\033[32m";
    for(int k = 1; k <= maxRangeValue; k++){
        std::cout << "k = " << k << " about to add countingVector[k](" <<countingVector[k]<< ") + countingVector[k-1](" << countingVector[k-1] << ")" << std::endl;
        countingVector[k] = countingVector[k] + countingVector[k-1];
    }
    printVector(countingVector);
    std::cout << "\033[33m";
    for(int i = vectorToSort.size()-1; i >= 0; i--){
        std::cout << "i = " << i <<" about to add to the finalVector: vectorToSort[i] = "<<vectorToSort[i] <<" in position countingVector[vectorToSort[i]] which is equal to = " << countingVector[vectorToSort[i]]<<std::endl;
        finalVector[countingVector[vectorToSort[i]]-1] = vectorToSort[i];
        countingVector[vectorToSort[i]] -= 1;
    }
    std::cout << "\033[0m";

    std::cout << "checking if any number was killed by the algorithm" << std::endl;
    whichNumberWasKilled(vectorToSort, finalVector);

    return finalVector;
}

}