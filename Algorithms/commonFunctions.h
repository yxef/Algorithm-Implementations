#pragma once

#include <vector>

// just a functions that swaps 2 elements of a vector using its indexes
template <typename T>
void swapVectorElements(std::vector<T> &v, int firstIndex, int secondIndex){
    T hold = v[firstIndex];
    v[firstIndex] = v[secondIndex];
    v[secondIndex] = hold;
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