//
// Created by joseph on 14/10/2024.
//

//Check whether binary array has odd parity

#include "iostream"

using namespace std;

bool isOddParityRecursive(const int iString[], int iStringLen) {
    //base case
    if (iStringLen == 1)
        return iString[iStringLen - 1];
    else {
        return {isOddParityRecursive(iString, iStringLen - 1) != (iString[iStringLen - 1])};
    }

}




bool isOddParityIterative(const int iString[], int iStringLen) {

    int counter = 0;

    for(int i = 0; i < iStringLen; i++) {
        if (iString[i] == 1)
            counter++;
    }

    return {bool(counter % 2)};

}




int main() {
    int binaryStringEven[] = {1,0,1,0,1,0,1}; //even parity
    int binaryStringOdd[] = {1,0,1,0,1}; //odd parity

    //cout <<  isOddParityIterative(binaryStringEven, 7);
    //cout << "\n" << isOddParityIterative(binaryStringOdd, 5);

    cout << isOddParityRecursive(binaryStringEven, 0);

}