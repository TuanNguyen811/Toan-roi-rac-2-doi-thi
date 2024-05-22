#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

bool chuaXet[100];
int a[100][100],n;
struct Canh
{
    int dinhDau;
    int dinhCuoi;
    int trongSo;
};
Canh danhSachCanh[100];
int soLuongCanh=0;

queue <Canh> danhSachCanhCay;
queue <Canh> danhSachCanhMaTran;
int doDaiNhoNhat=0;

void chuyenMaTranThanhDanhSachCanh(void){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][j]!=100){
                soLuongCanh++;
                danhSachCanh[soLuongCanh].dinhDau=i;
                danhSachCanh[soLuongCanh].dinhCuoi=j;
                danhSachCanh[soLuongCanh].trongSo=a[i][j];
            }
        }
    }
    cout <<"sap xep danh sach canh"<<endl;
    for(int i=1;i<soLuongCanh;i++){
        for(int j=i+1;j<=soLuongCanh;j++){
            if(danhSachCanh[i].trongSo>danhSachCanh[j].trongSo){
                swap(danhSachCanh[i],danhSachCanh[j]);
            }
        }
    }
    for(int i=1;i<=soLuongCanh;i++){
        cout <<danhSachCanh[i].dinhDau<<" "<<danhSachCanh[i].dinhCuoi<<" "<<danhSachCanh[i].trongSo<<endl;
        danhSachCanhMaTran.push(danhSachCanh[i]);
    }
}
int find(vector <int>& parent, int i){
    if(parent[i]==i){
        return i;
    }
    return parent[i]=find(parent,parent[i]);
}
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

bool kiemTraTaoTruTrinh(Canh e, vector<int>& parent) {
    int rootDinhDau = find(parent, e.dinhDau);
    int rootDinhCuoi = find(parent, e.dinhCuoi);
    return rootDinhDau == rootDinhCuoi;
}
/*
bool kiemTraTaoTruTrinh(Canh e, queue <Canh> danhSacha){
    bool dinhDau=false,dinhCuoi=false;
    queue <Canh> danhSachCopy=danhSacha;
    while (!danhSachCopy.empty()) {
        Canh a = danhSachCopy.front();
        danhSachCopy.pop();

        if (e.dinhDau == a.dinhCuoi) {
            dinhDau = true;
        }  
        if (e.dinhCuoi == a.dinhDau) {
            dinhCuoi = true;
        }
        if (dinhDau && dinhCuoi) {
            return true;
        }
    }
    return false;
}
*/

void thuatToanKusal(){
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (danhSachCanhCay.size()==n-1&&danhSachCanhMaTran.size()==0){
        Canh e=danhSachCanhMaTran.front();
        danhSachCanhMaTran.pop();
        if(!kiemTraTaoTruTrinh(e,parent)){
            danhSachCanhCay.push(e);
            doDaiNhoNhat+=e.trongSo;
            unionSets(parent, rank, e.dinhDau, e.dinhCuoi);
        }
    } 
    while (!danhSachCanhCay.empty())
    {
        Canh a=danhSachCanhCay.front();
        danhSachCanhCay.pop();
        cout <<"Cay: "<<"("<<a.dinhDau<<","<<a.dinhCuoi<<")"<<" ";
    }
    cout <<"Chi phi: "<<doDaiNhoNhat<<endl;
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
                cout <<a[i][j];
            }else{
                a[i][j]=b;
                cout <<" "<<a[i][j];
            }
        }
        cout << endl;
    }
    chuyenMaTranThanhDanhSachCanh();
    fi.close();
}
int main(){
    Init();
    thuatToanKusal();
    return 0;
}
