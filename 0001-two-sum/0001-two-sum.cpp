class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int val=target-arr[i];
            if(mp.count(val)){
                return {mp[val],i};
            }
            mp[arr[i]]=i;
        }
        return {};
    }
};

// time complexity : O(n)
// space complexity :O(n)   
