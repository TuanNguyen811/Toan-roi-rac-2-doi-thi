#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int maTran[100][100],n;
bool chuaXet[100];

void init(void){
    ifstream fi("OT1.txt");
    if(!fi.is_open()){
        cout <<"khong the mo file"<<endl;
        return;
    }
    fi>>n;
    for(int i=1;i<=n;i++){
        chuaXet[i]=true;
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
            DFS_deQuy(j);
        }
    }
}
void DFS_Stack(int i){
    cout <<i<<" ";
    stack <int> ST;
    ST.pop();
}
int main(int argc, char const *argv[]){
    init();
    DFS_deQuy(1);

    return 0;
}

