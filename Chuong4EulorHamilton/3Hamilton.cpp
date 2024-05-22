#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int maTran[100][100];// ma trận đương đi
int chuaXet[100];//ma trận kiêm tra
int ketQua[100];// ma trân kết quả
int n;//so dinh
int i;//??
int d;// dem 
void Init() {
    ifstream fi("maTranHamilton.txt");
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
    d++;
    cout <<"Duong di thu "<<d<<": ";
    for(int i=0;i<=n;i++){
        cout <<ketQua[i]<<" ";
    }
    cout <<endl;
}
void Hamilton(int ketQua[100],int chuaXet[100], int i){
    for (int j=1;j<=n;j++){
        if(maTran[ketQua[i-1]][j]==1&&chuaXet[j]==0){
            ketQua[i]=j;
            chuaXet[j]=1;
            if(i < n){// trường hợp oke tìm được 
                Hamilton(ketQua,chuaXet,i+1);
            }else if(ketQua[i]==ketQua[0]){// trường hợp về ban đầu và i không tìm được đường nữa
                cout <<"D:";
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
    return 0;
}
