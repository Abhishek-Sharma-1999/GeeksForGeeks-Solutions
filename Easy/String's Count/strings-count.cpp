//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    long long int ans=1;    //all a , suppose n=5, then 3! / 3! (repetition of a)
    ans=ans+n;  // 1 b, 4a+1b => aaaab => 5!/4!(repetition of a) => 5 ==n
    ans=ans+n;  // 1 c, 4a+1c => aaaac => 5!/4! (repetition of c) => 5==n
    ans=ans+n*(n-1)/2;  //2c  => aaacc => 5!/3!*2! => 5*4/2 => n*(n-1)/2
    ans=ans+n*(n-1); // 1b+1c => aaabc => 5!/3! => 5*4 => n*(n-1)
    ans=ans+n*(n-1)*(n-2)/2; // 1b+2c => aabcc => 5!/2!*2! => 5*4*3/2 => n*(n-1)*(n-2)/2
    return ans;
}