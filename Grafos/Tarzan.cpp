#include <iostream>
#include <cmath>

using namespace std;

int trees[1005][2];
int id[1005];
int sz[1005];
int ans = 0;

int find (int p) {
    while (p != id[p])
        p = id[p];
    return p;
}

void unite (int p, int q) {
    int rootP = find (p);
    int rootQ = find (q);
    if (rootP == rootQ) return;
    if (sz[rootP] < sz[rootQ]) {
        id[rootP] = rootQ;
        sz[rootQ] += sz[rootP];
    }
    else {
        id[rootQ] = rootP;
        sz[rootQ] += sz[rootQ];
    } 
        
}

int distance (int x[], int y[]) {
    return ceil (sqrt (pow (x[0] - y[0], 2) + pow (x[1]-y[1],2)));
}

int main () {
    int D, N;
    cin >> N >> D;
    for (int i = 0; i < N; i++) {    
        int x, y;
        cin >> x >> y;
        trees[i][0] = x;
        trees[i][1] = y;
        id[i] = i;
        sz[i] = i;
    }
   for (int i = 0; i < N; i++)
       for (int j = i+1; j < N; j++) {
            if (distance (trees[i], trees[j]) <= D) 
                unite (i, j);
       }
    for (int i = 0; i < N; i++) {
        if (find(i) == i) ans++;
        if (ans > 1) break;
    }    
    if (ans == 1) cout << "S" << endl;
    else cout << "N" << endl;
    return 0;
}
