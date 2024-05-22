#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
int n; // số đỉnh
int a[100][100]; 
bool chuaXet[100]; 
int truoc[100];
int soLienThong;
vector<vector<int>> danhSachKe(n + 1);
vector <int> luuDuongDi;
// ma trân kết quả
int ketQua[100];
int d;// dem 

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
void nhapDanhSachKe(){
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    vector<vector<int>> danhSachKe(n + 1);
    cout << "Nhap danh sach ke:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Nhap cac dinh ke voi dinh " << i << " (nhap 0 de ket thuc): ";
        int v;
        do {
            cin >> v;
            if(v != 0) {
                danhSachKe[i].push_back(v);
            }
        } while(v != 0);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int v : danhSachKe[i]) {
            a[i][v] = 1;
            //a[v][i] = 1; // Neu do thi vo huong
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
void khoiPhucMaTran(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int v : danhSachKe[i]) {
            a[i][v] = 1;
            //a[v][i] = 1; // Neu do thi vo huong
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
    while (truoc[j]!=tu){
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
    int soLuong=soThanhPhanLienThong();// số lượng liên thông ban đầu;
    khoiPhuc();
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(a[i][j]==1){
                a[i][j]=0;// bo di canh i j
                bool voHuong=false;
                if(a[j][i]==1){
                    voHuong=true;
                    a[j][i]=0;
                }
                int soLuong2=soThanhPhanLienThong();
                cout <<"Cau: ("<<i<<","<<j<<")"<< soLuong <<"->"<<soLuong2<<": ";
                khoiPhuc();
                BFS(1);
                khoiPhuc();
                if(soLuong2>soLuong){
                    cout <<"YES"<<endl;
                }else{
                    cout <<"NO"<<endl;
                }
                a[i][j]=1;
                if(voHuong){
                    a[j][i]=1;
                }
            }
        }
    }
}
void timDinhTru2(){
    int soLuong=soThanhPhanLienThong();// số lượng liên thông ban đầu;
    khoiPhuc();
    for (int i = 1; i <= n; i++) {
        chuaXet[i]=false;
        int soLuong2=soThanhPhanLienThong();
        cout <<"Tru "<<i<<": "<< soLuong <<"->"<<soLuong2<<": ";
        khoiPhuc();
        chuaXet[i]=false;
        if(i==1){
            BFS(2);
        }
        else{
            BFS(1);
        }
        khoiPhuc();
        if(soLuong2>soLuong){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }
}
void timDinhTru(){
    for (int i = 1; i <= n; i++) {
        cout <<"Dinh "<<i<<": ";
        chuaXet[i]=false;
       
        if(!kiemTra()){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
        khoiPhuc();
    }
}
//chuong Euler
void chuTrinhEuler(int u) {
    stack<int> ST;//
    int CE[100];
    ST.push(u);
    int dCE = 0;
    while (!ST.empty()) {
        int v = ST.top();
        int x = 1;
        while (x <= n && a[v][x] == 0) {
            x++;
        }
        if (x > n) {
            dCE++;
            CE[dCE] = v;
            ST.pop();
        } else {
            ST.push(x);
            a[v][x] = a[x][v] = 0; // Loại bỏ cạnh (v, x)
        }
    }
    cout <<"Chu Trinh Euler( "<<u<<"): ";
    for (int i = dCE; i > 0; i--) {
        cout << CE[i] << " ";
    }    
    cout << endl;
    //khoiPhucMaTran();
}

//chuong Hamilton
void inKetQua(void){
    d++;
    cout <<"Duong di thu "<<d<<": ";
    for(int i=0;i<=n;i++){
        cout <<ketQua[i]<<" ";
    }
    cout <<endl;
}
void Hamilton(int ketQua[100],bool chuaXet[100], int i){
    for (int j=1;j<=n;j++){
        if(a[ketQua[i-1]][j]==1&&chuaXet[j]==true){
            ketQua[i]=j;
            chuaXet[j]=false;
            if(i < n){// trường hợp oke tìm được 
                Hamilton(ketQua,chuaXet,i+1);
            }else if(ketQua[i]==ketQua[0]){// trường hợp về ban đầu và i không tìm được đường nữa
                inKetQua();
            }
            chuaXet[j]=true;// trường hơpj khong có đường thì trả về o và xét j tiếtp theo
        }
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
        cout <<"5. Tim duong di\n";// gắp lỗi khi không có đường đi tới
        cout <<"6. Lien Thong Manh\n";
        cout <<"7. Tim dinh tru\n";
        cout <<"8. Tim Canh Cau\n";    
        cout <<"9. Chu Trinh Euler\n";
        cout <<"10. Duyet Hamiltom\n";
        cout <<"11. Khoi phuc ma tran\n";
        cout <<"0. Thoat\n";
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
            timDinhTru2();
            break;
        }
        case 8:{
            timCanhCau();
            break;
        }
        case 9:{
            cout <<"Duyet tu: ";
            int u;cin>>u;
            chuTrinhEuler(u);
            break;
        }
        case 10:{
            ketQua[0]=1;
            int i=1;
            d=0;
            Hamilton(ketQua,chuaXet,i);
            if(d==0){
                cout <<"Khong co chu trinh"<<endl;
            } 
            break;
        }
        case 11:{
            khoiPhucMaTran();
            break;
        }
        default:
            break;
        }
    } while (luaChon!=0);
}