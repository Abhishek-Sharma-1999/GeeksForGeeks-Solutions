//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        int n1=s1.length();
        int n2=s2.length();
        if(s1==s2)
        {
            return true;
        }
        if(n1!=n2)
        {
            return false;
        }
        for(int i=0;i<n1;i++)
        {
            char ch=s1.back();
            s1.pop_back();
            s1.insert(s1.begin(),ch);
            
            if(s1==s2)
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends