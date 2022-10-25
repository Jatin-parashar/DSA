class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto x:word1){
            for(auto y:x){
                a+=y;
            }
        }
        for(auto x:word2){
            for(auto y:x){
                b+=y;
            }
        }
        return a==b?1:0;
        
    }
};