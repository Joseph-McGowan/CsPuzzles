//
// Created by joseph on 22/09/2024.
//
#include "iostream"

using namespace std;

bool isSorted(int aList[], int listSize) {

    int element = 0;
    while (element < listSize)
    {
        if (aList[element] > aList[element+1])
            return false;
        element++;
    }
    return true;

}

int main() {

    int testList[] = {1,2,4,10};
    int testFail[] = {1,2,10,1};
    int edgeCasePass[] {1,1,1,1,1};

    cout << isSorted(testList, size(testList));
    cout << "\n" << isSorted(testFail, size(testFail));
    cout <<"\n" << isSorted(edgeCasePass, size(edgeCasePass));

}