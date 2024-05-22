#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int maTran[100][100],n;
bool chuaXet[100];
int truoc[100];

void init(void){
    ifstream fi("maTran1.txt");
    if(!fi.is_open()){
        cout <<"khong the mo file"<<endl;
        return;
    }
    fi>>n;
    for(int i=1;i<=n;i++){
        chuaXet[i]=true;
        truoc[i]=0;
        for(int j=1;j<=n;j++){
            fi>>maTran[i][j];
            cout <<maTran[i][j]<<" ";
        }
        cout <<endl;
    }
    fi.close();
}

void DFS_deQuy(int i){
    cout <<i<<" ";
    chuaXet[i]=false;
    for (int j=1;j<=n;j++){
        if (chuaXet[j]&&maTran[i][j]){
            truoc[j]=i;
            DFS_deQuy(j);
        }
    }
}
void DFS_Stack(int i){
    cout <<i<<" ";
    stack <int> st;
    chuaXet[i]=false;
    st.push(i);
    while (!st.empty())
    {
        int u=st.top();
        st.pop();
        for(int j=1;j<=n;j++){
            if(chuaXet[j]&&maTran[u][j]){
                st.push(u);
                st.push(j);
                truoc[j]=u;
                chuaXet[j]=false;
                cout <<j<<" ";
                break;
            }
        }
    }
}

void BFS(int i){
    queue <int>qu;
    qu.push(i);
    chuaXet[i]=false;
    while (!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        cout <<u<<" ";
        for(int j=1;j<=n;j++){
            if(chuaXet[j]&&maTran[u][j]){
                qu.push(j);
                truoc[j]=u;
                chuaXet[j]=false;
            }
        }
    }
}
void soThanhPhanLienThong(void){
    cout <<"So thanh phan lien thong: "<<endl;
    int soluong=0;
    for (int i = 1; i <=n; i++)
    {
        if(chuaXet[i]){
            soluong++;
            cout <<"Thanh phan lien thong thu: "<<soluong<<": ";
            DFS_deQuy(i);
            cout <<endl;
        }
    }   
}
void timDuongDi(int tu, int den){
    cout <<"duyet dinh: ";
    BFS(tu);
    cout <<endl;
    if(truoc[den]==0){
        cout <<"khong co duong di"<<endl;
        return;
    }
    cout <<"Duong di: ";
    int i=den;
    cout<<den<<" ";
    while (truoc[i]!=tu)
    {
        cout << truoc[i]<<"<-";
        i=truoc[i];
    }
    cout<<"<-"<<tu<<endl;
}
bool kiemTraLienThong(){
    for(int i=1;i<=n;i++){
        if(chuaXet[i]==true){
            return false;
        }
    }
    return true;
}
void khoiPhuc(){
    for(int i=1;i<=n;i++){
        chuaXet[i]=true;
    }
}
void kiemTraLienThongMang(){
    cout <<"Kiem tra lien thong: "<<endl;
    for(int i=1;i<=n;i++){
        cout <<i<<": ";
        DFS_deQuy(i);
        if(kiemTraLienThong()==true){
            cout <<" Lien thong"<<endl;
        }else{
            cout <<" Khong lien thong"<<endl;
        }
        khoiPhuc();
    } 
}
int soThanhPhanLienThong2(void){
    int soluong=0;
    for (int i = 1; i <=n; i++)
    {
        if(chuaXet[i]){


            soluong++;
        }
    } 
    return soluong;  
}
void duyetDinhTru(){
    for(int i=1;i<=n;i++){
        chuaXet[i]=false;// cam duyet qua
        if(i==1){
            DFS_deQuy(2);
        }else{
            DFS_deQuy(1);
        }
        // kiem tra so thanh phan lien thong
    }

}

int main(int argc, char const *argv[]){
    init();
    //DFS_deQuy(1);
    //DFS_Stack(1);
    BFS(1);
    //soThanhPhanLienThong();
    //timDuongDi(1,13);
    //kiemTraLienThongMang();

    return 0;
}

