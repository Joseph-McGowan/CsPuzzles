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

void printTriangle (int n) {
    for (int i = 0; i < n; i = i + 2) {
        for (int a = 0; a < i/2 ;a++)
            cout << ' ';

        for (int j = i; j < n ; ++j) {
            cout << '#';

        }
        cout << '\n';

    }
}

void printDiamond(int n) {
    for (int i = 0; i < n; i = i +2) {
        for (int a = 0 ; a < (n - i) /2; a++)
            cout << ' ';
        for (int j = 0; j <= i; ++j)
            cout << "#";
        cout << '\n';
    }


    printTriangle(n);
}


int main() {

    printTriangle(4);
    cout << '\n';
    printDiamond(7);
    return 0;
}
