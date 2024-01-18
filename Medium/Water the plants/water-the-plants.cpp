//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]==-1){
                continue;
            }
            int leftRange=max(0,i-gallery[i]);
            int rightRange=min(n-1,i+gallery[i]);
            vec.push_back({leftRange,rightRange});
        }
        sort(vec.begin(),vec.end());
        int tap=0;
        int target=0;
        int i=0;
        while(target<n)
        {
            int maxRightEnd=-1;
            while(i<vec.size())
            {
                if(vec[i].first<=target){
                    maxRightEnd=max(maxRightEnd,vec[i].second);
                    i++;
                }
                else{
                    break;
                }
            }
            if(maxRightEnd<target){
                return -1;
            }
            tap++;
            target=maxRightEnd+1;
        }
        return tap;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends