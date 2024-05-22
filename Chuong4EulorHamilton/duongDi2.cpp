#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX_VERTICES = 100;
int maTran[MAX_VERTICES][MAX_VERTICES];
int chuaXet[MAX_VERTICES];
int ketQua[MAX_VERTICES];
int n, d;

void Init() {
    ifstream fi("duongDi.txt");
    if (!fi.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    fi >> n;
    cout << "Doc file: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fi >> maTran[i][j];
            cout << maTran[i][j] << " ";
        }
        cout << endl;
    }
    fi.close();
}

void inKetQua() {
    d++;
    cout << "Duong di thu " << d << ": ";
    for (int i = n; i >= 0; i--) {
        cout << ketQua[i] << " ";
    }
    cout << endl;
}

bool isValid(int v, int pos) {
    // Kiểm tra xem có thể di chuyển từ đỉnh pos đến v hay không
    if (!maTran[ketQua[pos]][v])
        return false;

    // Kiểm tra xem đỉnh v đã được thăm chưa
    if (chuaXet[v])
        return false;

    return true;
}

void Hamilton(int ketQua[], int pos) {
    // Khi pos đạt tới n, ta đã tìm thấy một đường đi Hamilton
    if (pos == n) {
        // Kiểm tra xem có thể quay lại đỉnh ban đầu hay không
        if (maTran[ketQua[pos]][ketQua[0]]) {
            inKetQua();
            return;
        }
    }

    for (int v = 1; v <= n; v++) {
        if (isValid(v, pos)) {
            ketQua[pos + 1] = v;
            chuaXet[v] = 1;
            Hamilton(ketQua, pos + 1);
            chuaXet[v] = 0;
        }
    }
}

int main() {
    ketQua[0] = 1;
    d = 0;
    Init();
    chuaXet[1] = 1; // Đánh dấu đỉnh ban đầu
    Hamilton(ketQua, 1);

    if (d == 0) {
        cout << "Khong co chu trinh" << endl;
    }
    return 0;
}
