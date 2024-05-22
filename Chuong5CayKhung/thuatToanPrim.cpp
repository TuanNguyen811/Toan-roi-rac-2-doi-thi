/*
mã giải thuật toán prim
b1(khởi tạo){
    - V2 tập đỉnh cây khung
    - V1 tập đỉnh chưa xét
    - T tập cạnh cây khung
    - d độ dài =0
}
b2:(lặp){
    while(V!=rỗng){
        tìm ra tập cạnh e có độ dài nhỏ nhất thỏa mãn điều kiện 1 đỉnh ở V1, 1 đỉnh ở V2
        d+=d(e)// tăng độ dài
        thêm e vào v2
        loại e khởi v1
    }
}
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

bool chuaXet[100];
int a[100][100], n;
struct Canh {
    int dinhDau;
    int dinhCuoi;
    int trongSo;
};
vector <int> dinhCayKhung;
queue <Canh> tapCanhCayKhung; 
int doDaiDuongDi=0;

void thuatToanPrim(int root){
    chuaXet[root]=false;
    dinhCayKhung.push_back(root);
    int min;
    while (dinhCayKhung.size()<n)
    {
        min=999;
        Canh canhCay;
        //mang các đỉnh trong cây ra tìm min
        for(int i=0;i<dinhCayKhung.size();i++){
            int t=dinhCayKhung[i];
            //duyêt xem cạnh t đến đâu thì min nhất
            for(int j=1;j<=n;j++){
                if(chuaXet[j]&&min>a[t][j]){
                    min=a[t][j];
                    canhCay.dinhDau=t;
                    canhCay.dinhCuoi=j;
                }
            }
        }
        //lúc này mình đã có cạnh có trọng số nhỏ nhất,thỏa mãn điều kiện prim
        tapCanhCayKhung.push(canhCay);
        chuaXet[canhCay.dinhCuoi]=false;
        doDaiDuongDi+=min;
        dinhCayKhung.push_back(canhCay.dinhCuoi);
    }
    cout <<"Canh cay khung: ";
    while (!tapCanhCayKhung.empty())
    {
        Canh a=tapCanhCayKhung.front();
        tapCanhCayKhung.pop();
        cout <<"("<<a.dinhDau<<","<<a.dinhCuoi<<")"<<" ";
    }
    cout <<"Chi phi: "<<doDaiDuongDi;
    cout <<endl;
}

void Init() {
    ifstream fi("maTran2.txt");
    if (!fi.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    fi >> n;
    for (int i = 1; i <= n; i++) {
        chuaXet[i] = true;
        for (int j = 1; j <= n; j++) {
            int b;
            fi>>b;
            if(b==0){
                a[i][j]=99;
                cout <<a[i][j]<<" ";
            }else{
                a[i][j]=b;
                cout <<a[i][j]<<"  ";
            }
        }
        cout << endl;
    }
    fi.close();
}
int main() {
    Init();
    thuatToanPrim(1);
    return 0;
}
