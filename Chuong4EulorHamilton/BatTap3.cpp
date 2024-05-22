#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int n; // số đỉnh
int a[100][100]; // ma trận kề
bool chuaXet[100]; // mảng đánh dấu đỉnh đã xét
void Init() {
    ifstream fi("baiTap3.txt");
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
void DFS_DeQuy(int u){
    chuaXet[u]=false;
    cout <<u<<" ";
    for(int i=1;i<=n;i++){
        if(chuaXet[i]&&a[u][i]){
            chuaXet[i]=false;
            DFS_DeQuy(i);
        }
    }
}
bool kiemTraLienThong(){
    for(int i=1;i<=n;i++){
        if(chuaXet[i]){
            return false;
        }
    }
    return true;
}
int kiemTraBac(int u){
    int tongBac=0;
    for (int i=1;i<=n;i++){
        if(a[u][i]==1){
            tongBac++;
        }
    }
    return tongBac;
}


bool kiemTraEulorCoHuong(){
    Init();
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(a[i][j]==1){
                a[i][j]=1;
                a[j][i]=1;
            }
        }
    }
    cout <<"\nChuyen thanh ma tran vo huong: "<<endl;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout <<a[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<"Duyen DFS: ";
    DFS_DeQuy(1);
    if(kiemTraLienThong()){
        cout <<"=> Do thi LIEN THONG"<<endl;
        Init();
        for(int i=1;i<=n;i++){
            int bacRa=0, bacVao=0;
            for (int j=1;j<=n;j++){
                if(a[i][j]==1){
                    bacRa++;
                }
            }
            for (int j=1;j<=n;j++){
                if(a[j][i]==1){
                    bacVao++;
                }
            }
            cout <<"deg+"<<"("<<i<<")="<<bacRa;
            cout <<" |deg-"<<"("<<i<<")="<<bacVao<<endl;
            if(bacRa!=bacVao){
                cout <<"Khong bang, ";
                cout <<"Khong phai euler"<<endl;
                return false;
            }
        }
            cout <<"=>la do thi EULER"<<endl;
        return true;
    }else{
        cout <<"Do thi khong lien thong"<<endl;
        cout <<"Khong phai Euler "<<endl;
        return false;
    }
}

void chuTrinhEuler(int u){
    Init();
    stack <int> ST;//
    int CE[100];// đựng các trường hợp không đi được đâu nữa
    ST.push(u);// cho u vào st
    int dCE=0;
    do
    {
        // lấy đỉnh ở đầu ngăn xếp
        int v=ST.top();// lấy đỉnh ra đi kiểm tra
        int x=1;
        while (x<=n&&a[v][x]==0)// chạy đến vị trí bằng 1,
        {
            x++;// chay đến hàng v cột có số 1;
        }
        //cout <<"x chay den"<<x<<endl;
        // 2 trương hợp x còn đi được, x không đi được
        // - x còn đi được thì đưa vào st, sau đó xóa đường
        //- x không đi được thì, cho x vào CE, cho st quay về 1 vị trí để xét tiếp
        if(x>n){
            //cout <<"- Truong hop x>n, khong con di dau duoc nua"<<endl;
            dCE++;
            CE[dCE]=v;
            //cout <<"cho v="<<v<<" vao CE va bo no ra khoi ST"<<endl;
            ST.pop();

            // có đoạn cuối không còn đi được đường nào nưã thì ST sẽ chuyển hết vào CE;
        }else{
            //cout <<"- Truong hop x<n, di toi x, cho x vao ST"<<endl;
            ST.push(x);
            //cout <<"xoa canh("<<v<<","<<x<<") va nguoc laio"<<endl;
            a[v][x]=0;
            a[x][v]=0;
        }
    } while (!ST.empty());
    cout <<"Chu Trinh Euler( "<<u<<"): ";
    for (int i=dCE;i>=0;i--){
        cout <<CE[i]<<" ";
    }    
    cout <<endl;
}
void chuTrinhEuler2(int u){
    Init();
    cout <<"Phan tich chu Trinh Euler("<<u<<"): "<<endl;
    stack <int> ST;//
    int CE[100];// đựng các trường hợp không đi được đâu nữa
    ST.push(u);// cho u vào st
    int dCE=0;
    int b=1;
    do
    {
        cout <<"===Buoc: "<<b<<"====\n";
        b++;
        // lấy đỉnh ở đầu ngăn xếp
        int v=ST.top();// lấy đỉnh ra đi kiểm tra
        int x=1;
        while (x<=n&&a[v][x]==0)// chạy đến vị trí bằng 1,
        {
            x++;// chay đến hàng v cột có số 1;
        }
        cout <<"x chay den "<<x<<endl;
        // 2 trương hợp x còn đi được, x không đi được
        // - x còn đi được thì đưa vào st, sau đó xóa đường
        //- x không đi được thì, cho x vào CE, cho st quay về 1 vị trí để xét tiếp
        if(x>n){
            cout <<"-Truong hop x>n"<<endl;
            dCE++;
            CE[dCE]=v;
            cout <<"cho v="<<v<<" vao CE va lay ra khoi stack"<<endl;
            ST.pop();
            // có đoạn cuối không còn đi được đường nào nưã thì ST sẽ chuyển hết vào CE;
        }else{
            cout <<"-Truong hop x<n, cho x vao stack"<<endl;
            ST.push(x);
            cout <<"xoa canh("<<v<<","<<x<<") va "<<"canh("<<v<<","<<x<<")"<<endl;
            a[v][x]=0;
            a[x][v]=0;
        }
    } while (!ST.empty());
    cout <<"Chu Trinh Euler("<<u<<"): ";
    for (int i=dCE;i>=0;i--){
        cout <<CE[i]<<" ";
    }    
    cout <<endl;
}


