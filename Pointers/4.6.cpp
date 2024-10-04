//Ex 4.6: Linked List strings
// Created by joseph on 03/10/2024.
//
#include "iostream"

using namespace std;

typedef struct linkedString {
    char character;
    linkedString* next;
} linkedString;

void strAppend(linkedString*& s, char a) {

    //create new node, to be appended
    linkedString* b = new linkedString;
    b->character = a;
    b->next = nullptr;



    //loop through string until we reach last char
    linkedString* temp = s;

    while (temp->next != nullptr)
        temp = temp->next;

    //assign next to new node
    temp->next = b;

}

char characterAt(int index, linkedString* s) {

    int i = 0;
    linkedString* temp = s;

    while(i != index) {
        //move to next node, checking wether we have reached the end of the string
        if(temp->next == nullptr) {
            cout << "index not in range" << endl;
            return 0;
        }
        temp = temp->next;
        i++;
    }

    return temp->character;

}

int strLen(linkedString sc);

void concatenate(linkedString*& s1, linkedString* s2) {

    linkedString* temp = s2;

    while(temp->next != nullptr) {
        strAppend(s1, temp->character);
        temp = temp->next;
    }

    strAppend(s1, temp->character);

}

//void appendTest() {
//
//
//    cout << characterAt(1, s) << endl;
//
//    strAppend(s, 't');
//
//    cout << characterAt(3, s);
//}

void printString(linkedString* s1) {

    linkedString* temp = new linkedString;
    temp = s1;

    while(temp->next != nullptr) {
        cout << temp->character;
        temp = temp->next;
    }

    cout << temp->character;
    cout << "\n";

}

void removeChars(linkedString*& s1, int startIndex, int noChars) {

    linkedString* temp = new linkedString;
    temp = s1;

    int index = 1;

    while(index != startIndex - 1){
        if (temp->next == nullptr)
            return;
        temp = temp->next;
        index++;
    }

    linkedString* startChar = new linkedString;
    startChar = temp;
    temp = temp->next;

    int charCounter = 0;
    while(charCounter != noChars && temp->next != nullptr) {

        startChar->next = temp->next;
        temp = nullptr;
        temp = startChar->next;
        charCounter++;
    }


}


int main() {
    linkedString* a = new linkedString;
    linkedString* b = new linkedString;
    linkedString* c = new linkedString;

    a->character = 'x';
    a->next = b;

    b->next = c;
    b->character = 'y';

    c->character = 'j';
    c->next = nullptr;

    linkedString* s = new linkedString;

    s = a;
    a = b = c = nullptr;

    linkedString* x = new linkedString;
    linkedString* y = new linkedString;

    x->next = y;
    x->character = 'p';

    y->next = nullptr;
    y->character = 'u';

    linkedString* s2 = new linkedString;

    s2 = x;

    x = y = nullptr;

    concatenate(s, s2);

    printString(s);

    removeChars(s, 2, 2);

    printString(s);

    return 1;


}