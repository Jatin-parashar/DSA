class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        map<int,multiset<string>,greater<int>> mp2;
        for(auto x:mp){
            mp2[x.second].insert(x.first);
        }
        for(auto x:mp2){
            while(!x.second.empty()){
                if(k==0) break;
                ans.push_back(*x.second.begin());
                x.second.erase(x.second.begin());
                k--;
            }

        }
        return ans;
    }
};