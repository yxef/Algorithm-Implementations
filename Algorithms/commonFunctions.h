#pragma once

#include <vector>

// just a functions that swaps 2 elements of a vector using its indexes
void swapVectorElements(std::vector<int> &vector, int index1, int index2){
    int hold = vector[index1];
    vector[index1] = vector[index2];
    vector[index2] = hold;
    return;
}

template <typename T>
void printVector(std::vector<T> toPrint){
    for(int i = 0; i < toPrint.size(); i++){
        std::cout <<"["<< toPrint[i] << "]";
    }
    std::cout << std::endl;
}

bool checkIfVectorSorted(std::vector<int> vectorToCheck){
    if(vectorToCheck.size() == 0 || vectorToCheck.size() == 1){
        return true;
    }

    for(int i = 1; i < vectorToCheck.size(); i++){
        if(vectorToCheck[i] < vectorToCheck[i-1]){
            return false;
        }
    }
    return true;
}