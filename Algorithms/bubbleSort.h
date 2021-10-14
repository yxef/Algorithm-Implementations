#include <iostream>
#include <vector>
#include "commonFunctions.h"

namespace bubbleSort{
std::vector<int> bubbleSort(std::vector<int> vectorToSort){
    int vecLength = vectorToSort.size()-1;
    int hold;
    for(int i=0; i < vecLength-1; i++){
        for(int j=vecLength; j>i; j--){
            if(vectorToSort[j] < vectorToSort[j-1]){
                hold = vectorToSort[j];
                vectorToSort[j] = vectorToSort[j-1];
                vectorToSort[j-1] = hold;
            }
        }
    }
    return vectorToSort;
}
}