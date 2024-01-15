//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int index,int n, int total, vector<int> &cost,vector<vector<int>>&dp)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index][total]!=-1)
        {
            return dp[index][total];
        }
        int not_taken=solve(index+1,n,total,cost,dp);
        int taken=INT_MIN;
        if(cost[index]<=total){
           taken=1+solve(index+1,n,total-cost[index]+(cost[index]*0.9),cost,dp);
        }
        return dp[index][total]=max(not_taken,taken);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return solve(0,n,total,cost,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends