#include"bits/stdc++.h"

using namespace std;

int str2int(string str){
    if(str.empty())return 0;
    int ret(0);
    for(int i=0;i<str.size();i++){
        if(str[i]=='b')ret+=1;
        ret<<=1;
    }

    return ret;
}
int change_int(int cur,int pos){
    //next pos

}
void solve(int st){
    if(st==0||st==(1<<16)-1){
        puts("0");
        return ;
    }

    const int MaxN=10+(1<<16);
    bool vis[MaxN];
    memset(vis,false,sizeof(vis));
    queue<int>myque;
    myque.push(st);
    vis[st]=true;

    while(myque.empty()==false){
       int cur=myque.front();
       myque.pop();

       //try every position


    }

}
int main(){

    string str;
    for(int i=0;i<4;i++){
       string tmp;
       cin>>tmp;
       str+=tmp;
    }
   
    int st=str2int(str);
    cout<<"st="<<st<<endl;
    
    solve(st);

    return 0;
}
