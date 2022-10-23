class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
            else{
                ans.push_back(abs(nums[i]));
                break;
            }
        }
        cout<<ans[0]<<endl;        cout<<sum<<endl<<n*(n+1)/2;
        if(sum>n*(n+1)/2)  ans.push_back(ans[0]-(sum-(n*(n+1)/2)));
        else ans.push_back(ans[0]-(sum-(n*(n+1)/2)));
        return ans;
        
    }
};