class Solution {
public:
    string minWindow(string s, string t) { 
        int n=s.length();
        int m=t.length();
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int cnt=mp.size();
        int i=0,j=0;
        int start,len;
        start=-1;
        len=n+1;
        while(j<n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }
            if(cnt==0){
                while(cnt==0){
                    if(j-i+1<len){
                        len=j-i+1;
                    start=i;
                    }
                    if(mp.count(s[i])){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) cnt++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(len==n+1) return "";
        return s.substr(start,len);
    }
};