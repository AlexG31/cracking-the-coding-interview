#include"bits/stdc++.h"

using namespace std;

class solution{
    public:
        vector<int> remove_dup(vector<int>&vc){
            vector<int>arr;
            int N=vc.size();
            int top(0);
            cout<<arr.size()<<endl;
            int k=2;
            for(int i=0;i<N;i++){
                
                if(arr.size()<k||arr[arr.size()-k]!=vc[i]){
                   arr.push_back(vc[i]);  
                }
            }
            return arr;

        }
};
void print_vector(const vector<int>&vc){

    for(int i=0;i<vc.size();i++){
        printf("%d ,",vc[i]);
    }
    puts("");
}
int main(){

    int N;
    solution sol;
    while(cin>>N){
        vector<int>vc;
        for(int i=0;i<N;i++){
            int a;
            scanf("%d",&a);
            vc.push_back(a);
        } 
        sort(vc.begin(),vc.end());
        vector<int>ret=sol.remove_dup(vc);
        print_vector(ret);
    }
}
