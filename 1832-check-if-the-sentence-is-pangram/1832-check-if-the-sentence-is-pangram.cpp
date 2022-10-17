class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,bool> mp;
        for(int i=0;i<sentence.size();i++){
            mp[sentence[i]]=true;
            if(mp.size()==26) return true;
        }
        return false;
    }
};