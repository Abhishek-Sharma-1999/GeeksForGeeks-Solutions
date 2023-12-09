//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int sum_of_digits(int n)
  {
      int sum=0;
      while(n>0)
      {
          int rem=n%10;
          sum=sum+rem;
          n=n/10;
      }
      return sum;
  }
  
  bool isPrime(int n)
  {
      if(n<=1)
      {
          return false;
      }
      for(int i=2;i<=sqrt(n);i++)
      {
          if(n%i==0)
          {
              return false;
          }
      }
      return true;
  }
    int smithNum(int n) {
// agar number prime hai(2 factors-> number itself and 1), toh composite (3 factors , 15->5,3,1) toh hai nahin toh false return kar denge
        if(isPrime(n))
        {
            return 0;
        }
        int sum_of_number=sum_of_digits(n);
        int sum_of_factors=0;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                int s=sum_of_digits(i);
                while(n%i==0 && n>0)
                {
                    sum_of_factors+=s;
                    n=n/i;
                }
            }
        }
        if(sum_of_factors==sum_of_number)
        {
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends