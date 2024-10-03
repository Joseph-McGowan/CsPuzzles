//
// Created by joseph on 01/10/2024.
//
#include "iostream"
#include "string"


using namespace std;

struct studentCollection {
    int studentId;
    int grade;
    string studentName;
    studentCollection* next;
};

void removeRecord(studentCollection*& sc, int sNumber) {
    //loop through record until we find matching record
    studentCollection* a = sc;

    //check first record separately
    if(sc->studentId == sNumber) {
        sc = sc->next;
        delete a;
        //delete sc;

        return;
    }


    bool found = true;
    while(a->next->studentId != sNumber) {
        a = a->next;
        if (a->next == nullptr)
            found = false;
    }

    if (!found) {
        cout << "couldn't match record";
        return;
    }

    //point previous record to next
    studentCollection*b = a->next;

    a->next = b->next;

    //delete record
    delete b;

}

void printCollection(studentCollection* sc) {

    studentCollection * temp = sc;

    if(temp == nullptr)
        return;

    while(temp->next != nullptr ) {
        cout << temp->studentName << " " << temp->grade << " \n";
        temp = temp->next;
    }

    cout << temp->studentName << " " << temp->grade << " \n";

    cout << "\n";
}



int main() {

    studentCollection* sc = new studentCollection;

    studentCollection* a = new studentCollection {10001, 100, "Fred"};
    studentCollection* b = new studentCollection;
    studentCollection* c = new studentCollection;

    a->next = b;

    b->studentName = "asdf"; b->grade = 50; b->studentId = 1002; b->next =  c;
    c->studentId = 1003; c->grade = 30; c->studentName = "askdlfj"; c->next = nullptr;

    sc = a;

    a = b = c = nullptr;

    printCollection(sc);



    removeRecord(sc, 1003);

    printCollection(sc);

    removeRecord(sc, 1002);

    printCollection(sc);

    removeRecord(sc, 10001);

    printCollection(sc);




}