//
// Created by joseph on 23/09/2024.
//
#include "iostream"
#include "random"
#include "string"
#include "unordered_set"

using namespace std;


string randomEncrypt(string pt) {

    //generate random sequence of letters to be subsituted
    vector<char>subChart;
    string encrypted;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(65, 90);

    unordered_set<int> usedNumbers;
    int randomVal;

    for (int i = 0; i < 26; ++i) {
        do
            randomVal = distr(gen);
        while (usedNumbers.count(randomVal));

        usedNumbers.insert(randomVal);
        subChart.emplace_back(randomVal);
    }

    // Encryption

    int i = 0;
    while (pt[i] != 0) {
        if (pt[i] == 32) {
            encrypted.push_back(32);
            i++;
            continue; //do nothing to spaces

        }

        int alteredChar = toupper(pt[i]);
        alteredChar -= 65;
        encrypted.push_back(subChart[alteredChar]);

        i++;
    }

    return encrypted;

}


int main() {

    string plainText = "This is a test";
    string encryptedText = randomEncrypt(plainText);

    cout << encryptedText;



}