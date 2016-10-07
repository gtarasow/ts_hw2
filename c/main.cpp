#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    int N, ans = 0, cur, n;

    queue<int> Q;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> cur;
        Q.push(cur);
    };

    n = 0;

    for (int j = 0; j < N; j++){
        cin >> cur;

        while (!(Q.empty()|(Q.front()>cur))) {
            n++;
            ans += Q.front()*(n%2);
            ans %= 1000000000;
            Q.pop();
        };

        n++;
        ans += cur*(n%2);
        ans %= 1000000000;
    }

     while (!(Q.empty())) {
            n++;
            ans += Q.front()*(n%2);
            ans %= 1000000000;
            Q.pop();
        };

    cout << ans << endl;

    return 0;
}


