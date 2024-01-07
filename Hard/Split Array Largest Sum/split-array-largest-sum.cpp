//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isValid(int arr[] ,int requiredSum, int K,int N)
  {
      int sum=0,count=1;
      for(int i=0;i<N;i++)
      {
          if(sum+arr[i]<=requiredSum)
          {
              sum+=arr[i];
          }
          else
          {
              count++;
              sum=arr[i];
          }
      }
      return count<=K;
  }
    int splitArray(int arr[] ,int N, int K) {
        int sum=0,MAXI=INT_MIN;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            MAXI=max(MAXI,arr[i]);
        }
        //Applying Binary-Search
        int low=MAXI;
        int high=sum;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(arr,mid,K,N))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends