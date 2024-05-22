#include <iostream>
#include <fstream>
int n;
int s,t;//vị trí từ, đến
int truoc[100],maTran[100][100];
int d[100];//đây là giá trị đường đi đến mỗi đỉnh từ s
bool chuaXet[100];

using namespace std;

void init(){
    fstream fi("maTran1.txt");
    if(!fi.is_open()){
        cout <<"Khong mo duoc file"<<endl;
        return;
    }
    fi>>n;
    for(int i=1;i<=n;i++){
        chuaXet[i]=true;
        for(int j=1;j<=n;j++){
            int c;
            fi>>c;
            if(c==0){
                maTran[i][j]=88;
                cout <<maTran[i][j]<<" ";
            }
            else{
               maTran[i][j]=c;
               cout <<maTran[i][j]<<" ";
               cout <<" ";
            }
        }
        cout <<endl;
    }
    fi.close();
}
void dijkstra(void){
    int nhanDinhMin;//Nhán tam thoi đỉnh đó là min, để mang đi tìm đường tiếp
    int dminp;//nhán giá trị min
    cout <<"Nhap dung di tu: ";
    cin>>s;
    cout <<"Den: ";
    cin>>t;
    //Khởi tạo ban đầu cho các đỉnh
    for(int i=1;i<=n;i++){
        d[i]=maTran[s][i];
        truoc[i]=s;
        chuaXet[i]=false;
    }
    truoc[s]=0;
    d[s]=0;
    chuaXet[s]=true;
    //đây là các bước xét cho đến khi tìm được đính nhé
    while (!chuaXet[t])
    {
        dminp =999;//đặt để tìm min;
        //bước tìm đỉnh min hiện tại mà chưa xét
        for(int i=1;i<=n;i++){
            if(!chuaXet[i]&&d[i]<dminp){
                //gán các giá trị vào nhán
                dminp=d[i];
                nhanDinhMin=i;
            }
        }
        chuaXet[nhanDinhMin]=true;
        //giờ đã có nhãn đỉnh min rồi, giờ mang đi xét xem nó đi đến đâu màn min được nữa
        if(!chuaXet[t]){//biết đâu nhán min đó là đỉnh cần tìm
            for(int i=1;i<=n;i++){
                //duyết để tìm, nếu đi từ nhan min mà nhỏ hơn đường cũ thì gán cho nó nhé
                if(!chuaXet[i]&&(d[nhanDinhMin]+maTran[nhanDinhMin][i]<d[i])){
                    d[i]=d[nhanDinhMin]+maTran[nhanDinhMin][i];
                    truoc[i]=nhanDinhMin;
                }
            }
        }
    }
    //ở thuật toán này mình chỉ tìm từ 1 s đến t là dùng
    //nhưng có thể nâng cấp là xét hết mới dùng cũng được nhé
}
void result(void){
    cout <<"Duong di ngan nhat tu "<<s<<" den "<<t<<": "<<t;
    int i=truoc[t];
    while (i!=s)
    {
        cout <<"<-"<<i;
        i=truoc[i];
    }
    cout <<"<-"<<s<<endl;
    cout <<"Do dai: "<<d[t];
}
int main(){
    init();
    dijkstra();
    result();
    return 0;
}
