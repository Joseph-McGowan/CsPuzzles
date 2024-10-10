//
// Created by joseph on 10/10/2024.
//
#include "string"
#include "iostream"

using namespace std;

struct studentCollection {
    int studentId;
    int grade;
    string studentName;
};


struct studentNode {
    studentCollection sInfo;
    studentNode* next;
};
typedef studentNode* sn;


//Class representing linked list of student records, and their associated methods
class studentList {
public:
    studentList();
    void addRecord(sn newNode);
    int averageRecord();
    int classSize();
    sn recordsWithinRange(int minGrade, int maxGrade);


private:
    sn _listHead;
    string className;
};

studentList::studentList() {
    this->_listHead = nullptr;
}

sn studentList::recordsWithinRange(int minGrade, int maxGrade) {
    sn newList = new studentNode;
    sn tempList = newList;

    sn loopPtr = this->_listHead;

    while (loopPtr != nullptr) {
        if(loopPtr->sInfo.grade >= minGrade)
            tempList->sInfo = loopPtr->sInfo;
            tempList = tempList->next;
            loopPtr = loopPtr->next;
    }

    return newList;
}


void studentList::addRecord(sn newNode) {
    //prepend record

    if(_listHead == nullptr){
        _listHead = newNode;
        newNode->next = nullptr;
        return;
    }

    sn tempPtr = this->_listHead;
    newNode->next = tempPtr;
    _listHead = newNode;


}

int studentList::classSize(){
    int counter = 0;
    sn loopPtr = this->_listHead;

    while(loopPtr != nullptr) {
        loopPtr = loopPtr->next;
        counter++;
    }

    return counter;

}

int studentList::averageRecord() {
    //return average of all student grades
    double average;
    int noOfStudents = this->classSize();
    int cumulativeGrade = 0;

    sn loopPtr = this->_listHead;

    while(loopPtr != nullptr) {
        cumulativeGrade += loopPtr->sInfo.grade;
        loopPtr = loopPtr->next;
    }

    return {cumulativeGrade / noOfStudents};
}

int main() {
    studentList class1;


    studentCollection student1;
    student1.grade = 50;
    student1.studentId = 1001;
    student1.studentName = "Jimmy";

    studentCollection student2;
    student2.grade = 70;
    student2.studentName = "John";
    student2.studentId = 1002;

    studentNode* classList1 = new studentNode;
    classList1->sInfo = student1;

    class1.addRecord(classList1);

    cout << class1.classSize() << "\n";

    sn s2 = new studentNode;
    s2->sInfo = student2;

    class1.addRecord(s2);

    cout << class1.classSize() << "\n";
    cout << class1.averageRecord() << "\n";


}