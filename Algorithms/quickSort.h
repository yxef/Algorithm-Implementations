#pragma once

#include <vector>
#include <math.h>
#include <time.h>


namespace quickS{
// just a functions that swaps 2 elements of a vector using its indexes
void swapVectorElements(std::vector<int> &vector, int index1, int index2){
    int hold = vector[index1];
    vector[index1] = vector[index2];
    vector[index2] = hold;
    return;
}

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