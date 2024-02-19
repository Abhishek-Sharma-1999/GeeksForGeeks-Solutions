//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        int result=0;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(k>0)
        {
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            freq--;
            k--;
            if(freq>0)
            {
                pq.push({freq,ch});
            }
            
        }
        while(!pq.empty())
        {
            int freq=pq.top().first;
            result+=(freq*freq);
            pq.pop();
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends