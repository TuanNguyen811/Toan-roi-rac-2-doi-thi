#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n,soluong;
bool chuaXet[100];

void Init(void) {
    ifstream fi("maTran5.in");
    if (!fi.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    fi >> n;
    for (int i = 1; i <= n; i++) {
        chuaXet[i] = true;
        for (int j = 1; j <= n; j++) {
            fi >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    fi.close();
}

void DFS(int u) {
    chuaXet[u] = false;
    for (int i = 1; i <= n; i++) {
        if (a[u][i] && chuaXet[i]) {
            soluong++;// đếm số lượng 
            DFS(i);
        }
    }
}
//
bool kiemTraLienThong(void) {
   for (int i = 1; i < soluong; i++) {
        if (chuaXet[i]) {
            return false;
        }
    }
    return true;
}

void datLaiChuaXet(void) {
    soluong=0;
    for (int i = 1; i <= n; i++) {
        chuaXet[i] = true;
    }
}
bool duyetDinhTru(int u){
    datLaiChuaXet();
    chuaXet[u]=false;
    DFS(u);
    if(kiemTraLienThong()){
        return true;
    }
    else return false;
}

int main(void) {
    Init();
    for (int i = 1; i <= n; i++) {
        if (duyetDinhTru(i)) {
            cout << "dinh " << i << " la dinh tru" << endl;
        }
    }
    return 0;
}
