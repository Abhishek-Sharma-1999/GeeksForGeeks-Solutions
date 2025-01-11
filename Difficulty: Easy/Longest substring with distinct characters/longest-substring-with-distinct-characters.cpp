//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int i=0,j=0,ans=0,n=s.length();
        unordered_map<char,int>mp;
        while(j<n){
            while(mp[s[j]]){    //if that character already exists
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends