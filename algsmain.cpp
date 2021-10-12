#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Algorithms/quickSort.h"
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

    int choiceSelector = 0;
    while(choiceSelector != -1){
        std::cout << "Choose your algorithm:"<< std::endl;
        std::cout << "[0] Scramble vector" << std::endl;
        std::cout << "[1] Insertion Sort" << std::endl;
        std::cout << "[2] Merge Sort" << std::endl;
        std::cout << "[3] Bubble Sort" << std::endl;
        std::cout << "[4] Selection Sort" << std::endl;
        std::cout << "[5] Peak Finder Algorithm" << std::endl;
        std::cout << "[6] Heap Sort" << std::endl;
        std::cout << "[7] Quick Sort" << std::endl;
        std::cout << "[-1] To exit this menu" << std::endl;
        std::cin >> choiceSelector;
        switch (choiceSelector)
        {
        case 0:
            std::cout << "you choose to scramble the vector" << std::endl;
            generateRandomIntVector(vectorToGenerate, vectorToGenerate.size(), 30);
            std::cout << "New Vector: ";
            printVector(vectorToGenerate);
            break;
        case 1:
            std::cout << "You chose Insertion Sort"<< std::endl;
            break;
        case 2:
            std::cout << "You chose Merge Sort"<< std::endl;
            break;
        case 3:
            std::cout << "You chose Bubble Sort"<< std::endl;
            break;
        case 4:
            std::cout << "You chose Selection Sort"<< std::endl;
            break;
        case 5:
            std::cout << "You chose Peak Finder Algortitmh"<< std::endl;
            break;
        case 6:
            std::cout << "You chose Heap Sort"<< std::endl;
            break;
        case 7:
            printVector(vectorToGenerate);
            std::cout << "You chose Quick Sort"<< std::endl;
            quickS::quickSort(vectorToGenerate);
            printVector(vectorToGenerate);
            break;
        case 69:
            std::cout << "Nice"<< std::endl;
        break;
        case -1:
            std::cout << "googbye" << std::endl;
            break;
        default:
            std::cout << "Not a valid choice"<<std::endl;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
            }
            break;
        }
    }
}