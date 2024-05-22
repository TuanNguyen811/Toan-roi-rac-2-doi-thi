#include <stdio.h>
#include<iostream>

#define MAX 30
#define TRUE 1
#define FALSE 0
using namespace std;
int A[MAX][MAX], n, chuaXet[MAX];
int solt = 0;

void Init(void) {
    int i, j;
    FILE *fi;
    fi = fopen("dothi.in", "r");
    fscanf(fi, "%d", &n);
    printf("\n So dinh do thi=%d", n);
    cout << endl;
    for (i = 0; i < n; i++) {
        chuaXet[i] = TRUE;
        for (j = 0; j < n; j++) {
            fscanf(fi, "%d", &A[i][j]);
            printf("%3d", A[i][j]);
        }
        printf("\n");
    }
}

void BFS(int u) {
    int queue[MAX], low = 0, high = 0;
    int s, t, i;
    chuaXet[u] = FALSE;
    s = queue[high++] = u;
    printf("%3d ", s);
    while (low < high) {
        s = queue[low++];
        for (t = 0; t < n; t++){
            if (A[s][t] && chuaXet[t]) {
                queue[high++] = t;
                chuaXet[t] = FALSE;
                printf("%3d ", t);
            }
        }
    }
}

void DFS(int u) {
    int v, t;
    printf("%3d ", u);
    chuaXet[u] = FALSE;
    for (v = 0; v < n; v++){
        if (A[u][v] && chuaXet[v]){
            DFS(v);
        }
    }
}

int main(void) {
    int u, v;
    Init();
    for (u = 0; u < n; u++){
        if (chuaXet[u]) {
            solt++;
            BFS(u);
            DFS(u);
        }
    }
    printf("\n So lien thong %d:", solt);
    return 0;
}
