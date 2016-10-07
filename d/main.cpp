#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int n, m[101];

int compute(int L){  //number of correct bracket sequences of length L
    if (m[L]>-1) {return m[L];};
    long result = 0, x = 0;
    for (int i = 0; i < L; i++){
        x = compute(i);
        x *= compute(L-i-1);
        x %= 1000000000;
        result += x;
        result %= 1000000000;
    };
    if (m[L]==-1) {m[L] = result;};
    return result;
}

int main()
{
    int result=0;
    cin >> n;

    m[0] = 1;
    for (int i = 1; i < n+1; i++) {m[i] = -1;}
    cout << compute(n) << endl;
    return 0;
}
