//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    private:
        void solve(vector<string>& ans,int zero_count,int one_count,string curr,int n)
        {
            if(curr.length()==n)
            {
                ans.push_back(curr);
                return;
            }
            if(one_count>zero_count)    //agar one ka count,bda hai,matlab zero append kar sakte hain
                solve(ans,zero_count+1,one_count,curr+"0",n);
/*
1 toh append, dono case mein, isliye ye condition bahar likhi  hai, 
agar zero ka count equal hai one ke count se tab bhi one append hoga,
aur agar one ka count bda hai, zero ke count, tab bhi one append kar sakte hain (jo upar ki if condition hai)
*/
            solve(ans,zero_count,one_count+1,curr+"1",n);   
        }
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    solve(ans,0,1,"1",n);
	    sort(ans.begin(), ans.end());
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends