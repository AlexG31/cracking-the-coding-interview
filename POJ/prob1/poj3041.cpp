//#include"bits/stdc++.h"
#include"cstdio"
#include"iostream"
#include"string"
#include"cstring"
#include"vector"

using namespace std;

int main(){

    int N,K;
    while(cin>>N>>K){
        int *rx=new int[K+1]();
        int *ry=new int[K+1]();
        int *X=new int[K+1]();
        int *Y=new int[K+1]();
        bool *vis=new bool[K+1]();

        vector<vector<int> >vx;
        vector<vector<int> >vy;

        //init
        for(int i=0;i<K;i++){
            vector<int>vc;
            vx.push_back(vc);
            vy.push_back(vc);
        }
        for(int i=0;i<K;i++){

           int ta,tb;
           scanf("%d%d",&ta,&tb);
           ta--;
           tb--;
           rx[i]=ta;
           ry[i]=tb; 
           X[ta]++;
           Y[tb]++;
           vx[ta].push_back(i);
           vy[tb].push_back(i);

        }
        int left(K);
        int ans(0);
        while(left>0){
            //find max
            ans++;
            /*if(ans>4)break;
            for(int i=0;i<K;i++)printf("%d ,",X[i]);
            puts("");
            for(int i=0;i<K;i++)printf("%d ,",Y[i]);
            puts("");
            */
            int mv(0);
            int ind(-1);
            for(int i=0;i<K;i++){
                if(X[i]>mv){
                    mv=X[i];
                    ind=i;
                }
                if(Y[i]>mv){
                    mv=Y[i];
                    ind=i+500;
                }
            }
            if(ind==-1){puts("ERROR");break;}
            //printf("ind=%d\n",ind);
            if(ind>=500){
                ind-=500;
                int sz=vy[ind].size();
                //printf("sz=%d\n",sz);

                for(int i=0;i<vy[ind].size();i++){
                    int &star=vy[ind][i];
                    //printf("star=%d\n",star);

                    if(vis[star]==false){
                        vis[star]=true;
                        left--;
                        X[rx[star]]--;
                        Y[ry[star]]--;
                    }
                }
            }
            else{
            
                for(int i=0;i<vx[ind].size();i++){
                    int &star=vx[ind][i];
                    if(vis[star]==false){
                        vis[star]=true;
                        left--;
                        X[rx[star]]--;
                        Y[ry[star]]--;
                    }
                }
            }
        }

        printf("%d\n",ans);
        

        delete []rx;
        delete []ry;
        delete []X;
        delete []vis;
        delete []Y;
    }


return 0;}
