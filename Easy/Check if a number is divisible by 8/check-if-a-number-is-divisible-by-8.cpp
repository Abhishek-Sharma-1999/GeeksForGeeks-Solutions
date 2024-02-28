//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //if last 3 digits are divisible by 8, it means it is divisible by 8
        //stoi -> to convert string to integer in c++
        // s.substr -> take the substring from the provided index, to last index if not specified
        int n=s.length();
        if(n<=3)
        {
            if(stoi(s)%8==0)
                return 1;
        }
        else
        {
            if(stoi(s.substr(n-3))%8==0)
                return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends