#include <iostream>
#include <fstream>

using namespace std;

class DFS {
private:
    int n; // số đỉnh
    int a[100][100]; // ma trận kề
    bool chuaXet[100]; // mảng đánh dấu đỉnh đã xét
public:
    void Init() {
        ifstream fi("maTran.in");
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
    void DFS_Dequi(int u){
        chuaXet[u]=false;
        cout <<u<<" ";
        for (int i=1;i<=n;i++){
            if(a[u][i]&&chuaXet[i]){
                DFS_Dequi(i);
            }
        }
    }
    void DFS_Stack(int u){
        int Stack[100], dau=1;
        Stack[dau]=u;
        chuaXet[u]=false;
        cout <<u<<" ";
        while (dau>=0)
        {
            int s=Stack[dau];
            dau--;
            for (int i=1;i<=n;i++){
                if (chuaXet[i]&&a[s][i]){
                    cout <<i<<" ";
                    chuaXet[i]=false;
                    Stack[++dau]=s;
                    Stack[++dau]=i;
                    break;
                }
            }
        }
    }
};

int main() {
    DFS dfs;
    dfs.Init();
    dfs.DFS_Dequi(3);
    cout <<endl;
    //dfs.DFS_Stack(3);
    return 0;
}