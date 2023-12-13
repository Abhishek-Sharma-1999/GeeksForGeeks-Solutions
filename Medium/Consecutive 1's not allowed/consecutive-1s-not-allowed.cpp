//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll MOD=1e9+7;
	ll countStrings(int n) {
	    ll first=2;
	    ll second=3;
	    if(n==1) return first;
	    ll c=0;
	    for(int i=3;i<=n;i++)
	    {
	        c=(first+second)%MOD;
	        first=second;
	        second=c;
	    }
	    return second;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends