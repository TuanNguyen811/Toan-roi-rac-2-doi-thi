#include <iostream>
#include <fstream>

using namespace std;
int a[100][100],n,solt=0;
bool chuaXet[100];
void Init(void) {
    ifstream fi("maTran4.in");
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
    chuaXet[u]=false;
    for (int i=1;i<=n;i++){
        if(a[u][i]&&chuaXet[i]){
            DFS(i);
        }
    }
}
void reInit(void){
    for (int i=1;i<=n;i++){
        chuaXet[i]=true;
    }
 }
bool kiemTraSoLienThong(void){
    for (int i=1;i<=n;i++){
        if (chuaXet[i]){
            return true;
        }
    }
    return false;
}
bool kiemTraLienThongManh(void){
    Init();
    for (int i=1;i<=n;i++){
        chuaXet[i]==false;
        if(i==1){
            DFS(2);
        }
        else{// kiemtra casc truong hop con lai
            DFS(1);
        }
        if(kiemTraSoLienThong()){
            return false;
        }
        reInit();
    }
    return true;
}
int main(void){

    if(kiemTraLienThongManh){
        cout <<"Lien thong manh"<<endl;
    }else{
        cout <<"Lien thong yeu"<<endl;
    }
    return 0;
}
