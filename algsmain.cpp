#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "Algorithms/algslib.h"
#include "Algorithms/commonFunctions.h"


void generateRandomIntVector(std::vector<int> &toRandomize, int desiredSize, int maxValueRange){
    if(toRandomize.size() == 0){
        for(int i = 0; i < desiredSize; i++){
            toRandomize.push_back(rand() % maxValueRange);
        }
    }else{
        for(int i = 0; i < toRandomize.size(); i++){
            toRandomize[i] = rand() % maxValueRange;
        }
        for(int i = toRandomize.size(); i < desiredSize; i++){
            toRandomize.push_back(rand() % maxValueRange);
        }
    }
}

int main(){
    srand(time(NULL));
    std::vector<int> vectorToGenerate;
    generateRandomIntVector(vectorToGenerate, 10, 30);
    bool exit = false;

    int choiceSelector = 0;
    while(choiceSelector != -1){
        std::cout << "Choose your algorithm:"<< std::endl;
        std::cout << "[0] Scramble vector" << std::endl;
        std::cout << "[1] Insertion Sort" << std::endl;
        std::cout << "[2] Merge Sort" << std::endl;
        std::cout << "[3] Bubble Sort" << std::endl;
        std::cout << "[4] Selection Sort" << std::endl;
        std::cout << "[5] Peak Finder Algorithm \033[2;32m[IN THE END I IMPLEMENTED IT :)]\033[0m" << std::endl;
        std::cout << "[6] Heap Sort  \033[1;31m[DOESN'T WORK]\033[0m" << std::endl;
        std::cout << "[7] Quick Sort" << std::endl;
        std::cout << "[-1] To exit this menu" << std::endl;
        std::cin >> choiceSelector;
        printVector(vectorToGenerate);
        switch (choiceSelector)
        {
        case 0:
            std::cout << "you choose to scramble the vector" << std::endl;
            generateRandomIntVector(vectorToGenerate, vectorToGenerate.size(), 30);
            std::cout << "New Vector: ";
            break;
        case 1:
            std::cout << "You chose Insertion Sort"<< std::endl;
            insSort::insSort(vectorToGenerate);
            break;
        case 2:
            std::cout << "You chose Merge Sort"<< std::endl;
            mergeS::mergeSort(vectorToGenerate);
            break;
        case 3:
            std::cout << "You chose Bubble Sort"<< std::endl;
            vectorToGenerate = bubbleSort::bubbleSort(vectorToGenerate);
            break;
        case 4:
            std::cout << "You chose Selection Sort"<< std::endl;
            vectorToGenerate = selSort::selSort(vectorToGenerate);
            break;
        case 5:
            std::cout << "You chose Peak Finder Algortitmh"<< std::endl;
            peakFinder::findPeakInVector(vectorToGenerate);
            break;
        case 6:
            std::cout << "You chose Heap Sort"<< std::endl;
            heapSort::heapSort(vectorToGenerate);
            break;
        case 7:
            std::cout << "You chose Quick Sort"<< std::endl;
            quickS::quickSortRand(vectorToGenerate);
            break;
        case 69:
            std::cout << "Nice"<< std::endl;
        break;
        case -1:
            std::cout << "googbye" << std::endl;
            exit = true;
            break;
        default:
            std::cout << "Not a valid choice"<<std::endl;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
            }
            break;
        }
        if(checkIfVectorSorted(vectorToGenerate) && !exit){
            printVector(vectorToGenerate);
            std::cout << "\033[4;32m" << "Can confirm that the vector is sorted" << "\033[0m"<<std::endl;
            std::cout << "\033[4;37m" << "\tsource: trust me bro" << "\033[0m" << std::endl;
        }else if(!checkIfVectorSorted(vectorToGenerate) && !exit){
            printVector(vectorToGenerate);
            std::cout << "\033[4;31m" << "The vector is NOT sorted" << "\033[0m"<<std::endl;
        }
    }
}