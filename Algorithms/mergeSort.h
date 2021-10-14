#include <iostream>
#include <vector>       // std::vector
#include "commonFunctions.h"

namespace mergeS{
void merge(std::vector<int> &vectorToSort, int vecFirst, int vecMid, int vecLast){
    std::cout << "\n----STARTING MERGE----";
    int nElementsLeft= vecMid-vecFirst+1;
    int nElementsRight= vecLast-vecMid;
    std::vector<int> vectorLeft;
    std::vector<int> vectorRight;
    for(int i = 0; i < nElementsLeft; i++){
        std::cout << "\n [R] Reading vectorToSort -\tposition: ["<<vecFirst+i<<"]-\tvalue: "<<vectorToSort[vecFirst+i];
        vectorLeft.push_back(vectorToSort[vecFirst+i]);
        std::cout << "\n {W} Written in vectorLeft -\t\t\tvalue: "<<vectorLeft[i];
    }
    for(int i = 0; i < nElementsRight; i++){
        std::cout << "\n [R] reading vectorToSort -\tposition: ["<< vecMid+i+1 <<"]-\tvalue: "<< vectorToSort[vecMid+i+1];
        vectorRight.push_back(vectorToSort[vecMid+i+1]);
        std::cout << "\n {W} Written in vectorRight -\t\t\tvalue: "<< vectorRight[i];
    }
    
    std::cout << "\n Printing temporary VectorLeft:";
    printVector(vectorLeft);
    std::cout << "\n Printing temporary VectorRight:";
    printVector(vectorRight);


    int leftCounter=0;
    int rightCounter=0;
    vectorLeft.push_back(INT32_MAX);
    vectorRight.push_back(INT32_MAX);
    std::cout << "\n---------------------RECONSTRUCTING ARRAY---------------------\n";
    for(int k = vecFirst; k <= vecLast; k++){
        std::cout <<"\nabout to compare vectorLeft["<<leftCounter<<"]="<<vectorLeft[leftCounter]<<" with vectorRight["<<rightCounter<<"]="<<vectorRight[rightCounter]<<"\n";
        if(vectorLeft[leftCounter] < vectorRight[rightCounter]){
            std::cout<<"assigning vectorLeft["<<leftCounter<<"] \t with value: "<<vectorLeft[leftCounter]<<" \t to vectorToSort["<<k<<"]\n";    
            vectorToSort[k] = vectorLeft[leftCounter];
            leftCounter++;
        }else{
            std::cout<<"assigning vectorRight["<<rightCounter<<"] \t with value: "<<vectorRight[rightCounter]<<" \t to vectorToSort["<<k<<"]\n";    
            vectorToSort[k] = vectorRight[rightCounter];
            rightCounter++; 
        }
    }
    printArrayWithRange(vectorToSort, vecFirst, vecLast);
    std::cout << "\n---------------------RECONSTRUCTION TERMINATED---------------------\n";

    return;
}

// when calling this outside the main function
// vecFirst is the first element of the array, usually 0 when calling this from outside the function.
// vecLast is equal to the length of the array, which is equal to vectorToSort.size()-1;
void mergeSort(std::vector<int> &vectorToSort, int vecFirst, int vecLast){
    if(vecFirst<vecLast){
        int vecMid = (vecFirst+vecLast)/2 ;
        
        printArrayWithRange(vectorToSort, vecFirst, vecMid);
        mergeSort(vectorToSort, vecFirst, vecMid);
        printArrayWithRange(vectorToSort, vecMid+1, vecLast);
        mergeSort(vectorToSort, vecMid+1, vecLast);

        merge(vectorToSort, vecFirst, vecMid, vecLast);
    }
    return;
}

void mergeSort(std::vector<int> &vectorToSort){
    mergeSort(vectorToSort, 0, vectorToSort.size()-1);
}
}