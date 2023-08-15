#include<bits/stdc++.h>
using namespace std;
class Soln{
public:
    //using bfs detecting a cycle
    bool detect(int src, vector<int> adj[], int vis[]){
         vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }

    bool isCycle(int V, vector<int> adj[]) {
               // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
        
    }

    //using dfs detecting a cycle
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node]= 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, adj)==true) return true;
            }
            else if(it != parent ) return true;
        }
        return false;
    }
    bool iscycle(int v, vector<int> adj[]){
        int vis[v] = {0};
        for(int i=0 ;i<v; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)==true) return true;
            }
        }
        return false;
    }
    
};
