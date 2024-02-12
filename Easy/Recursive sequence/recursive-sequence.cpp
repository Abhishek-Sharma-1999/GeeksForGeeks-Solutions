//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    const long long MOD=1e9+7;
    long long sequence(int n){
        long long ans=0,count=1;
        for(int i=1;i<=n;i++)
        {
            long long prod=1;
            for(int j=1;j<=i;j++)
            {
                prod=(prod*count)%MOD;
                count++;
            }
            ans+=prod;
        }
        return ans%MOD;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends