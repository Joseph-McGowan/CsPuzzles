//
// Created by josep on 24/09/2024.
//

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;


struct student {
    int grade;
    int studentId;
    std::string name;
};

bool compareFuncGrade(const student& studentA, const student& studentB)
{

    return studentA.grade  < studentB.grade;
}


vector<float> quartiles(vector<student> students) {
    vector<float> results;

    float q1,q2,q3;
    //Quartiles as follows
    //2Q = Median (if array odd, middle, if even, average of middle two vals

    if (students.size() % 2 ==  0) { //if even size
        int middleIndex = students.size() / 2;
        q2 = (students[middleIndex].grade + students[middleIndex+1].grade ) / 2;

        int q1Index = students.size() / 4;
        q1 = (students[q1Index].grade + students[q1Index + 1].grade) / 2;

        int q3Index = (students.size() / 4) * 3;
        q3 = (students[q3Index].grade + students[q3Index+1].grade) / 2;

        return {q1,q2,q3};
    }

    else {
        q2 = students[(students.size() + 1) / 2].grade;
        q1 = students[(students.size() + 1 ) / 4].grade;
        q3 = students[((students.size() + 1 / 4) * 3)].grade;

        return {q1,q2,q3};

    }

}

int main() {

    vector<student> studentArray = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"},
        {19, 100011, "Joseph"}
    };

    sort(studentArray.begin(), studentArray.end(), compareFuncGrade);

    auto answer = quartiles(studentArray);

    for (auto i : answer) {
        cout << i << endl;
    }

}