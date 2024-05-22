#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;
int n;
bool chuaXet[100];
int truoc[100];
int d[100];
int tu;
struct DanhSachCanh
{
    int dinhDau;
    int dinhCuoi;
    int trongSo;
};
DanhSachCanh* danhSachCanh;

void init(void){
    ifstream file("danhSachCanh.txt");
    if(!file.is_open()){
        cerr << "Không thể mở file!" << endl;
        return;
    }
    file>>n;
    danhSachCanh=new DanhSachCanh[n+1];
    for(int i=1;i<=n;i++){
        file>>danhSachCanh[i].dinhDau;
        file>>danhSachCanh[i].dinhCuoi;
        file>>danhSachCanh[i].trongSo;
    }
    file.clear();
    cout <<"So luong dinh: "<<n<<endl;
    for(int i=1;i<=n;i++){
        cout <<danhSachCanh[i].dinhDau<<" "<<danhSachCanh[i].dinhCuoi<<" "<<danhSachCanh[i].trongSo<<endl;
    }
}

void ketQua(int tu, int den){
    int i;
    cout <<"Duong di ngan nhat tu "<<tu<<" den "<<den<<": "<<endl;
    cout <<den;
    i=truoc[den];
    while (tu!=den)
    {
        cout <<"-"<<i;
        i=truoc[i];
    }
    cout <<tu<<endl;
}
 
void thuatToan_Dijkstra(int s) {
    int danNhanMin;
    // Khởi tạo ban đầu
    for (int i = 1; i <= n; i++) {
        d[i] = danhSachCanh[i].trongSo; // Trọng số thứ i
        truoc[i] = tu;
        chuaXet[i] = false;
    }
    //khoi tao cho b1
    truoc[tu] = tu;
    d[tu] = 0;
    chuaXet[tu] = true;

    while (!chuaXet[]){
        //buoc tim dinh min de mang di xet
        int minp = 2000;
        for (int i = 1; i <= n; i++) {
            if (!chuaXet[i] && (minp > d[i])) {
                danNhanMin = i;
                minp = d[i];
            }
        }
        //mang dinh min di xet
        chuaXet[danNhanMin] = true;
        if (!chuaXet[]) {
            for (int i = 1; i <= n; i++) {
                if (!chuaXet[i] && (d[danNhanMin] + danhSachCanh[i].trongSo < d[i])) {
                    d[i] = d[danNhanMin] + danhSachCanh[i].trongSo;
                    truoc[i] = danNhanMin;
                }
            }
        }
    }
}
int main(){
    init();
    thuatToan_Dijkstra(1);
    ketQua(1);
}
