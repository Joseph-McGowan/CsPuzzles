//
// Created by joseph on 17/10/2024.
//

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

typedef bool (* firstStudentPolicy)(studentCollection s1, studentCollection s2);


//Class representing linked list of student records, and their associated methods
class studentList {
public:
    studentList();
    void addRecord(sn newNode);
    int averageRecord();
    int classSize();
    sn recordsWithinRange(int minGrade, int maxGrade);
    void setFirstStudentPolicy(int flag);
    studentCollection firstStudent();


private:
    sn _listHead;
    string className;
    firstStudentPolicy _studentPolicy;
    static bool higherGrade(studentCollection s1, studentCollection s2) {
        return s1.grade > s2.grade;
    }

    static bool lowerStudentNumber(studentCollection s1, studentCollection s2) {
        return s1.studentId < s2.studentId;
    }

    enum policies {highGrade, lowSNumb};
};

void studentList::setFirstStudentPolicy(int flag) {
    switch (flag) {
        case highGrade:
            _studentPolicy = higherGrade;
            break;
        case lowSNumb:
            _studentPolicy = lowerStudentNumber;
            break;
    }
}

studentCollection studentList::firstStudent() {
    sn loopPtr = this->_listHead;
    studentCollection first = loopPtr->sInfo;
    loopPtr = loopPtr->next;

    while(loopPtr != nullptr) {
        if (_studentPolicy(loopPtr->sInfo, first))
        {
            first = loopPtr->sInfo;
        }
        loopPtr = loopPtr->next;
    }
    return first;
}

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

