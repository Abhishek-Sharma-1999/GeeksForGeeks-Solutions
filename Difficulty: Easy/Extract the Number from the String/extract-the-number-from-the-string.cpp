//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {
        vector<long long>ans;
        long long n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                long long num=0;
                bool flag=false;
                while(i<n && s[i]!=' ')
                {
                    if(s[i]=='9')
                        flag=true;
                    num=(num*10)+s[i]-'0';
                    i++;
                }
                if(!flag){
                    ans.push_back(num);
                }
            }
        }
        return ans.empty() ? -1 : *max_element(ans.begin(),ans.end());
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends