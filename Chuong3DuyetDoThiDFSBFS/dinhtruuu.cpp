#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n;
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
            DFS(i);
        }
    }
}

bool kiemTraLienThong(void) {
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (chuaXet[i]) {
            dem++;
            DFS(i);
        }
    }
    return dem > 1; 
    // Nếu có nhiều hơn 1 thành phần liên thông, trả về true
}

bool duyetDinhTru(int u){
    chuaXet[u] = false;
    bool kq = kiemTraLienThong();
    chuaXet[u] = true; 
    // Phục hồi lại trạng thái ban đầu
    return kq;
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
