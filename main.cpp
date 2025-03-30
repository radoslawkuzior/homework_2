#include <iostream>
#include "class.h"


using namespace std;

int main() {

    Time t1(200);
    cout << t1 << endl; // displays 03m:20s
    Time t2;
    cin >> t2; // user enters 10h:12m:01s

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521

    return 0;
}
