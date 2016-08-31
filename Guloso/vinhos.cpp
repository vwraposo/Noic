#include <iostream>
#include <stdlib.h>
#define MAXN 100005

using namespace std;

int N;
int houses[MAXN];
long long work;
int pos, neg;

int main () {
    cin >> N;
    while (N > 0) {
        work = pos = neg = 0;
        for (int i = 0; i < N; i++) 
            cin >> houses[i];
        while (pos < N && neg < N) {
            while (pos < N && houses[pos] <= 0) pos++;
            while (neg < N && houses[neg] >= 0) neg++;
            int diff = houses[pos] + houses[neg];
            int w;
            if (diff < 0) {
                w = houses[pos];
                houses[pos] = 0;
                houses[neg] = diff;
            }
            else {
                w = -houses[neg];
                houses[neg] = 0;
                houses[pos] = diff;
            }
            diff = pos - neg;
            work += abs(w*diff);
        }
        cout << work << endl;
        cin >> N;
    }

    return 0;
}
