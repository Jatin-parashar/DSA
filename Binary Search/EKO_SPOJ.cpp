#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> h,int n,int m,int mid){
    int sum=0;
    for(int i=0;i<n;i++){
        if(h[i]>mid){
            sum+=(h[i]-mid);
        }
        if(sum>=m){
            return true;
        }
    }
    return false;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int ans=0;
    int s=0;
    int e=*max_element(h.begin(),h.end());
    while(s<=e){
        int mid=(s+e)/2;
        if(possible(h,n,m,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
