#include"bits/stdc++.h"

using namespace std;

class Solution{
    public:
        vector<vector<int>> threeSum(vector<int>&nums){
            vector<vector<int>>ret;
            if(nums.empty())return ret;
            int N=nums.size();
            //not so good
            sort(nums.begin(),nums.end());
            int rem(nums[0]);
            for(int i=0;i<N;i++){
                if(i!=0&&nums[i]==rem)continue;
                rem=nums[i];
                int L(i+1),R(N-1);
                while(L<R){
                    int csum=nums[L]+nums[R];
                    if(csum>-rem)R--;
                    else if(csum<-rem){
                        L++;
                    }
                    else {
                        vector<int>vc;
                        vc.push_back(rem);
                        vc.push_back(nums[L]);
                        vc.push_back(nums[R]);
                        ret.push_back(vc);
                        L++;
                        while(L<R&&nums[L]==nums[L-1])L++;
                    }
                }
            }
            return ret;

        }
};

void disp(vector<vector<int>>&ret){
    puts("vector");
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<",";
        }
        puts("");
    }
}
int main(){

    int arr[]={-1,0,0,1};
    vector<int>vc(arr,arr+4);
    Solution sol;
    vector<vector<int>>ret=sol.threeSum(vc);
    
    //puts("here");
    disp(ret);


return 0;}
