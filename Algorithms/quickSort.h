#pragma once

#include <vector>
#include <math.h>
#include <time.h>
#include "commonFunctions.h"

/*
QuickSort
    Worst Case: n^2
    Average Case: n log n

Quick sort is defined by being in practical terms really fast and ON PLACE
Quick sort uses a Divide and Conquer approach
They key to this algorithm is the "partition" procedure which subdivides the array into 4 regions (can be empty)
leftIndexWall[ - ]i[ - ]j[ - ]rightIndexWall
This particular implementation starts by sampling the right most item as pivot (rightIndexWall)


*/

namespace quickS{

/* partition function
#   input: array
#     
*/
int partitionVector(std::vector<int> &vectorToSort, int leftIndexWall, int rightIndexWall){
    int pivot = vectorToSort[rightIndexWall];
    int i = leftIndexWall-1;
    int hold;
    for(int j = leftIndexWall; j < rightIndexWall; j++){
        if(vectorToSort[j] <= pivot){
            i=i+1;
            swapVectorElements(vectorToSort, i, j);
        }
    }
    swapVectorElements(vectorToSort, i+1, rightIndexWall);
    return i+1;
}

void quickSort(std::vector<int> &vectorToSort, int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int middleIndex = partitionVector(vectorToSort, leftIndex, rightIndex);
        quickSort(vectorToSort, leftIndex, middleIndex-1);
        quickSort(vectorToSort, middleIndex, rightIndex);
    }
    return;
}

// overload made only to make it more intuitive to call the funcion from the outside
void quickSort(std::vector<int> &vectorToSort){
    quickSort(vectorToSort, 0, vectorToSort.size()-1);
}
}