#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void printRightTriangle(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 0; j--)
            cout << '#';
        cout << "\n";
    }
}

void printSidewaysTriangle (int n = 5) {
    //for loop that peaks in middle
    int i = n * 2;

    for (int j = 1; j < i; j++) {
        for (int y = 0; y < n - abs(n - j); y++)
            cout << '#';
        cout << '\n';
    }


}



int main() {

    printSidewaysTriangle();
    return 0;
}
