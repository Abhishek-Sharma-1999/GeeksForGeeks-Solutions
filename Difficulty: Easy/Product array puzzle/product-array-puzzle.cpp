//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        long long int prod=1,n=nums.size();;
        vector<long long int>ans(n,0);
        int zeroCount=0;
        for(int i:nums)
        {
            if(i==0)
                zeroCount++;
            else
                prod=prod*i;
        }
        if(zeroCount>1) //1 se zayada zero hain, toh sabka product zero hoga
            return ans;
            
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)    //i 0 hai, toh usmein product aa jayega
                ans[i]=prod;
            else if(zeroCount)  //zeroCount hai-> matlab 0 present hai array mein, aur current element zero nahin hai, toh zero push kar denge
                ans[i]=0;
            else    
                ans[i]=prod/nums[i];    
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends