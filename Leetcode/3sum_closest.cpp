class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        if(nums.empty())return 0;
        int N=nums.size();
        if(N<3)return 0;
        int ret(nums[0]+nums[1]+nums[2]);
        int ans=ret;
        ret=abs(ret-target);
        
        sort(nums.begin(),nums.end());
        int rem(nums[0]);
        for(int i=0;i<N;i++){
            if(i>0&&nums[i]==rem)continue;
            rem=nums[i];

            int L(i+1),R(N-1);
            while(L<R){
                int csum=(rem+nums[L]+nums[R]-target);
                if(abs(csum)<ret){
                    ans=csum+target;
                    ret=abs(csum);
                }
                else if(csum>0){R--;}
                else L++;
            }
        }
        return ans;
    }
};
