//
// Created by joseph on 01/10/2024.
//
#include "iostream"

using namespace std;

//4.4
//arrayString with index 0 == length of following string

typedef char * arrayString;

char characterAt(arrayString a, int index) {
    return a[index+1];
}

int strLen(arrayString a) {
    return a[0];
}

void outString(arrayString a) {

    for(int i = 1; i <= a[0]; i++)
        cout << a[i];


}

void append (arrayString& a, char c) {

    //get length of original string
    int lengthA = strLen(a);

    arrayString b = new char[lengthA+2];

    b[0] = lengthA+1;

    for(int i = 1; i < strLen(b); i++)
        b[i] = a[i];

    b[strLen(b)] = c;

    //dereference memory a pointing to, then assign b to a
    delete[] a;

    a = b;
}


//joins string b to end of string a
void concatenate(arrayString& a, arrayString b) {

    //get both lengths of strings
    int lengthA = strLen(a);
    int lengthB = strLen(b);

    //create new arrayString with combined length of both strings + 1 for length index
    arrayString concatString = new char[lengthA + lengthB + 1];
    concatString[0] = lengthB+lengthA;

    for(int i = 1; i < lengthA+1; i++)
        concatString[i] = a[i];

    for (int j = lengthA + 1; j < lengthA + lengthB + 1; j++)
        concatString[j] = b[j-lengthA];

    delete[] a;
    a = concatString;



}

void appendTest() {
    arrayString test = new char[5] {4, 'a','b','c','d'};

    outString(test); cout<<"\n";

    append(test, 'e');

    outString(test);
}


void concatTest() {
    arrayString test = new char[5] {4, 'a','b','c','d'};

    arrayString b = new char[2]{1, 'x' };

    concatenate(test, b);

    outString(test);

    cout << strLen(test);

}

int main() {

    concatTest();



}