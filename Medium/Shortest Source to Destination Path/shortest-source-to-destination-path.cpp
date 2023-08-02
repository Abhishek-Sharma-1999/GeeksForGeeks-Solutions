//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isValid(int i,int j,int N,int M)
  {
      if(i>=0 && i<N && j>=0 && j<M)    return true;
      return false;
  }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int steps=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        int dir_x[]={-1,0,1,0};
        int dir_y[]={0,1,0,-1};
        while(!q.empty())
        {
            int Size=q.size();
            while(Size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==X && y==Y)
                {
                    return steps;
                }
                

                for(int i=0;i<4;i++)
                {
                    int new_x=x+dir_x[i];
                    int new_y=y+dir_y[i];
                    if(isValid(new_x,new_y,N,M) && A[new_x][new_y]==1)
                    {
                        q.push({new_x,new_y});
                        A[new_x][new_y]=0;
                        
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends