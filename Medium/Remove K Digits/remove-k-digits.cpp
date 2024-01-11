//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n=S.length();
        if(K==n)    //saare hi characters,remove karne hai
        {
            return "0";
        }
        stack<char>st;
        for(char digit:S)
        {
            while(!st.empty() && K>0 && st.top()>digit)
            {
                st.pop();
                K--;
            }
            st.push(digit);
        }
        // agar ab bhi k bacha hai, toh aur remove kar denge elements
        while(K>0)
        {
            st.pop();
            K--;
        }
        string ans="";
        while(!st.empty())  // stack ka content aa gya,digits reverse order mein in answer
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end()); //stack se reverse order mein, milega, toh ans ko reverse krana padega
        int len=ans.length();
        int startIndex=len;    //trailing zeros ke liye
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            {
                startIndex=i;
                break;
            }
        }
//agar ans, len ke equal hai,matlab saare zeroes hain (starting mein,toh zrero) return karenge,nahin toh substring
        ans=startIndex==len ? "0" : ans.substr(startIndex);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends