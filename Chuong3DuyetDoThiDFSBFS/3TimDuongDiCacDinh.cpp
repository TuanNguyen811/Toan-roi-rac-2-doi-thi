#include <iostream>
#include <fstream>
using namespace std;

int a[100][100],n,truoc[100];
bool chuaXet[100];
void Init(void) {
    ifstream fi("maTran3.in");
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
//su dung thuat toan dfs
void DFS(int u){
    chuaXet[u]=false;
    for (int i=1;i<=n;i++){
        if(a[u][i]&&chuaXet[i]){
            truoc[i]=u;
            DFS(i);
        }
    }
}
void BFS(int u){
    int Queue[100],low=1,hight=1;
    Queue[low]=u;
    chuaXet[u]=false;
    while (low<=hight)
    {
        int u=Queue[low];
        low++;
        for (int i=1;i<=n;i++){
            if(a[u][i]&&chuaXet[i]){
                hight++;
                Queue[hight]=i;
                chuaXet[i]=false;
                truoc[i]=u;
            }
        }
    }
}
void duongDi(int dau, int cuoi){
    if(truoc[cuoi]==0){
        cout <<"Khong co duong di"<<endl;
        return;
    }
    cout <<"Duong di: "<<cuoi<<"->";
    int j=cuoi;
    while (truoc[j]!=dau)
    {
        cout <<truoc[j]<<"->";
        j=truoc[j];
    }
    cout <<dau<<endl;
}
void chuyen(){
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (a[i][j]==1){
                cout <<i<<" "<<j<<endl;
            }
        }
        cout <<endl;
    }
}
int main(){
    Init();
    int dau, cuoi;
    chuyen();
    cout <<"Dinh dau: ";
    cin>>dau;
    cout <<"Dinh cuoi: ";
    cin>>cuoi;

    DFS(dau);
    //BFS(dau);
    
    duongDi(dau,cuoi);
}


