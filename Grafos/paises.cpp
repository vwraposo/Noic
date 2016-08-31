#include <iostream>
#include <algorithm>
#define MAXN 505
#define INFINITO 999999
using namespace std;

int N, M, K;
int mapa[MAXN][MAXN];
int distancia[MAXN];
int processado[MAXN];

void Dijikstra (int S) {
    for (int i = 0; i < N; i++) {
        processado[i] = false;
        distancia[i] = INFINITO;
    }

    distancia[S] = 0;

    while (true) {
        int davez = -1;
        int menor = INFINITO;

        for (int i = 0; i < N; i++)
            if (!processado[i] && distancia[i] < menor) {
                davez = i;
                menor = distancia[i];
            }
        if (davez == -1) break; 
        processado[davez] = true;

        for (int i = 0; i < N; i++)
            distancia[i] = min (distancia[i], distancia[davez] + mapa[davez][i]);
    }
}

int main () {
    cin >> N >> M;
    while (N != 0) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) 
                mapa[i][j] = INFINITO;
        
        for (int i = 0; i < M; i++) {
            int x, y, h;
            cin >> x >> y >> h;
            x--; y--;
            if (mapa[y][x] != INFINITO) {
                mapa[x][y] = 0;
                mapa[y][x] = 0;
            }
            else 
                mapa[x][y] = h;
        }

        cin >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            Dijikstra (x);
            int dist = distancia[y];
            if (dist < INFINITO)
                cout << dist << endl;
            else 
                cout << "Nao e possivel entregar a carta" << endl;
        }
        cout << endl;
        cin >> N >> M;
    
    } 


    return 0;
}
