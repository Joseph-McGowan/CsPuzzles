//
// Created by joseph on 11/10/2024.
//
#include "iostream"

using namespace std;

int sumPositiveNumbs(int vals[], int size) {
    //find sum of all positive numbers in array
    //base case, array size = 0;
    //recursive case, if last array value is postive, add to sumPosNumbs(size - 1)
    //else, add 0 to sumPosNumbs(size -1)

    if (size == 0)
        return 0;
    else {
        if (vals[size - 1] > 0)
            return vals[size-1] + sumPositiveNumbs(vals, size - 1);
        else
            return 0 + sumPositiveNumbs(vals, size - 1);
    }

}


int main() {
    int test[] = {3,-1,5,7,-5,0,5,1};

    cout << sumPositiveNumbs(test, 8);
}