//
// Created by joseph on 10/05/2024.
//

#include <iostream>

bool luhnCheck(int n) {
    //given number n
    //double every other digit of n
    //add digit values
    //return true if divisible by 10

    int x;
    int luhnDigit = 0;
    int luhnCounter = 0;

    while (n > 0) {
        x = n %10;
        n /= 10;

        if (luhnDigit) {
            x *= 2;
            if (x >= 10) {
                luhnCounter += (x % 10) + (x / 10);
            }
            else {
                luhnCounter += x;
            }
        }
        else {
            luhnCounter += x;
        }
        luhnDigit = !luhnDigit;

    }

    if ((luhnCounter % 10 == 0))
        return true;
    return false;
}


void messageDecode() {

    int decipherMode = 0;  //0 = upper, 1 = Lower, 2 = punctuation

    char* stream = new char;
    int i = 0;
    int numberToDecode = 0;

    char digit = std::cin.get();

    int decodeValue = 0;
    int endFlag = 1;

    numberToDecode += digit - '0';

    digit = std::cin.get();
    while(digit != 10 || !endFlag) {
        if (digit == ',' || digit == 10) {
            switch (decipherMode % 3) {
                case 0:
                    decodeValue = numberToDecode % 27;
                    if (decodeValue == 0) {
                        decipherMode++;
                        break;
                    }
                    stream[i] = (decodeValue + 64);
                    i++;
                    break;
                case 1:
                    decodeValue = numberToDecode % 27;
                    if (decodeValue == 0) {
                        decipherMode++;
                        break;
                    }
                    stream[i] = (decodeValue + 96);
                    i++;
                    break;
                case 2:
                    decodeValue = numberToDecode % 9;
                    switch (decodeValue) {
                        case 0:
                            decipherMode++;
                            break;
                        case 1:
                            stream[i] = '!';
                            i++;
                            break;
                        case 2:
                            stream[i] = '?';
                            i++;
                            break;
                        case 3:
                            stream[i] = ',';
                            i++;
                            break;
                        case 4:
                            stream[i] = '.';
                            i++;
                            break;
                        case 5:
                            stream[i] = ' ';
                            i++;
                            break;
                        case 6:
                            stream[i] = ';';
                            i++;
                            break;
                        case 7:
                            stream[i] = '"';
                            i++;
                            break;
                        case 8:
                            stream[i] = '\'';
                            i++;
                            break;
                    }

            }
            numberToDecode = 0;
            endFlag = 1;
        }
        else {
            numberToDecode = (numberToDecode * 10) + (digit - '0');
            endFlag = 0;
        }

        if (digit == 10)
            break;
        digit = std::cin.get();
    }

    for (int j = 0; j < i ; j++) {
        std::cout << stream[j];
    }


}

void test() {
    char a = std::cin.get();
    int b = a ;
    std::cout << b;
    int gitTest;
}

int main() {
    //std::cout << luhnCheck(1762484) << std::endl;
    messageDecode();
    //test();
}