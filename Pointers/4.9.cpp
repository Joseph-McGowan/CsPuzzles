//
// Created by joseph on 07/10/2024.
//

//Ex 4.9 - Linked List Integers
#include "iostream"
using namespace std;

struct integerDigit {
    int digit;
    integerDigit* next;
};

typedef integerDigit* intDigit;

void appendIntDigit (intDigit& i, int val) {

    intDigit temp = new integerDigit;
    temp = i;

    while (temp->next != nullptr)
        temp = temp->next;

    intDigit newDigit = new integerDigit;
    newDigit->digit = val;
    newDigit->next = nullptr;

    temp->next = newDigit;

    temp = newDigit = nullptr;

}

intDigit intToList(int intVal) {
    //converts integer to linkedList integer

    int temp = intVal;

    //Mod to find each digit value, append value to list;
    int modVal = 10;

    intDigit a = new integerDigit;
    a->next = nullptr;

    a->digit = intVal % modVal;
    temp -= intVal % modVal;

    modVal *= 10;

    while(temp != 0) {
        int valueAppend = (temp % modVal);
        int digitToAppend = valueAppend / (modVal / 10);
        appendIntDigit(a, digitToAppend);
        temp -= valueAppend;
        modVal *= 10;
    }

    return a;
}

void printLinkedInt(intDigit a) {

    intDigit temp = new integerDigit;
    temp = a;

    while(temp->next != nullptr) {
        cout << temp->digit << " ";
        temp = temp->next;
    }

    cout << temp->digit ;

}


int linkedIntLength (intDigit a) {

    intDigit temp = new integerDigit;
    int counter = 0;
    temp = a;

    while(temp->next != nullptr){
        temp = temp->next;
        counter++;
    }

    return counter +1;
}


intDigit addIntegers (intDigit a, intDigit b) {

    intDigit sum = new integerDigit;
    int carry = 0;

    int lenA = linkedIntLength(a);
    int lenB = linkedIntLength(b);


    int digitsInCommon = min(lenA, lenB);

    intDigit tempA = new integerDigit;
    intDigit tempB = new integerDigit;

    tempA = a;
    tempB = b;

    int addedDigit = tempA->digit + tempB->digit;
    if (addedDigit > 9) {
        carry = 1;
        addedDigit -= 10;
    }
    sum->digit = addedDigit;
    sum->next = nullptr;

    tempA = tempA->next;
    tempB = tempB->next;

    for(int i = 1; i < digitsInCommon; i++) {
        int addedDigit = tempA->digit + tempB->digit;
        if(carry)
            addedDigit += 1;
        carry = 0;
        if (addedDigit > 9) {
            carry = 1;
            addedDigit -= 10;
        }
        appendIntDigit(sum, addedDigit);
        tempB = tempB->next;
        tempA = tempA->next;

    }

    if (lenA > lenB) {
        if (carry) {
            tempA->digit += 1;
            if (tempA->digit > 10) {
                tempA->next += 1;
                while (tempA->next != nullptr && tempA->next->digit == 10) {
                    appendIntDigit(sum, 0);
                    tempA = tempA->next;
                }
                int finalVal = tempA->digit;
                appendIntDigit(sum, finalVal);
            }
        }
        else {
            while(tempA->next != nullptr) {
                appendIntDigit(sum, tempA->digit);
                tempA = tempA->next;
            }
            appendIntDigit(sum, tempA->digit);
        }
    }
    else {
        cout << "unimplemented";
    }

    return sum;

}

int main() {

    intDigit a = new integerDigit;
    a->next = nullptr;

    a = intToList(327);

    intDigit b = new integerDigit;
    b->next = nullptr;

    b = intToList(12);

    intDigit c = new integerDigit;

    c = addIntegers(a,b);


    printLinkedInt(c);

    printLinkedInt(a);

}