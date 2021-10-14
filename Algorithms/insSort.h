#include <iostream>
#include <vector>
#include "commonFunctions.h"

namespace insSort{
// iterative vesion of the algorithm
void insSort(std::vector<int> &v){
    int hold, i;
    for(int j = 1; j < v.size(); j++){
        hold = v[j];
        i = j-1;
        while(i >= 0 && v[i]>hold){
            v[i+1] = v[i];
            i=i-1;
        }
        v[i+1] = hold;
    }
    return;
}
}