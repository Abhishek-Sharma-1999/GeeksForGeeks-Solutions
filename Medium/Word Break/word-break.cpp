//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    // int dp[1101];
    // unordered_set<string>st;
    // int solve_recursion(int index,string &s,int n){
    //     if(index>=n){
    //         return 1;
    //     }
    //     if(st.find(s)!=st.end())
    //     {
    //         return 1;
    //     }
    //     for(int l=index;l<n;l++)
    //     {
    //         string subString=s.substr(index,l);
    //         if(st.find(subString)!=st.end() && solve_recursion(index+l,s,n)==1)
    //         {
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }
    
    // int solve_memoization(int index,int n,string &s,unordered_set<string>st){
    //     if(index==n){
    //         return 1;
    //     }
    //     string k;
    //     for(int l=1;index+l<=n;l++)
    //     {
    //         k=s.substr(index,l);
    //         if(st.find(k)!=st.end() && solve_memoization(index+l,n,s,st)==1)
    //         {
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }
    
    // int wordBreak(int n, string s, vector<string> &dictionary) {
    //     memset(dp,-1,sizeof(dp));
    //     unordered_set<string>st;
    //     for(string s:dictionary)
    //     {
    //         st.insert(s);
    //     }
    //     return solve_memoization(0,n,s,st);
    // }
    
    unordered_set<string>st;
    bool solve(int i, string& str){
        if(i==str.size())return true;
        string temp="";
        bool ans=false;
        for(int j=i;j<str.size();j++){
            temp+=str[j];
            if(st.find(temp)!=st.end())
                ans=ans||solve(j+1,str);
        }
        return ans;
    }

    int wordBreak(int n,string A, vector<string> &B) {
        for(int i=0;i<B.size();i++)
            st.insert(B[i]);
        return solve(0,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends