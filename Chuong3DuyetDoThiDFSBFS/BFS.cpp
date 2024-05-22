#include <iostream>
#include <fstream>

using namespace std;

class BFS {
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
    void BFS_queue(int u){
        int queue[100],low=1,high=1;
        queue[low]=u;
        chuaXet[u]=false;
        while (low<=high)
        {
            u=queue[low];
            low++;
            cout <<u<<" ";
            for (int i=1;i<=n;i++){
                if(a[u][i]&&chuaXet[i]){
                    high++;
                    queue[high]=i;
                    chuaXet[i]=false;
                }
            }
        }
    }
};

int main() {
    BFS bfs;
    bfs.Init();
    bfs.BFS_queue(3);
    return 0;
}