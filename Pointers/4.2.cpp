//
// Created by joseph on 30/09/2024.
//

#include "iostream"

//4.2 SubString function on arrayString

typedef char* arrayString;

using namespace std;

char characterAt (int index, char* s) {
    return s[index];
}

int strLength(char* iString) { // returns number of characters in string (- null terminator)
    int i = 0;
    while (iString[i] != 0)
        i++;

    return i;
}

void append (char*& iString, char c) {
    //get length of string

    int iLength = strLength(iString);

    //Create new string with length + 2 for new char and null terminator

    arrayString newString = new char[iLength+2];

    //copy chars of old String to new String

    for (int i = 0; i < iLength; i++) {
        newString[i] = iString[i];
    }

    newString[iLength] = c;
    newString[iLength+1] = 0;

    delete[] iString; //deallocates memory associated for iString

    iString = newString;

    newString = nullptr;
    //iString = nullptr;

}

arrayString subString (arrayString a, int startIndex, int noChars) {

    int aLength = strLength(a);
    if (startIndex + noChars > aLength+1)
        return nullptr;

    arrayString newSubString = new char[noChars+1];

    for (int i = 0; i < noChars; i++) {
        newSubString[i] = a[i+startIndex-1];
    }
    newSubString[noChars] = 0;

    return newSubString;

}

void testSubString() {
    arrayString a = new char[5];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    a[3] = 'd';
    a[4] = 0;

    int i = 1; int noC = 4;

    arrayString b = subString(a, i, noC);

    cout << b;
}

void replaceText(arrayString& source, arrayString target, arrayString replace) {
    //allocate memory for new string
    arrayString s = new char[1];
    s[0] = 0;
    int oStringLength = strLength(source);
    int targetLength = strLength(target);
    bool match = true;

    for (int i = 0; i < oStringLength; i++) {
        if(source[i] == target[0]) {//loop through rest of target to see if we have a match
            match = true;
            for(int j = 1; j < targetLength; j++) {
                if (source[i+j] == target[j])
                    continue;
                else
                    match = false;
            }
            if (match) {
                for (int index = 0; index < strLength(replace); index++) {
                    append(s, replace[index]);
                }
                i = i + strLength(replace) - 1;

            }
            else {
                append(s, source[i]);
            }
        }
        else {
            append(s, source[i]);
        }
    }

    delete[] source;
    source = s;

}

void testReplace() {
    arrayString test = new char[8]{'a', 'b', 'c', 'd', 'a', 'b', 'g', 0};

    cout << test << "\n";

    arrayString b = new char[3]{'a','b',0};

    arrayString replace = new char[4]{'x','y','z', 0};

    replaceText(test, b, replace);

    cout << test << "\n";
}

int main() {

//    arrayString testString = new char[3];
//    testString[0] = 'o';
//    testString[1] = 'k';
//    testString[2] = 0;
//
//    cout << testString << "\n";
//
//    append(testString,  '!');
//
//    cout << testString;

    //testSubString();
    testReplace();


}