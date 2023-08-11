//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int solve(int index,int coins[], int N, int sum,vector<vector<long long int>>&dp)
  {
      if(sum==0)
      {
          return (sum%coins[N-1]==0);
      }
      if(index==N)
      {
          return 0;
      }
      if(dp[index][sum]!=-1)
      {
          return dp[index][sum];
      }
      long long int skip=solve(index+1,coins,N,sum,dp);
      long long int take=0;
      if(coins[index]<=sum)
      {
        take=solve(index,coins,N,sum-coins[index],dp);
      }
      return dp[index][sum]=take+skip;
  }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,-1));
        return solve(0,coins,N,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends