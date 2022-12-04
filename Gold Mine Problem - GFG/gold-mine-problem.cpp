//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int curr=M[j][i]+M[j][i+1];
                if(j-1>=0){
                    curr=max(curr,M[j][i]+M[j-1][i+1]);
                }
                if(j+1<n){
                    curr=max(curr,M[j][i]+M[j+1][i+1]);
                }
                M[j][i]=curr;
            }
        }
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            maximum=max(maximum,M[i][0]);
        }
        return maximum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends