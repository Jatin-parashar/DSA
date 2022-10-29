class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> pl;
        int n=plantTime.size();
        for(int i=0;i<n;i++){
            pl.push_back({growTime[i],plantTime[i]});
        }
        sort(pl.begin(),pl.end(),greater<pair<int,int>>());
        int time=0,ans=0;
        for(int i=0;i<n;i++){
            time+=pl[i].second;
            ans=max(ans,time+pl[i].first);
        }
        return ans;
    }
};