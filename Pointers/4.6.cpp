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

    cout << characterAt(1, s) << endl;

    strAppend(s, 't');

    cout << characterAt(3, s);




}