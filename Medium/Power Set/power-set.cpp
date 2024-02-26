//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>ans;
	void solve(string &s,int index,string &curr,int len)
	{
	    if(index>=len)
	    {
	        if(curr!="")    ans.push_back(curr);
	        return;
	    }
	    curr.push_back(s[index]);
	    solve(s,index+1,curr,len);
	    curr.pop_back();
	    solve(s,index+1,curr,len);
	}
		vector<string> AllPossibleStrings(string s){
		    string curr="";
		    solve(s,0,curr,s.length());
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends