#include <iostream>
#include <vector>
#include "commonFunctions.h"

/*
    Definition of a Peak
    a peak is a number A[x] such that A[x] >= A[y], A[x]>=A[z]
    for example, in an array we have
    A[y] = 2;
    A[x] = 5;
    A[z] = 3;
    y,x,z indicate the array A's cells in succession such as 1,2,3
    In short, a peak is an array element that is NOT smaller than its neighbours
    for corners we only look at one neighbour
*/

namespace peakFinder{
    int findPeak(int firstPos, int lastPos, std::vector<int> vectorToSearch){
        int middle = firstPos + (lastPos-firstPos)/2;
        if(middle == 0){
            if(vectorToSearch[0] >= vectorToSearch[1]){
                return 0;
            }
        }else if(middle == vectorToSearch.size()-2){
            if(vectorToSearch[vectorToSearch.size()-1] >= vectorToSearch[vectorToSearch.size()-2]){
                return vectorToSearch.size()-1;
            }
        }else if(vectorToSearch[middle] >= vectorToSearch[middle+1] && vectorToSearch[middle] >= vectorToSearch[middle-1]){
            return middle;
        }else if(vectorToSearch[middle+1] >= vectorToSearch[middle]){
            return findPeak(middle, lastPos, vectorToSearch);
        }else if(vectorToSearch[middle-1] >= vectorToSearch[middle]){
            return findPeak(firstPos, middle, vectorToSearch);
        }

        return -1;
    }

    // recursive, divide and conquer function to find a peak
    void findPeakInVector(std::vector<int> vectorToSearch){
        int pos = findPeak(0, vectorToSearch.size()-1, vectorToSearch);
        if(pos == -1)
            std::cout<<"Peak not found\n";
        std::cout<<"\nPeak in position ["<<pos<<"]\t value: "<< vectorToSearch[pos]<<"\n";
        
    }
}