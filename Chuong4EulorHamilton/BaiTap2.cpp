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
    ifstream fi("baiTap2.txt");
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

bool chungMinhEulerVoHuong(){
    Init();
    cout <<"DFS(1)=";
    DFS_DeQuy(1);
    if(!kiemTraLienThong()){
        cout <<"KHONG LIEN THONG"<<endl;
        cout <<"Khong phai euler"<<endl;
        return false;
    }else{
        cout <<"LIEN THONG"<<endl;
        for (int i=1;i<=n;i++){
            cout <<"Deg("<<i<<")"<<"="<<kiemTraBac(i);
            if(kiemTraBac(i)%2==0){// xem bấc có chẵn không
                cout <<" Chan"<<endl;
            }else{
                cout <<" Le"<<endl;
                cout <<"Khong phai EULER"<<endl;
                return false;
            }
        }
    }
    cout <<"=> EULER"<<endl;
    return true;
}
bool kiemTraEulorVoHuong(){
    Init();
    DFS_DeQuy(1);
    if(!kiemTraLienThong()){
        return false;
    }else{
        for (int i=1;i<=n;i++){
            if(kiemTraBac(i)%2==0){
            }else{
                return false;
            }
        }
    }
    return true;
}

void chuTrinhEuler(int u){
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
    cout <<"Chu Trinh Euler("<<u<<"): ";
    for (int i=dCE;i>=0;i--){
        cout <<CE[i]<<" ";
    }    
    cout <<endl;
}

bool kiemTraDoThiVoHuong(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(a[i][j]!=a[j][i]){
                return false;
            }
        }
    }
    return true;
}

bool kiemTraNuaEulorVoHuong(){
    Init();
    cout <<"Duyet Do thi DFS(1): ";
    DFS_DeQuy(1);
    if(kiemTraLienThong()){
        cout <<"=> Do Thi LIEN THONG"<<endl;
        int soDinhLe=0;
        for (int i=1;i<=n;i++){
            int soDinh=0;
            for(int j=1;j<=n;j++){
                if(a[i][j]==1){
                    soDinh++;
                }
            }
            if(soDinh%2!=0){
                cout <<"deg("<<i<<")="<<soDinh<<" Dinh LE"<<endl;
                soDinhLe++;
            }else{
                cout <<"deg("<<i<<")="<<soDinh<<endl;
            }
        }
        cout <<"So dinh le="<<soDinhLe<<endl;
        if(soDinhLe==2||soDinhLe==0){
            cout <<"=>nua EULER"<<endl;
            return true;
        }
        else{
            cout <<"Khong phai nu euler"<<endl;
            return false;
        }
    }else{
        cout <<"Do thi khong lien thong"<<endl;
        cout <<"Khong phai nua Euler"<<endl;
        return false;
    }
}

void chuTrinhEuler2(int u){
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

void duongDiEuler(){
    Init();
    // tim đầu vào
    // vô hương thì bậc lẻ đầu tiên
    int bacLeDauTien=1;
    for(int i=1;i<=n;i++){
        int bac=0;
        for (int j=1;j<=n;j++){
            if(a[i][j]==1){
                bac++;
            }
        }
        cout <<"deg("<<i<<")="<<bac<<endl;
        if(bac%2!=0){
            cout <<"Bac le dau tien: "<<i<<endl;
            bacLeDauTien=i;
            break;
        }
    }
    chuTrinhEuler(bacLeDauTien);
    return;
}
void duongDiEuler2(){
    Init();
    // tim đầu vào
    // vô hương thì bậc lẻ đầu tiên
    int bacLeDauTien=1;
    for(int i=1;i<=n;i++){
        int bac=0;
        for (int j=1;j<=n;j++){
            if(a[i][j]==1){
                bac++;
            }
        }
        cout <<"deg("<<i<<")="<<bac<<endl;
        if(bac%2!=0){
            cout <<"Bac le dau tien: "<<i<<endl;
            bacLeDauTien=i;
            break;
        }
    }
    chuTrinhEuler2(bacLeDauTien);
    return;
}

int main(){
    int luaChon;
    Init();
    do
    {
        cout <<"1. Chung minh nua Euler\n";
        cout <<"2. Tim Duong Di Euler\n";
        cout <<"3. Tim Duong Di Euler Chi tiet\n";
        cout <<"4. Duong di Euler\n";
        cin>>luaChon;
        switch (luaChon)
        {
        case 1:{
            kiemTraNuaEulorVoHuong();
            break;
        }
        case 2:{
            duongDiEuler();
            break;
        }
        case 3:{
            duongDiEuler2();
            break;
        }
        default:
            break;
        }

    } while (luaChon!=0);
    return 0;
}