//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long countWays(int n, int k){
        // Base Cases
        if(n==0){
            return 0;
        }
        if(n==1){
            return k;
        }
        vector<long long>dp(n+1,0);
        const int MOD=1e9+7;
        dp[1]=k;
        dp[2]=static_cast<long long>(k)*k;
        for(int i=3;i<=n;i++)
        {
            long long diff_color=(k-1)*dp[i-1];
            long long same_color=(k-1)*dp[i-2];
            dp[i]=(diff_color+same_color)%MOD;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends