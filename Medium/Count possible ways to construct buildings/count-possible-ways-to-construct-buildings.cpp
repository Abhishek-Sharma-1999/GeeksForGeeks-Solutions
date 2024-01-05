//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int Building=1;
	int Space=0;
	const int MOD=1e9+7;
	int solve_recursion(int status,int plot)  //status -> kya lga rahe hain (Building ya Space)
	{
	    if(plot==0) //agar plot khatam ho gaye,toh return 1 kar denge
	    {
	        return 1;
	    }
	    if(status==Building)    //agar status Building hai, toh sirf space hi lga sakte hain
	    {
	        return solve_recursion(Space,plot-1)%MOD;
	    }
	    else    //agar status Space hai,toh building aur space dono lga sakte hain
	    {
	        return solve_recursion(Space,plot-1)%MOD+solve_recursion(Building,plot-1)%MOD;
	    }
	    return -1;  //int function hai,toh return -1, vaise yhaan tak kabhi code aayega nahin upar hi return ho jaayega
	}
	int dp[2][100001];
	int solve_memoization(int status,int plot)  //status -> kya lga rahe hain (Building ya Space)
	{
	    if(plot==0) //agar plot khatam ho gaye,toh return 1 kar denge
	    {
	        return 1;
	    }
	    if(dp[status][plot]!=-1)
	    {
	        return dp[status][plot];
	    }
	    if(status==Building)    //agar status Building hai, toh sirf space hi lga sakte hain
	    {
	        return dp[status][plot]=solve_memoization(Space,plot-1)%MOD;
	    }
	    else    //agar status Space hai,toh building aur space dono lga sakte hain
	    {
	        return dp[status][plot]=solve_memoization(Space,plot-1)%MOD+solve_memoization(Building,plot-1)%MOD;
	    }
	    return -1;  //int function hai,toh return -1, vaise yhaan tak kabhi code aayega nahin upar hi return ho jaayega
	}
	int TotalWays(int N)
	{
	    // N-1  -> 0 based indexing
	   // int ans=solve_recursion(Building,N-1)%MOD+solve_recursion(Space,N-1)%MOD;
	   memset(dp,-1,sizeof(dp));
	   long long ans=solve_memoization(Building,N-1)%MOD+solve_memoization(Space,N-1)%MOD;
	    
	    return (ans*ans)%MOD;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends