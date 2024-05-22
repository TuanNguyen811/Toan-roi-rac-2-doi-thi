#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int maTran[100][100];
int chuaXet[100];
int ketQua[100];
int n,i,d;

int DuongDiNhoNhat[100];
int chiPhiNhoNhat=INT_MAX;
void Init() {
    ifstream fi("duongDi.txt");
    if (!fi.is_open()) {
        cout << "Khong the mo file" << std::endl;
        return;
    }
    fi >> n;
    cout <<"Doc file: "<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fi >> maTran[i][j];
            cout << maTran[i][j] << " ";
        }
        cout <<endl;
    }
    fi.close();
}

void inKetQua(void){
    int chiphi=0;
    d++;
    cout <<"Duong di thu "<<d<<": ";
    
    for(int i=0;i<=n;i++){
        cout <<ketQua[i]<<" ";
        chiphi+=maTran[ketQua[i]][ketQua[i+1]];
    }

    if(chiphi<chiPhiNhoNhat){
        chiPhiNhoNhat=chiphi;
        for(int i=0;i<=n;i++){
            DuongDiNhoNhat[i]=ketQua[i];
        }
    }
    cout <<"chi phi: "<<chiphi <<endl;
}
void Hamilton(int ketQua[100],int chuaXet[100], int i){
    for (int j=1;j<=n;j++){
        if(maTran[ketQua[i-1]][j]>=0&&chuaXet[j]==0){
            ketQua[i]=j;
            chuaXet[j]=1;
            if(i < n){// trường hợp oke tìm được 
                Hamilton(ketQua,chuaXet,i+1);
            }else if(ketQua[i]==ketQua[0]){// trường hợp về ban đầu và i không tìm được đường nữa
                inKetQua();
            }
            chuaXet[j]=0;// trường hơpj khong có đường thì trả về o và xét j tiếtp theo
        }
    }
}
int main(){
    ketQua[0]=1;
    i=1;
    d=0;
    Init();
    Hamilton(ketQua,chuaXet,i); 
    if(d==0){
        cout <<"Khong co chu trinh"<<endl;
    }
    cout <<"=> Duong di nho nhat: ";
    for (int i=0;i<=n;i++){
        cout <<DuongDiNhoNhat[i]<<" ";
    }
    cout <<"Chi phi: "<<chiPhiNhoNhat<<endl;
    return 0;
}
