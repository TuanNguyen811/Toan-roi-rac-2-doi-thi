#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
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
int truoc[100];
int soLienThong;
vector<vector<int>> danhSachKe(n + 1);
vector <int> luuDuongDi;
void khoiPhuc(){
    for(int i=1;i<=n;i++){
        chuaXet[i]=true;
    }
}
bool lienThongManh(){
    for(int i=1;i<=n;i++){
        if(chuaXet[i]){
            return false;
        }
    }
    return true;
}
void Init() {
    ifstream fi("maTran222.in");
    if (!fi.is_open()) {
        cout <<"Khong mo file (Doc danh sach ke)";
        a[100][100] = {0}; // Ma tran ke
        for (int i = 1; i <= n; ++i) {
            for (int v : danhSachKe[i]) {
                a[i][v] = 1;
                a[v][i] = 1; // Neu do thi vo huong
            }
        }
        // In ma tran ke
        cout << "\nMa tran ke:\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
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
}
void nhapDanhSachKe(){
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    vector<vector<int>> danhSachKe(n + 1);
    cout << "Nhap danh sach ke:\n";
    for (int i = 1; i <= n; ++i) {
        int m;
        cout << "Nhap so dinh ke voi dinh " << i << ": ";
        cin >> m;
        cout << "Nhap cac dinh ke voi dinh " << i << ": ";
        for (int j = 0; j < m; ++j) {
            int v;
            cin >> v;
            danhSachKe[i].push_back(v);
        }
    }
    a[100][100] = {0}; // Ma tran ke
    for (int i = 1; i <= n; ++i) {
        for (int v : danhSachKe[i]) {
            a[i][v] = 1;
            a[v][i] = 1; // Neu do thi vo huong
        }
    }
    // In ma tran ke
    cout << "\nMa tran ke:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void DFS_deQuy(int u){
    cout <<u<<" ";
    chuaXet[u]=false;
    for(int i=1;i<=n;i++){
        if(a[u][i]&&chuaXet[i]){
            truoc[i]=u;// su dung de tim duong
            chuaXet[i]==false;
            luuDuongDi.push_back(i);
            DFS_deQuy(i);
        }
    }
}
void DFS(int u){
    chuaXet[u]=false;
    for(int i=1;i<=n;i++){
        if(a[u][i]&&chuaXet[i]){
            truoc[i]=u;// su dung de tim duong
            chuaXet[i]==false;
            luuDuongDi.push_back(i);
            DFS(i);
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
        st.pop();// lay ra roi di kiem tra
        for(int i=1;i<=n;i++){
            if(chuaXet[i]&&a[s][i]){
                cout <<i<<" ";
                chuaXet[i]=false;
                st.push(s);// đưa vào nếu thoả mãn
                st.push(i);
                truoc[i]=u;
                luuDuongDi.push_back(i);
                break;
            }
        }
    }
    return;
}
void BFS(int u){
    queue <int> qu;
    qu.push(u);
    chuaXet[u]=false;
    while (!qu.empty())
    {
        u=qu.front();//lay tinh ra
        qu.pop();// loai bo
        cout <<u<<" ";
        for(int i=1;i<=n;i++){
            if(a[u][i]&&chuaXet[i]){
                qu.push(i);
                truoc[i]=u;
                chuaXet[i]=false;
                luuDuongDi.push_back(i);
            }
        }
    }
}
void kiemTraThanhPhanLienThong(){
    soLienThong=0;
    for (int i=1;i<=n;i++){
        if(chuaXet[i]){
            soLienThong++;
            cout <<"Thanh phan lien thong thu "<<soLienThong<<": ";
            BFS(i);// duyet roi thi de xem con dinh nao chua xet khong, neu con thi duyet tiep
            cout <<endl;
        }
    }
}

void kiemTraLienThongManh(){
    for(int i=1;i<=n;i++){
        chuaXet[i]=false;
        cout <<"Duyet Dinh "<<i<<": ";
        DFS_deQuy(i);// duyet de tim chuaxe
        cout <<endl;
        if(!lienThongManh()){
            cout <<"Lien thong Yeu\n";
            return;
        }
        khoiPhuc();
    }
    cout <<"Lien thong Manh\n";
}
void timDuongDi(int tu, int den){
    khoiPhuc();
    cout <<"Duyet dinh BFS("<<tu<<"): ";
    //BFS(tu);// duyet de tim duong cua t;
    DFS_deQuy(tu);
    cout <<endl;
    if(truoc[den]==0){
        cout <<"Khong co duong di tu: "<<tu<<" den "<<den<<endl;
        return;
    }
    cout <<"Duong di: "<<den;
    int j=den;
    while (truoc[j]!=tu)
    {
        cout <<"<-"<<truoc[j];
        j=truoc[j];
    }
    cout <<"<-"<<tu<<endl;
}
int soThanhPhanLienThong() {
    int soLuong = 0;
    for (int i = 1; i <= n; i++) {
        if (chuaXet[i]) {
            soLuong++;
            DFS(i);
        }
    }
    return soLuong;
}
bool kiemTra(){
    for (int i=1;i<=n;i++){
        if(chuaXet[i]==true){
            return false;
        }
    }
    return true;
}
void timCanhCau(){
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(a[i][j]==1){
                int soLuong=soThanhPhanLienThong();// số lượng liên thông ban đầu;
                khoiPhuc();
                a[i][j]=0;// bo di canh i j
                int soLuong2=soThanhPhanLienThong();
                cout <<"Ket qua: ("<<i<<","<<j<<")"<< soLuong <<"->"<<soLuong2<<": ";
                khoiPhuc();
                BFS(1);
                khoiPhuc();
                if(soLuong2>soLuong){
                    cout <<"YES"<<endl;
                }else{
                    cout <<"NO"<<endl;
                }
                a[i][j]=1;
            }
        }
    }
}
void timDinhTru(){
    for (int i = 1; i <= n; i++) {
        cout <<"Dinh "<<i<<": ";
        chuaXet[i]=false;
        if(i==1){
            BFS(2);
        }
        else{
            BFS(1);
        }
        if(!kiemTra()){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
        khoiPhuc();
    }
}

int main(){
    int u;
    cout <<"Doc ma tran: "<<endl;
    int luaChon;
    do
    {
        khoiPhuc();
        cout <<endl;
        cout <<"1. Nhap danh sach ke\n";
        cout <<"2. Duyet DFS_deQuy\n";
        cout <<"3. Duyet BFS\n";
        cout <<"4. Kiem tra lien thong\n";
        cout <<"5. Tim duong di\n";// gắp lỗi khi không có đường đi tới, sửa đi nhé
        cout <<"6. Lien Thong Manh\n";
        cout <<"7. Tim dinh tru\n";//1 đọc số liên thông,2 cho đỉnh chuaxet[i]=false, và kiểm tra lại xem số liên thông có tăng không
        cout <<"8. Tim Canh Cau\n";    
        cin>>luaChon;
        switch (luaChon)
        {
        case 1:{
            nhapDanhSachKe();
            break;
        }
        case 2:{
            cout <<"Nhap dinh bat dau: ";
            cin>>u;
            cout <<"DFS("<<u<<"): ";
            DFS_deQuy(u);
            cout <<"\n";
            break;
        }
        case 3:{
            cout <<"Nhap dinh bat dau: ";
            cin>>u;
            cout <<"BFS("<<u<<"): ";
            BFS(u);
            cout <<"\n";
            break;
        }
        case 4:{
            kiemTraThanhPhanLienThong();
            break;
        }
        case 5:{
            int tu,den;
            cout <<"Di tu: ";cin>>tu;
            cout <<"Den: ";cin>>den;
            timDuongDi(tu,den);
            break;
        }
        case 6:{
            kiemTraLienThongManh();
            break;
        }
        case 7:{
            timDinhTru();
            break;
        }
        case 8:{
            timCanhCau();
            break;
        }
        default:
            break;
        }
    } while (luaChon!=0);
}
