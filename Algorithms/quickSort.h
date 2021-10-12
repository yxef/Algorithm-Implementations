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
leftIndexWall[ - ]i[ excluded pivots ]j[ - ]rightIndexWall-1[ - ]currentPivot
This particular implementation starts by sampling the right most item as pivot (rightIndexWall)
The procedure uses index j to compare with the pivot, if the pivot is smaller then,
the value in vector[j] is swapped with vector[i]
vector[i]'s index is always <= to j (i<=j) so what it does is push the smaller value
at the start of the vector, so that in the end, you always swap values that are smaller than the pivot.
After the Swap we increment i
When we reach the end of the array we swap the pivot with i. The contents of that vector[i] are bound to be
greater or equal than the pivot, so we swap them.
This way we have on the left side a subarray with value that are all smaller than the Pivot
And on the right side all bigger than the Pivot.
Then we return the position of said Pivot, which is i

Then, back on the quickSort procedure, we call quickSort twice, one with values from 0 to pivot-1
and the other from pivot+1, vector.size()-1 (last index of vector)

We repeat this process until we start passing the same indexes as left and right wall
AKA: we are passing empty arrays, meaning that we are done.
*/

namespace quickS{

//partition function  

int partitionVector(std::vector<int> &vectorToSort, int leftIndexWall, int rightIndexWall){
    int pivot = vectorToSort[rightIndexWall];
    int i = leftIndexWall;
    for(int j = leftIndexWall; j < rightIndexWall; j++){
        if(vectorToSort[j] <= pivot){
            swapVectorElements(vectorToSort, i, j);
            i=i+1;
        }
    }
    swapVectorElements(vectorToSort, i, rightIndexWall);
    return i;
}

void quickSort(std::vector<int> &vectorToSort, int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int middleIndex = partitionVector(vectorToSort, leftIndex, rightIndex);
        quickSort(vectorToSort, leftIndex, middleIndex-1);
        quickSort(vectorToSort, middleIndex+1, rightIndex);
    }
    return;
}

// overload made only to make it more intuitive to call the funcion from the outside
void quickSort(std::vector<int> &vectorToSort){
    quickSort(vectorToSort, 0, vectorToSort.size()-1);
}
}