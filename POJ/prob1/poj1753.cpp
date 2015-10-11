
#include"iostream"
#include"string"
#include"vector"
#include"cstring"
#include"cstdio"
#include"queue"

using namespace std;

int str2int(string str){
    if(str.empty())return 0;
    int ret(0);
    for(int i=0;i<str.size();i++){
        ret<<=1;
        if(str[i]=='b')ret+=1;
    }

    return ret;
}

int change_int(int cur,int pos){
    //next pos
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    
    int ret(cur^(1<<pos));


    for(int i=0;i<4;i++){
        int cx=pos/4;
        int cy=pos%4;
        cx+=dx[i];
        cy+=dy[i];
        if(cx>=4||cx<0||cy>=4||cy<0)continue;
        int np=cx*4+cy;
        ret^=(1<<np);

    }    
    return ret;
}
int solve(int st){
    if(st==0||st==(1<<16)-1){
        return 0;
    }


    const int MaxN=10+(1<<16);
    bool vis[MaxN];
    memset(vis,false,sizeof(vis));
    queue<int>myque;
    myque.push(st);
    vis[st]=true;

    int ret(0);
    int level(0);

    while(myque.empty()==false){
       int sz=myque.size();
       level++;
       for(int li=0;li<sz;li++){
           int cur=myque.front();
           myque.pop();

           //try every position
           for(int i=0;i<16;i++){
              int npos=change_int(cur,i);
              if(npos==0||npos==(1<<16)-1){
                  return level;

              }
              if(vis[npos]==false){
                 myque.push(npos);
                 vis[npos]=true;
              }
           }
       } 


    }
    return -1;

}
void debug_showint(int v){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++,v>>=1){
            printf("%d",v&1);
        }
        puts("");
    }
}
int main(){

    string str;
    while(cin>>str){
        for(int i=0;i<3;i++){
           string tmp;
           cin>>tmp;
           str+=tmp;
        }
       
        int st=str2int(str);
        //cout<<"st="<<st<<endl;
        //debug_showint(st);
        
        int ans=solve(st);
        if(ans==-1){
            puts("Impossible");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
