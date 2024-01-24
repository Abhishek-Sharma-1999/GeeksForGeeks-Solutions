//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
  bool isCycle(int node,vector<int> adjacencyList[],vector<bool>&visited,int parent)
  {
      visited[node]=true;
      for(auto &v:adjacencyList[node])
      {
          if(!visited[v])
          {
              if(isCycle(v,adjacencyList,visited,node))
              {
                  return true;
              }
          }//matlab,  vo visted hai aur vo uski parent bhi nahin hai
          else if(v!=parent)
          {
              return true;
          }
      }
      return false;
  }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<bool>visited(n,false);
        vector<int>adjacencyList[n];
        for(auto &vec:adj){
            adjacencyList[vec[0]].push_back(vec[1]);
            adjacencyList[vec[1]].push_back(vec[0]);
        }
//first,we are checking, if the graph does have a cycle, if a cycle is present, then it is not a tree
        if(isCycle(0,adjacencyList,visited,-1))
        {
            return false;
        }
// if any of the node remains unvisited, then also graph is not a tree        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends