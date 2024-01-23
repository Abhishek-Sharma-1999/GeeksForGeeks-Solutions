//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  vector<int>topological_sort(vector<int>&indegree,unordered_map<int,vector<int>>&mp,int n)
  {
      vector<int>result;
      queue<int>q;
      int count=0;
      for(int i=0;i<n;i++)
      {
          if(indegree[i]==0)
          {
              result.push_back(i);
              count++;
              q.push(i);
          }
      }
      
      while(!q.empty())
      {
          int u=q.front();
          q.pop();
          
          for(int &v:mp[u])
          {
              indegree[v]--;
              
              if(indegree[v]==0)
              {
                  q.push(v);
                  count++;
                  result.push_back(v);
              }
          }
      }
      if(count==n)
      {
          return result;
      }
      return {};
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int>inDegree(n,0);
        unordered_map<int,vector<int>>mp;   //adjacency list
        for(auto &vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            mp[b].push_back(a);    //[1,0] ->    1<----0
            inDegree[a]++;
        }
        return topological_sort(inDegree,mp,n);
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends