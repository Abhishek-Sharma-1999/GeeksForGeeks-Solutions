//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
/*
agar ek vertex ko visit kar liya, matlab uski ek edge ko traverse kar chuke hain, 
ab agar usmein dusri edge hai, toh vhaan se nikal jaayenge, 
(matlab edges even hain,toh ek se aaye aur dusre se nikal gaye, toh vertex par bhi aa gaye
aue edge bhi traverse ho gayi) ->Perfect Case
  lekin agar kisi vertex par odd edge hai (suppose 3), toh ek se aa agye, second se nikal gaye
  ,lekin 3rd edge visit nahin hui, aur hme saari edge, minimum ek baar visit
  karni hi hai, toh iss case mein (odd) vaale mein false return kar denge
[vertices multiple times visit ho sakti hain, lekin saari edge ek baar hi traverse hongi]  
*/

	    for(int i=0;i<paths.size();i++)
	    {
	        int visitedEdge=0;
	        for(int j=0;j<paths[i].size();j++)
	        {
	            if(paths[i][j]==1)
	            {
	                visitedEdge++;
	            }
	        }
	        if(visitedEdge%2!=0)
	        {
	            return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends