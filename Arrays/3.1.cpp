//
// Created by joseph on 18/09/2024.
//

#include "string"
#include "iostream"


struct student {
    int grade;
    int studentId;
    std::string name;
};

int compareFuncGrade(const void* voidA, const void* voidB)
{
    student* studentA = (student*) (voidA);
    student* studentB = (student* ) (voidB);

    return studentA->grade - studentB->grade;
}

int compareFuncID(const void* voidA, const void* voidB) {
    student* studentA = (student*) (voidA);
    student* studentB = (student*) (voidB);

    return studentA->studentId - studentB->studentId;
}

int main() {


    student studentArray[10] = {
            {87, 10001, "Fred"},
            {28, 10002, "Tom"},
            {100, 10003, "Alistair"},
            {78, 10004, "Sasha"},
            {84, 10005, "Erin"},
            {98, 10006, "Belinda"},
            {75, 10007, "Leslie"},
            {70, 10008, "Candy"},
            {81, 10009, "Aretha"},
            {68, 10010, "Veronica"}
    };

    for (auto i : studentArray)
        std::cout << i.studentId << " " << i.grade << std::endl;

    qsort(studentArray, 10, sizeof(student), compareFuncGrade);

    std::cout<< "Sorting by Grade \n\n";

    for (auto i : studentArray)
        std::cout << i.studentId << " " << i.grade << std::endl;

    std::cout<< "Sorting by Student Id\n\n";

    qsort(studentArray, 10, sizeof(student), compareFuncID);

    for (auto i : studentArray)
        std::cout << i.studentId << " " << i.grade << std::endl;

    return 1;
}