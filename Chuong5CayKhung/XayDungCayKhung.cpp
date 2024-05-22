#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
bool chuaXet[100];
int a[100][100],n;
int cbt[100][2],sc;
queue <int> Queue;
stack <int> Stack;

void init() {
    ifstream fi("maTran1.txt");
    if (!fi.is_open()) {
        cout << "Khong the mo file" << endl;
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
void TREE_DFS(int i){
    chuaXet[i]=false;
    if(sc == n-1){
        return;
    }
    for(int j=1;j<=n;j++){
        if(chuaXet[j]&&a[i][j]){
            sc++;
            cbt[sc][1]=i;
            cbt[sc][2]=j;
            TREE_DFS(j);
            if(sc==n-1){
                return;
            }
        }
    }
}
void TREE_DFS_Stack(int i){
    Stack.push(i);
    chuaXet[i]=false;
    while (!Stack.empty())
    {
        int s=Stack.top();
        Stack.pop();
        for (int j=1;j<=n;j++){
            if(chuaXet[j]&&a[s][j]){
                chuaXet[j]=false;
                sc++;
                Stack.push(s);
                Stack.push(j);
                cbt[sc][1]=s;
                cbt[sc][2]=j;
                break;
            }
        }
    }
}
void TREE_BFS(int i){
    Queue.push(i);
    chuaXet[i]=false;
    while (!Queue.empty()){
        int v=Queue.front();
        Queue.pop();
        for(int j=1;j<=n;j++){
            if(chuaXet[j]&&a[v][j]){
                chuaXet[j]=false;
                sc++;
                cbt[sc][1]=v;
                cbt[sc][2]=j;
                Queue.push(j);
                if(sc==n-1){
                    return;
                }
            }
        }
    }
}
void result(void){
    cout <<"Ket qua: ";
    for (int i=1;i<=sc;i++){
        cout << "(" << cbt[i][1] << "," << cbt[i][2] << ") ";
    }
    cout << endl;
    if(sc == n-1){
        cout << "Cay lien thong" << endl;
    } else {
        cout << "Khong lien thong" << endl;
    }
}
int main(){
    sc=0;
    init();
    //TREE_DFS(1);
    //TREE_BFS(1);
    TREE_DFS_Stack(1);
    result();
    return 0;
}
