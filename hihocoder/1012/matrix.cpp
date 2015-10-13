
#include"iostream"
#include"cstring"
#include"cstdio"

using namespace std;
#define MaxN 1011


int N;
int mA[MaxN][MaxN];
int mB[MaxN][MaxN];
int mC[MaxN][MaxN];

int mLen;

bool vis[MaxN];

void dispmC(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d ,",mC[i][j]);
        puts("");
    }
    puts("\n========");
}
bool check(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(mC[i][j]!=mB[i][j])return false;
        }
    return true;
}
bool checkmC(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(mC[i][j]!=mB[i][j])return false;
        }
    return true;
}
void loop_row(int pos,int row){
    if(vis[pos]==true)return ;
    vis[pos]=true;
    
    for(int i=0;i<N;i++){
        if(mA[0][i]==mB[row][pos]){
            loop_row(i,row);
            break;
        }
    }
}

void loop_col(int pos,int col){
    if(vis[pos]==true)return ;
    vis[pos]=true;
    
    for(int i=0;i<N;i++){
        if(mC[i][col]==mB[pos][col]){
            loop_col(i,col);
            break;
        }
    }
}
int match(int pi,int pj){
    memset(vis,false,sizeof(vis));
    //pi-th row
    int ans(0);
    for(int i=0;i<N;i++){
        if(mA[0][i]!=mB[pi][i]){
            ans++;
            if(!vis[i]){
                ans--;
                loop_row(i,pi);
            }
        }
    }
    //move row
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mA[0][j]==mB[pi][i]){
                //copy
                for(int k=0;k<N;k++){
                    mC[k][i]=mA[k][j];
                }
                break;
            }
        }  
    }
    //dispmC();
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N;i++){
        if(mC[i][pj]!=mB[i][pj]){
           ans++;
           if(!vis[i]){
               ans--;
               loop_col(i,pj);
           }  
        }  
    }
    //move col
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mB[i][pj]==mC[j][pj]){
                if(i==j)break;
                //swap
                for(int k=0;k<N;k++){
                    swap(mC[i][k],mC[j][k]);
                }
                break;
            }
        }  
    }
    //dispmC();
    //check
    if(checkmC()==false)return -1;
    return ans;

}
int solve(){

    int ret(-1);
    //loop i,j
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mB[i][j]==mA[0][0]){
                //found i,j
                //printf("i=%d,j=%d\n",i,j);
                int ans=match(i,j);
                if(ans!=-1){
                    if(ret==-1)ret=ans;
                    else if(ans<ret)ret=ans;
                }

            }
        }

    }

    return ret;
}

int main(){

    while(cin>>N){
        //input mat

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&mA[i][j]);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&mB[i][j]);


        printf("%d\n",solve());
    }

return 0;}
