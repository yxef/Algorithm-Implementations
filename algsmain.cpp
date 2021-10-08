#include <iostream>
#include <vector>
#include <math.h>

template <typename T>
void printVector(std::vector<T> toPrint){
    for(int i = 0; i < toPrint.size(); i++){
        std::cout << toPrint[i];
    }
    std::cout << std::endl;
}


int main(){
    std::vector<char> cringerz = {'b', 'a', 's', 'e', 'd' };
    printVector(cringerz);
}
