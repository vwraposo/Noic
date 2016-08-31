#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int mapa[1015][1015];
int distancia[1015];
int processado[1015];
int INFINITO = 999999;

void Dijikstra (int S) {
    // Para os ligados com a origem
    for (int i = 0; i <= N+1; i++ ) distancia[i] = mapa[S][i];
    distancia[S] = 0;
    processado[S] = true;
    while (true) {
        int davez = -1;
        int menor = INFINITO;
        
        // Achando o mais proximo, que sera o proximo a ser processado
        for (int i = 0; i <= N+1; i++) 
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

int main () {
    cin >> N >> M;
    for (int i = 0; i <= N+1; i++)
        for (int j = 0; j <= N+1; j++)
            mapa[i][j] = INFINITO;

    for (int i = 0; i < M; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        mapa[s][t] = b;
        mapa[t][s] = b;
    }
    
    Dijikstra (0);
    cout << distancia[N+1] << endl;
}
