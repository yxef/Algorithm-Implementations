#include <iostream>
#include <vector>       // std::vector
#include "commonFunctions.h"

namespace selSort{
std::vector<int> selSort(std::vector<int> vectorToSort){
    int vecLength = vectorToSort.size()-1;
    int smallV, hold;
    for(int j=0; j < vecLength; j++){
        smallV = j;
        for(int i=j+1; i<=vecLength; i++){
            if(vectorToSort[i] < vectorToSort[smallV])
                smallV = i;
        }
        hold = vectorToSort[j];
        vectorToSort[j] = vectorToSort[smallV];
        vectorToSort[smallV] = hold;
    }

    return vectorToSort;
}
}