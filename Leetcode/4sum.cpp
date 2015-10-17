class Solution {
    int bw_search_ind(vector<pair<int,int>>&vc,int ind){
        //first vc[i].first>ind
        if(vc.empty())return -1;
        int N=vc.size();
        int L(0),R(N-1);
        while(L<=R){
            int mid=L+(R-L)/2;
            if(vc[mid].first<=ind){L=mid+1;}
            else R=mid-1;
        }
        //not found
        if(L>=N)return -1;
        return L;
    }
    int bw_search_val(vector<int>&nums,vector<pair<int,int>>&vc,int fv){

        //first nums[vc[i].first]>fv
        if(vc.empty())return -1;
        int N=vc.size();
        int L(0),R(N-1);
        while(L<=R){
            int mid=L+(R-L)/2;

            if(nums[vc[mid].first]<=fv){L=mid+1;}
            else R=mid-1;
        }
        if(L>=N)return -1;
        return L;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ret;
        if(nums.empty())return ret;
        int N=nums.size();
        
        if(N<4)return ret;
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>>hash;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int csum=nums[i]+nums[j];
                hash[csum].push_back(make_pair(i,j));
            }
        }
        //for i,j
        int remi(0);
        int remj(0);
        for(int i=0;i<N;i++){
            if(i>0&&remi==nums[i])continue;
            remi=nums[i];
            for(int j=i+1;j<N;j++){
                //get a,b
                if(j>i+1&&remj==nums[j])continue;
                remj=nums[j];

                int a=nums[i];
                int b=nums[j];
                //no such solution
                if(hash.count(target-a-b)==0){continue;}
                vector<pair<int,int>>&hvc=hash[target-a-b];
                int bw_ind=bw_search_ind(hvc,j);
                if(bw_ind==-1)continue;
                vector<int>ret_vc;

                ret_vc.push_back(nums[i]);
                ret_vc.push_back(nums[j]);
                ret_vc.push_back(nums[hvc[bw_ind].first]);
                ret_vc.push_back(nums[hvc[bw_ind].second]);

                //ret
                ret.push_back(ret_vc);
                int rem_val=nums[hvc[bw_ind].first];
                int bval_ind(-1);
                while((bval_ind=bw_search_val(nums,hvc,rem_val))!=-1){

                    ret_vc[2]=nums[hvc[bval_ind].first];
                    ret_vc[3]=nums[hvc[bval_ind].second];
                    ret.push_back(ret_vc);
                    rem_val=nums[hvc[bval_ind].first];
                }
            }
        }

        return ret;
    }
};
