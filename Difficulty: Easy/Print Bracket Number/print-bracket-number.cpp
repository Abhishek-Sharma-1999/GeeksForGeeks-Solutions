//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string s) {
        int n=s.size();
        vector<int>ans;
        stack<int>st;
        int i=0,count=0;
        while(i<n)
        {
            if(s[i]=='(')
            {
                count++;
                st.push(count);
                ans.push_back(count);
            }
            else if(s[i]==')')
            {
                ans.push_back(st.top());
                st.pop();
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends