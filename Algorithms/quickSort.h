#pragma once

#include <vector>
#include <math.h>
#include <time.h>

void swapVectorElements(std::vector<int> &vector, int index1, int index2){
    int hold = vector[index1];
    vector[index1] = vector[index2];
    vector[index2] = hold;
    return;
}

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

void quickSort(std::vector<int> &vectorToSort){
    quickSort(vectorToSort, 0, vectorToSort.size()-1);
}
/*

void printVectorInQS(std::vector<int> vectorToPrint){
    std::cout << "CUM CUM CUM CUM CUM CUM " << std::endl;
    for(int i = 0; i<vectorToPrint.size(); i++){
        std::cout << "[" << vectorToPrint[i] << "]";
    }
    std::cout << std::endl;
}

int main(){
    srand(time(NULL));
    std::vector<int> vectorToSort;
    for(int i = 10; i >= 0; i--){
        vectorToSort.push_back(rand() % 1000 + 1);
    }
    std::cout << "vector before sorting" << std::endl;
    printVector(vectorToSort);
    std::cout << "quickSort Activated" << std::endl;
    quickSort(vectorToSort, 0, vectorToSort.size()-1);
    std::cout << "vector after sorting" << std::endl;
    printVector(vectorToSort);

}
*/