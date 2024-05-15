//
// Created by joseph on 15/05/2024.
//
#include "stdio.h"
#include "iostream"
#include <vector>

const int ARRAY_SIZE = 10;

int compareFunc(const void* voidA, const void* voidB) {
    //compares to pointers to integers (elements in array)
    //int a is bigger if A - B > 0
    //int a is smaller if A - B < 0
    //a = b if A - B = 0

    int * intA = (int*)(voidA);
    int * intB = (int*)(voidB);
    return *intA - *intB;

}

void qSortTest() {

    int intArray[ARRAY_SIZE] = {1,6,2,7,9,20,34,2,643,4};

    //qsort takes in array to be sorted, array size, size of array elements, and a compare function;
    std::qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);

    for (int i : intArray) {
        std::cout << i << std::endl;
    }
}

//
void insertionSortExample() {

    int start = 0;
    int unsortedArray[ARRAY_SIZE] = {1,6,2,7,9,20,34,2,643,4};
    int end = ARRAY_SIZE - 1;

    start = unsortedArray[0];

    for (int i = start + 1; i <= end ; i++) {
    for (int j = i; j > start && unsortedArray[j-1] > unsortedArray[j]; j--) {
    int temp = unsortedArray[j-1];
    unsortedArray[j-1] = unsortedArray[j];
    unsortedArray[j] = temp;
    }
    }

    for (auto c : unsortedArray) {
    std::cout << c << std::endl;
    }

}

void mode () {

    const int modeArraySize = 12;
    int modeArray[modeArraySize] = {4, 7, 4, 8, 9, 7, 3, 9, 9, 3, 3, 10 };


    //find how many times a value appears
    int modeValue;
    int modeCount = 0;

    int valueToCount;
    int valueCount;

    for (int i = 0; i < modeArraySize; ++i) {
        valueToCount = modeArray[i];
        valueCount = 0;
        for (int j = 0; j < modeArraySize; ++j) {
            if (modeArray[j] == valueToCount)
                valueCount++;
        }

        if (valueCount > modeCount) {
            modeCount = valueCount;
            modeValue = valueToCount;
        }


    }

    std::cout << modeValue << std::endl;
    std::cout << modeCount << std::endl;

    int modalValue = 0;
}

int main() {

    //mode();

    std::vector<int> surveyData;
    surveyData.reserve(20);

    std::cout << surveyData.size() << std::endl;

    surveyData.push_back(3);

    std::cout << surveyData.size() << std::endl;


    return 0;

}