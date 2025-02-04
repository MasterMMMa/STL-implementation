#include <iostream>
using namespace std;

int main() {
    // 1. ??????
    int* p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    // ?????
    cout << "Original array: ";
    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    // 2. ???? - ??????
    cout << "Value at p: " << *p << endl;         // 1
    cout << "Value at p+1: " << *(p + 1) << endl;   // 2
    cout << "Value at p+2: " << *(p + 2) << endl;   // 3

    // 3. ????? vs ????
    cout << "p[1] = " << p[1] << endl;        // 2
    cout << "*(p+1) = " << *(p + 1) << endl;    // 2

    // 4. ??????????????
    int* q = p;  // ??????
    q = q + 1;   // ????
    cout << "First element through moved pointer: " << q[0] << endl;  // 2
    cout << "Second element through moved pointer: " << q[1] << endl; // 3

    // 5. ????????
    delete[] p;  // ?????????p???????q

    return 0;
}