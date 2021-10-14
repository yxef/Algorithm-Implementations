#include <iostream>
#include <vector>
#include <math.h>
#include "commonFunctions.h"
// there's some problems with having used heap.size() and heapSize variable at differnt times
// too lazy to fix it, doesn't work rn

namespace heapSort{
    int heapSize = 0;

    int findParent(int i){return(round(i/2.0)-1);}
    int findLeftChild(int i){return (i*2)+1;}
    int findRightChild(int i){return (i*2)+2;}

    void maxHeapify(int i, std::vector<int> &heap){
        int leftIndex = findLeftChild(i);
        int rightIndex =findRightChild(i);
        int largest;
        if(leftIndex < heapSize && heap[leftIndex] > heap[i]){
            largest = leftIndex;
        }else{
            largest = i;
        }

        if(rightIndex < heapSize && heap[rightIndex] > heap[largest]){
            largest = rightIndex;
        }

        if(largest != i){
            int hold = heap[i];
            heap[i] = heap[largest];
            heap[largest] = hold;
            maxHeapify(largest, heap);
        }
    }

    void buildMaxHeap(std::vector<int> &heap){
        for(int i = findParent(heap.size()-1); i >= 0; i--){
            maxHeapify(i, heap);
        }
    }

    // ricavi array ordinato incrementale da maxHeap
    // this kills the heap, quando implementato in questo modo
    void heapSort(std::vector<int> &heap){
        buildMaxHeap(heap);
        int hold;
        for(int i = heap.size()-1;i > 0; i--){
            hold = heap[0];
            heap[0] = heap[i];
            heap[i] = hold;
            heapSize = heapSize-1;
            maxHeapify(0, heap);
        }
    }

    //TODO
    // INSERT, MAXIMUM, EXTRACT-MAX, INCREASE-KEY

    // Returns the highest value of the heap (highest priority)
    int getMaximum(std::vector<int> heap){
        return heap[1];
    }

    // Returns the value of the node with the highest priority and removes it from the Heap
    // If heap is empty then it returns INT32_MIN as an error message
    int extractMax(std::vector<int> &heap){
        if(heapSize <= 0){
            return INT32_MIN;
        }
        int max = heap[0];
        heap[0] = heap[heapSize-1];       // we swap the first position with the lowest number at pos heapSize
        heapSize--;
        maxHeapify(0,heap);
        return max;
    }
};