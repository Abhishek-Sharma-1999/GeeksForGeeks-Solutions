//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve_recusrion(int *arr, int n,int index)
	{
	    if(index>=n)
	    {
	        return 0;
	    }
	    if(index==n-1)
	    {
	        return arr[index];
	    }
	    int take=arr[index]+solve_recusrion(arr,n,index+2);
	    int not_take=0+solve_recusrion(arr,n,index+1);
	    return max(take,not_take);
	}
	int solve_memoization(int *arr, int n,int index,vector<int>&dp)
	{
	    if(index>=n)
	    {
	        return 0;
	    }
	    if(index==n-1)
	    {
	        return arr[index];
	    }
	    if(dp[index]!=-1)
	    {
	        return dp[index];
	    }
	    int take=arr[index]+solve_memoization(arr,n,index+2,dp);
	    int not_take=0+solve_memoization(arr,n,index+1,dp);
	    return dp[index]=max(take,not_take);
	}
	int findMaxSum(int *arr, int n) {
	   // return solve_recusrion(arr,n,0);
	   vector<int>dp(n+1,-1);
	   return solve_memoization(arr,n,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends