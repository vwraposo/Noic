#include<iostream>

using namespace std;

int grid[105][105], N, M;

void dfs (int x, int y, int id) {
    if (x < 0 || y < 0 || x >= N || y >= M) return;
    if (grid[x][y] == -1) {
        grid[x][y] = id;
        dfs (x-1, y, id);
        dfs (x-1, y-1, id);
        dfs (x-1, y+1, id);
        dfs (x+1, y, id);
        dfs (x+1, y-1, id);
        dfs (x+1, y+1, id);
        dfs (x, y-1, id);
        dfs (x, y+1, id);
    }
}

int main () {
    cin >> N >> M;
    while (M != 0) {
        int id = 0;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) {
                char c;
                cin >> c;
                if (c == '*') grid[i][j] = 0;
                else grid[i][j] = -1;
            }
            
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++)
                if (grid[i][j] == -1) {
                    dfs (i, j, id);
                    id++;
                }
        cout << id << endl;
        cin >> N >> M;
    }
}
