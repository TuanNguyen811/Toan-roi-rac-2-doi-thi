#include <iostream>
#include <fstream>
int n;
int s,t;//vị trí từ, đến
int truoc[100],maTran[100][100];
int d[100];//đây là giá trị đường đi đến mỗi đỉnh từ s
using namespace std;
void docFile(){
    fstream fi("maTran1.txt");
    if(!fi.is_open()){
        cout <<"Khong mo duoc file"<<endl;
        return;
    }
    fi>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int c;
            fi>>c;
            if(c==0){
                maTran[i][j]=99;
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
//Ham khoi tao ban dau
void init(){
    for(int i=1;i<=n;i++){
        d[i]=maTran[s][i];
        truoc[i]=s;
    }
}
void result(void){
    if(d[t]==99){
        cout<<"Khong co duong di"<<endl;
    }else{
        cout <<"Duong di ngan nhat tu "<<s<<" den "<<t <<":";
        int i=truoc[t];
        cout <<t<<"<-";
        while (t!=s)
        {
            cout <<i<<"<-";
            t=truoc[i];
        }    
        cout <<s;
    }
}
void Ford_Bellman(void){
    d[s]=0;//chạy từ s
    //vòng chốt ngoài cùng
    for(int i=1;i<=n-2;i++){
        //vòng chọn mang đi tìm min với nó
        for(int j=1;j<=n;j++){
            if(j!=s){
                //vòng lấy xem có đường nào nhỏ hơn từ j không
                for(int k=1;k<=n;k++){
                   if(d[j]>d[k]+maTran[k][j]){
                    //hoán đổi các giá trị
                        d[j]=d[k]+maTran[k][j];
                        truoc[k]=j;
                   } 
                }
            }
        }
    }
}
int main(){
    docFile();
    cout <<"Tim duong tu: ";
    cin>>s;
    cout <<"Den: ";
    cin>>t;
    init();
    Ford_Bellman();
    result();
    return 0;
}