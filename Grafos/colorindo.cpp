#include <iostream>

using namespace std;

int m[205][205];
int N, M, ans = 0;

void color (int x, int y) { 
    if (x <= 0 || x > N || y <= 0 || y > M) return;
    if (m[x][y] != 0) return;
    m[x][y] = 1;
    ans++;
    //Down
    color (x-1, y);
    // Down Left 
    color (x-1, y-1);
    // Down Right 
    color (x-1, y+1);
    // Left  
    color (x, y-1);
    // Right 
    color (x, y+1);
    // Top 
    color (x+1, y);
    // Top Left 
    color (x+1, y-1);
    // Top Right 
    color (x+1, y+1); 
}

int main () {
    int K, X, Y;
    cin >> N >> M >> X >> Y >> K;
    for (int i = 1; i <= N;i++)
        for (int j = 1; j <= M; j++)
            m[i][j] = 0; 
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        m[x][y] = 1;
    }
    color (X, Y);
    cout << ans << endl;
}
