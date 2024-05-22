#include <iostream>
#include <fstream>

using namespace std;
int a[100][100],n,solt=0;
bool chuaXet[100];
void Init(void) {
    ifstream fi("maTran2.in");
    if (!fi.is_open()) {
        cout << "Khong the mo file" << std::endl;
        return;
    }
    fi >> n;
    for (int i = 1; i <= n; i++) {
        chuaXet[i] = true;
        for (int j = 1; j <= n; j++) {
            fi >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout <<endl;
    }
    fi.close();
}
void DFS(int u){
    cout <<u<<" ";
    chuaXet[u]=false;
    for (int i=1;i<=n;i++){
        if(a[u][i]&&chuaXet[i]){
            DFS(i);
        }
    }
}
int main(void){
    Init();
    for (int i=1;i<=n;i++){
        if(chuaXet[i]){
            solt++;
            cout <<"Thanh phan lien thong "<<solt<<": ";
            DFS(i);
            cout <<endl;
        }
    }
}