bool kiemTraNuaEulorCoHuong(){
    Init();
    cout <<"Duyet Do thi: ";
    DFS_DeQuy(1);
    cout <<endl;
    if(kiemTraLienThong()){
        cout <<"Do thi lien thong"<<endl;
        int bacLe=0;
        for (int i=1;i<=n;i++){
            int bacRa=0,bacVao=0;
            for (int j=1;j<=n;j++){
                if(a[i][j]==1){
                    bacRa++;
                }                
            }
            for (int j=1;j<=n;j++){
                if(a[j][i]==1){
                    bacVao++;
                }
            }
            cout <<"deg+("<<i<<")="<<bacRa<<" | "<<"deg-("<<i<<")="<<bacVao<<endl;
            if(bacRa==bacVao){
                if(bacRa%2!=0){
                    bacLe++;
                }
            }else{
                cout <<"Khong bang"<<endl;
                cout <<"=> khong Nua Euler"<<endl;
                return false;
            }
        }
        cout <<"Bac le ="<<bacLe<<endl;
        if(bacLe==2||bacLe==0){
            cout <<"=>Nua Euler"<<endl;
            return true;
        }else{
            cout <<"Khong phai nua Euler"<<endl;
            return false;
        }
    }else{
        cout <<"Do thi khong lien thong"<<endl;
        cout <<"Khong phai nua Euler"<<endl;
        return false;
    }
}



void duongDiEuler(){
    Init();
    // tim đầu vào

        // có hướng deg+ - deg-=1
        cout <<"Do thi co huong "<<endl;
        for (int i=1;i<=n;i++){
            int bacCong=0, bacTru=0;
            for (int j=1;j<=n;j++){
                if (a[i][j]==1){
                    bacCong++;
                }
            }
            for (int j=1;j<=n;j++){
                if (a[j][i]==1){
                    bacTru++;
                }
            }
            if((bacCong-bacTru)==1){
                cout <<"deg+("<<i<<")="<<bacCong<<" | deg-("<<i<<")="<<bacTru<<"=1"<<endl;
                chuTrinhEuler(i);
            }
        }

}
int main(){
    int luaChon;
    Init();
    do
    {
        cout <<"1. Kiem tra do thi Euler tu dong\n";
        cout <<"2. Tim chu trinh Euler\n";
        cout <<"3. Chu trinh Euler chi tiet\n";
        cout <<"4.  Euler\n";
        cin>>luaChon;
        switch (luaChon)
        {
        case 1:{
            kiemTraEulorCoHuong();
            break;
        }
        case 2:{
            chuTrinhEuler(1);
            break;
        }
        case 3:{
            chuTrinhEuler2(5);
            break;
        }
        case 4:{
            int dinh;
            cout <<"Nhap so dinh: ";
            cin >>dinh;
            chuTrinhEuler(dinh);
        }
        default:
            break;
        }

    } while (luaChon!=0);
    return 0;
}