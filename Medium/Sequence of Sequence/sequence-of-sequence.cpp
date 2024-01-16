//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int m,int n,int count)
    {
        if(count==n){
            return 1;
        }
        if(i>m){
            return 0;
        }
        int taken=solve(i*2,m,n,count+1);
        int not_taken=solve(i+1,m,n,count);
        return taken+not_taken;
    }
    int numberSequence(int m, int n){
        return solve(1,m,n,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends