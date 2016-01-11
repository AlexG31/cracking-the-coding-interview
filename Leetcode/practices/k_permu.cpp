#include"bits/stdc++.h"

using namespace std;

class solution{
    public :int fact[11];
    int factorial(int n){
        int ret(1);
        for(int i=1;i<=n;i++){
            ret*=i;
        }
        return ret;
    }
    public:
    solution(){
       fact[1]=1;
       fact[0]=1;
       for(int i=1;i<=9;i++){
           fact[i]=fact[i-1]*i;
       }  
    }
        int kthPermu(vector<int>&vc,int k,int L,int R){
            // kth 
            int N=R-L+1;
            k--;
            k%=fact[N];
            k++;

            if(k<=1)return 0;
            for(int i=N-1;i>0;i--){
                if(k>fact[i]){
                    //find jth elem >N-i-1
                    int pos(-1);
                    int pre_index(L+N-i-1);
                    int Scnt=k/fact[i];
                    int curCnt(0);

                    for(int j=pre_index;j<=R;j++){
                        if(vc[j]>vc[pre_index]){
                           pos=j;
                           if(++curCnt>=Scnt)
                           break;  
                        }
                    }
                    if(pos==-1)return -1;
                    swap(vc[pos],vc[pre_index]);
                    kthPermu(vc,k%fact[i],pre_index+1,R);
                    break;
                }  
            }

        }
        int kPermu(vector<int>&vc,int k){
            for(int i=1;i<k;i++){
                next_permutation(vc.begin(),vc.end());
            }
            return 1;
        }

};
void disp_vec(vector<int>&vc){
    for(int i=0;i<vc.size();i++)printf("%d,",vc[i]);
    puts("");
}
int main(){

    
    int n;
    solution sol;
    while(cin>>n){
      vector<int>vc;
      for(int i=1;i<=n;i++)vc.push_back(i);
       
      for(int i=0;i<sol.fact[n];i++){
           disp_vec(vc);
           next_permutation(vc.begin(),vc.end());
      }

    }

    return 0;
}
