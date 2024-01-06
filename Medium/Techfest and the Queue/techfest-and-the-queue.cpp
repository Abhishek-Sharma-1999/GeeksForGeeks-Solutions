//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int primefactors(int n)
    {
        int count=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            while(n%i==0)
            {
                count++;
                n=n/i;
            }
        }
        if(n!=1)    //agar n 1 ke equal nahin hua, jaise 11 ke case mein, kyunki vo ek prime number hai, toh ans++ kar denge, kyunki 11 ki power 1 , 1 power toh hai hi
        {
            count++;
        }
        return count;
    }
	int sumOfPowers(int a, int b){
	    int sum=0;
	    for(int i=a;i<=b;i++)
	    {
	        sum+=primefactors(i);
	    }
	    return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends