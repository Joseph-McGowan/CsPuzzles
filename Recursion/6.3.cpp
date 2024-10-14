//
// Created by joseph on 14/10/2024.
//
#include "iostream"

using namespace std;

int targetCount(int iArray[], int iSize, int target) {

    //Base case, array size = 0
    if (iSize == 0 )
        return 0;
    else {
        return {(iArray[iSize - 1] == target) + targetCount(iArray, iSize - 1, target)};

        if (iArray[iSize - 1] == target)
            return 1 + targetCount(iArray, iSize - 1, target);
        return targetCount(iArray, iSize - 1, target);
    }

}



int main() {


    int testArray[] = {1,5,3,89,4,3,67,12,3,9,2}; //3 appears 4 times
    int testLen = 11;

    cout << targetCount(testArray, testLen, 3);

}


