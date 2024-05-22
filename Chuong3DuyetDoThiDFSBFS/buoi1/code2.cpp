#include <stdio.h>
#include <stdbool.h>

#define MAX 50

int A[MAX][MAX], n, truoc[MAX], s, t;
void Init(void) {
    int i, j;
    FILE *fp;
    fp = fopen("dothi.in", "r");
    fscanf(fp, "%d", &n);
    printf("\n So dinh do thi: %d", n);
    for (i = 1; i <= n; i++) {
        printf("\n");
        truoc[i] = 0;
        for (j = 1; j <= n; j++) {
            fscanf(fp, "%d", &A[i][j]);
            printf("%3d", A[i][j]);
        }
    }
    fclose(fp);
}

void DFS(int u) {
    int v;
    printf("%3d", u);
    for (v = 1; v <= n; v++) {
        if (A[u][v] && !truoc[v]) {
            truoc[v] = u;
            DFS(v);
        }
    }
}

void Duongdi(void) {
    if (truoc[t] == 0) {
        printf("\n Khong ton tai duong di");
        return;
    }
    printf("\n Duong di:");
    int j = t;
    printf("%3d<= ", j);
    while (truoc[j] != s) {
        printf("%3d<= ", truoc[j]);
        j = truoc[j];
    }
    printf("%3d", s);
}

int main(void) {
    Init();
    printf("\n Dinh dau:");
    scanf("%d", &s);
    printf("\n Dinh cuoi:");
    scanf("%d", &t);
    DFS(s); // Or you can use BFS(s) instead
    Duongdi();
    return 0;
}
