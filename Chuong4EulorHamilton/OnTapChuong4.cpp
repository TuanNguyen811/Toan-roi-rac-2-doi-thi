#include <iostream>
#include <stack>
#include <fstream>
#include <queue>
using namespace std;
int maTran[100][100],n;
bool chuaXet[100];
int CE[100],nce=0;
void init(){
    ifstream fi("OnTap.txt");
    if(!fi.is_open()){
        cout <<"Khong mo duoc file"<<endl;
        return;
    }
    fi>>n;
    for (int i=1;i<=n;i++){
        chuaXet[i]=true;
        for(int j=1;j<=n;j++){
            fi>>maTran[i][j];
            cout <<maTran[i][j]<<" ";
        }
        cout <<endl;
    }
    fi.close();
}
bool kiemTraLienThong(){
    for(int i=1;i<=n;i++){
        if (chuaXet[i])
        {
            return false;
        }
    }
    return true;
}
void BFS(int i){
    queue <int> Qu;
    Qu.push(i);
    chuaXet[i]=false;
    cout <<"Duyet dinh: "<<i<<" ";
    while (!Qu.empty())
    {
        int u=Qu.front();
        Qu.pop();
        for (int j=1;j<=n;j++){
            if(chuaXet[j]&&maTran[u][j]){
                chuaXet[j]=false;
                Qu.push(j);
                cout <<j<<" ";
            }
        }
    }
    cout <<endl;
}
bool kiemTraEulor(){
    if(kiemTraLienThong()){
        cout <<"=> Lien thong"<<endl;
        for(int i=1;i<=n;i++){
            int bacRa=0;
            int bacVao=0;
            for(int j=1;j<=n;j++){
                if(maTran[i][j]){
                    bacRa++;
                }
                if(maTran[j][i]){
                    bacVao++;
                }
            }
            cout <<"deg+("<<i<<")="<<bacRa<<" | "<<"deg-("<<i<<")="<<bacVao<<"=> ";
            if(bacRa==bacVao){
                cout <<"Bang nhau"<<endl;
            }
            else{
                cout <<"Khong bang nhau"<<endl;
                return false;
            }
        }
        cout <<"=> La do thi Euler"<<endl;
        return true;
    }else{
        cout <<"Khong lien thong"<<endl;
        return false;
    }
}
void duyetEuler(int i){
    stack <int> St;
    St.push(i);
    while (!St.empty())
    {
        int u=St.top();
        int x=1;
        while (x<=n&&maTran[u][x]==0)
        {
            x++;
        }
        if(x>n){
            nce++;
            CE[nce]=u;
            St.pop();
        }
        else{
            St.push(x);
            maTran[u][x]=0;
            maTran[x][u]=0;
        }
    }
}
void ketQua(){
    cout <<"Chu trinh Euler: ";
    for (int j=nce;j>0;j--){
        cout <<CE[j]<<" ";
    }
}
int main(){
    init();
   // BFS(1);
   // kiemTraEulor();
    duyetEuler(1);
    ketQua();
    return 0;
}