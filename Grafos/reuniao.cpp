#include <iostream>
#include <algorithm>
#define INFINITO 999999
#define  MAXN 110

using namespace std;

int N, M;
int mapa[MAXN][MAXN];
int distancia[MAXN];
int processado[MAXN];

void Dijikstra (int S) {
    // Para os ligados com a origem
    for (int i = 0; i < N; i++) {
        distancia[i] = mapa[S][i];
        processado[i] = false;
    }
    distancia[S] = 0;
    processado[S] = true;
    while (true) {
        int davez = -1;
        int menor = INFINITO;
        
        // Achando o mais proximo, que sera o proximo a ser processado
        for (int i = 0; i < N; i++) 
            if (!processado[i] && distancia[i] < menor) { 
                davez = i;
                menor = distancia[i];
            }
        
        if (davez == -1) break;

        processado[davez] = true;

        for (int i = 0; i <= N+1; i++)
            distancia[i] = min (distancia[i], distancia[davez] + mapa[davez][i]);
    }

}

int maxd (int i) {
    if (i >= N) return -1;
    return max (distancia[i], maxd(i+1));
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            mapa[i][j] = INFINITO;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mapa[u][v] = w;
        mapa[v][u] = w;
    }
    int Dmax = INFINITO;
    for (int i = 0; i < N; i++) {
        Dijikstra (i);
        Dmax = min (maxd (0), Dmax);
    }
    cout << Dmax << endl;
    return 0;
}
