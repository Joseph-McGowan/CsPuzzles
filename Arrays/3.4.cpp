//
// Created by joseph on 22/09/2024.
//
#include <cstring>
#include "iostream"
#include "string"

using namespace std;




char* convertString(char* stringToConvert, int messageSize) {
    //covert string to ascii equivalent
    //subtract to bring within bounds of array
    //stringToConvert[i] = conversionTable[charNumber]

    const char conversionTable[26] = {'C','D', 'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B'};

    for (int i = 0; i < messageSize; i++) {
        int charKey = int(toupper(stringToConvert[i]) - 65);
        if (charKey == -33)
            continue;
        *(stringToConvert + i) = conversionTable[charKey] ;
    }

    return stringToConvert;

}

char* decodeString(char* cipherText, int messageSize) {
    //reverse of encoding
    //Ex 3.5

    const char conversionTable[26] = {'A', 'B', 'C','D', 'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for (int i = 0; i < messageSize; i++) {
        int charKey = int(cipherText[i]);
        cout << charKey << "\n";
        if (charKey == 32) {
            continue;
        }
        cipherText[i] = conversionTable[charKey - 67];
    }

    return cipherText;

}



int main() {

    char test[] = "this is a test";

    char* converted = convertString(test, (strlen(test)));

    cout << converted << endl;

    char* decoded = decodeString(converted, strlen(converted));

    cout << decoded << endl;

    return 1;
}