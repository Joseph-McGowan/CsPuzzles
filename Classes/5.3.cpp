//
// Created by joseph on 09/10/2024.
//
#include "iostream"

using namespace std;

struct charPointer {
    char character;
    charPointer* next;
};
typedef charPointer* cp;

class varString {
public:
    varString() {
        _listHead = nullptr;
    }

    ~varString() {
        deleteList(this->_listHead);
    }

    varString& operator=(const varString& rhs) {
        if (this != &rhs) {
            deleteList(_listHead);
            _listHead = copiedString(rhs._listHead);
        }
        return *this;
    }

    char operator[](int index) {
        //cout << this->characterAt(index);
        char a = this->characterAt(index);
        return a;
    }


    void append(char c);
    void concatenate(const varString& s);
    char characterAt(int index);
    void printString();
    int strLength();
    void remove(int startIndex, int charsToRemove);


private:
    charPointer* _listHead;
    void deleteList(cp& listPtr) {
        while (listPtr != nullptr) {
            cp temp = listPtr;
            listPtr = listPtr->next;
            delete temp;
        }
    }
    cp copiedString(const cp original);


};

int varString::strLength() {
    int counter = 0;
    cp loopPtr = this->_listHead;

    while (loopPtr != nullptr) {
        loopPtr = loopPtr->next;
        counter++;
    }

    return counter;
}

void varString::printString() {
    cp temp = _listHead;
    while(temp!= nullptr) {
        cout << temp->character;
        temp = temp->next;
    }
    cout << "\n";
}

void varString::append(char c) {
    cp temp = _listHead; //loop pointer

    cp newNode = new charPointer; //new node to append
    newNode->character = c;
    newNode->next = nullptr;

    //if string is empty
    if (temp == nullptr) {
        _listHead = newNode;
        newNode = nullptr;
        return;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;

    //dereference any used pointers
    newNode = nullptr;
    temp = nullptr;

}

void varString::concatenate(const varString& s) {
    //append input string to end of object string
    cp loopPtr = s._listHead;
    while (loopPtr != nullptr) {
        this->append(loopPtr->character);
        loopPtr = loopPtr->next;
    }

    //loopPtr = nullptr;

}

char varString::characterAt(int index) {
    cp loopPtr = _listHead;
    int temp = 0;
    while(loopPtr != nullptr && index != temp) {
        loopPtr = loopPtr->next;
        temp++;
    }
    if (loopPtr)
        return loopPtr->character;

    cout << "error, index not found";
    return 0;
}

cp varString::copiedString(const cp original) {
    if (original == nullptr)
        return nullptr;

    cp newString = new charPointer;
    newString->character = original->character;
    cp oldPointer = original->next;
    cp newPointer = newString;
    while(oldPointer != nullptr) {
        newPointer->next = new charPointer;
        newPointer->next = oldPointer;
        newPointer = newPointer->next;
        oldPointer = oldPointer->next;
    }
    newPointer->next = nullptr;
    return newPointer;
}

void varString::remove(int startIndex, int charsToRemove) {

    if (startIndex + charsToRemove > this->strLength() || startIndex > this->strLength()) {
        cout << "Error";
        return;
    }

    if (startIndex == 0) {
        cp loopPtr  = this->_listHead;
        while (charsToRemove != 0 && loopPtr != nullptr) {
            cp temp = loopPtr;
            loopPtr = loopPtr->next;
            delete temp;
            charsToRemove--;
        }
        this->_listHead = loopPtr;

        return;
    }


    int loopCounter = 0;
    cp tempLoop = this->_listHead;

    //have pointer to char before startIndex


    while(loopCounter != startIndex -1) {
        loopCounter++;
        tempLoop = tempLoop->next;
    }

    cp backMarker = tempLoop;
    tempLoop = tempLoop->next;


    while (tempLoop != nullptr && charsToRemove != 0 ) {
        cp nodeToDelete = tempLoop;
        tempLoop = tempLoop->next;
        backMarker->next = tempLoop;
        delete nodeToDelete;
        charsToRemove--;
    }


}



int main() {
    varString c;
    c.append('a');
    c.append('b');

    //c.printString();


    varString x;
    x.append('x');
    x.append('y');

    c.concatenate(x);

    //x.printString();
    //c.printString();

    char test = c[1];
    //cout << test;

    c.remove(0, 3);
    c.printString();



}