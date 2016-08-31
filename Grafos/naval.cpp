#include <iostream>

using namespace std;

int navios[10005];
int mapa[1005][1005];
int N, M, K;
int n = 0, ans = 0;

void dfs (int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (mapa[x][y] == -1) {
        mapa[x][y] = n;
        dfs (x-1, y);
        dfs (x+1, y);
        dfs (x, y-1);
        dfs (x, y+1);
    } 
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == '#') mapa[i][j] = -1;
            else mapa[i][j] = 0;
        }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) 
            if (mapa[i][j] == -1) {
                n++;
                dfs (i, j);
            }
    
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }*/
    cin >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        //cout << mapa[x][y] << endl;
        mapa[x][y] = - mapa[x][y];
    } 
    ans = n;
    for (int i = 0; i <= n; i++) navios[i] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (mapa[i][j] > 0 && navios[mapa[i][j]] == 0) {
                navios[mapa[i][j]] = 1;
                ans --;
            }
        }
            
    cout << ans << endl;
    return 0;
}
