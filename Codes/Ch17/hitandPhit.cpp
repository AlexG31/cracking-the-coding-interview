#include"bits/stdc++.h"


using namespace std;
void disp_ans(int h,int p){
    printf("hit=%d,presodu-hit=%d\n",h,p);
}
int map2int(char ch){
        if(ch=='R'){
            return 1;
        } else if(ch=='G'){
            return 2;
        }else if(ch=='B'){
            return 3;
        }else if(ch=='Y'){
          //"Y" 
            return 4;
        }else{
            //error
            return 0;
        }

}
int main(){
    string str_in,str_guess;
    while(cin>>str_in>>str_guess){
        //get input
        if(str_in.empty()||str_guess.empty()){disp_ans(0,0);continue;}
        
        int N=str_in.size();
        int M=str_guess.size();
        
        bool *vis=new bool[M]();

        int h(0),p(0);
        int Counter[5];
        memset(Counter,0,sizeof(Counter));

        //get h&p
        for(int i=0;i<N;i++){
            Counter[map2int(str_in[i])]++;   
        }
        for(int i=0;i<min(M,N);i++){
           if(str_in[i]==str_guess[i]){

               Counter[map2int(str_in[i])]--;   
               h++;
               vis[i]=true;
           }  
        }
        //get p
        for(int i=0;i<M;i++){
           if(vis[i]==true)continue;
           char ch=str_guess[i];
           if(Counter[map2int(ch)]>0){
               Counter[map2int(ch)]--;
               p++;
           }  
        }

        delete []vis;
        disp_ans(h,p);

    }

    return 0;
}
