#include"bits/stdc++.h"
using namespace std;

int count1b(int v){
    int cnt(0);
    while(v>0){
        v&=(v-1);
        cnt++;
    }

    return cnt;
}
bool check(int pr,int s,int d){
    int cur(0);
    int pos(1);
    int tail(1);
    for(int i=0;i<5;i++,pos<<=1){
        if(pr&pos){
            //s
            cur+=s;
        }
        else{
            cur-=d;
        }
    }
    if(cur>=0)return false;
    for(int i=5;i<12;i++,pos<<=1,tail<<=1){
        if(pr&pos)cur+=s;
        else cur-=d;
        if(pr&tail)cur-=s;
        else cur+=d;
        if(cur>=0)return false;
    }
    return true;
}
int main(){
    int s,d;
    while(cin>>s>>d){
        int mval(-1);

        for(int i=0;i<(1<<12);i++){
            if(check(i,s,d)){
                //printf("i=%d,s=%d,d=%d\n",i,s,d);
                int ns=count1b(i);
                int nd=12-ns;
                int val=ns*s-nd*d;
                if(val>mval)mval=val;
            }
        }
        if(mval<0){
            puts("Deficit");
            continue;
        }
        printf("%d\n",mval);
    }


return 0;}
