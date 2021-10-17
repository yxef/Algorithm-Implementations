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

// prints vector elements between two indexes
template <typename T>
void printArrayWithRange(T vectorToPrint, int vecStart, int vecEnd){
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\nprinting array from ["<<vecStart<<"] to ["<<vecEnd<<"]: \n";
    for(int i = vecStart; i <= vecEnd; i++){
        std::cout << vectorToPrint[i] << "\n" ;
    }
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

bool isInListOfIndexesToIgnore(std::vector<int> listOfIndexesToIgnore, int indexToCheck){
    for(int i = 0; i < listOfIndexesToIgnore.size(); i++){
        if(listOfIndexesToIgnore[i] == indexToCheck)
            return true;
    }

    return false;
}

// debug function, checks if the algorithm deleted a value that was present in the original vector
// works using isInListOfIndexesToIgnore, which ignores indexes, so that we do not check the same
// position twice in case there are two elements of the same value
void whichNumberWasKilled(std::vector<int> startingVector, std::vector<int> differentVector){
    bool isTheNumberInTheDifferentVector = false;       //i know, very explicit name, fuck you
    std::vector<int> listOfIndexesToIgnore;

    for(int i = 0; i < startingVector.size(); i++){
        for(int j = 0; j < differentVector.size(); j++){
            if(startingVector[i] == differentVector[j] && !isInListOfIndexesToIgnore(listOfIndexesToIgnore, j)){
                isTheNumberInTheDifferentVector = true;
                listOfIndexesToIgnore.push_back(j);
                break;
            }
        }
        if(isTheNumberInTheDifferentVector)
            std::cout << "["<<startingVector[i]<<"] is present in the differentVector" << std::endl;
        else{
            std::cout << "["<<startingVector[i]<<"] was eaten by the algorithm" << std::endl;
        }
        isTheNumberInTheDifferentVector = false;
    }
}