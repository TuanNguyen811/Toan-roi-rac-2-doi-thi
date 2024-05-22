#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
/*
- Thư viện stack
khai báo: stack<int> myStack;
push: them
top: lay ra
pop: loai bo
-Thư Viện Queue
queue<int> myQueue;
pust: them
front: lay
pop:loai bo
*/

using namespace std;
int n; // số đỉnh
int a[100][100]; // ma trận kề
bool chuaXet[100]; // mảng đánh dấu đỉnh đã xét

void Init() {
    ifstream fi("maTran1.in");
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
void DFS_deQuy(int u){
    cout <<u<<" ";
    chuaXet[u]=false;
    for(int i=1;i<=n;i++){
        if(a[u][i]&&chuaXet[i]){
            chuaXet[i]==false;
            DFS_deQuy(i);
        }
    }

}
void DFS_Stack(int u){
    stack <int> st;
    st.push(u);
    chuaXet[u]=false;
    cout <<u<<" ";
    while (st.top()>0)
    {
        int s=st.top();// lay ra vi tri dau
        st.pop();// loai bo
        for(int i=1;i<=n;i++){
            if(chuaXet[i]&&a[s][i]){
                cout <<i<<" ";
                chuaXet[i]=false;
                st.push(s);
                st.push(i);
                break;
            }
        }
    }
}
int main(){
    int u;
     Init();
    cout <<"Nhap dinh bat dau: ";
     cin>>u;
    DFS_Stack(u);
    DFS_deQuy(u);

    return 0;
}
