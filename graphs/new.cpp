#include<bits/stdc++.h>
using namespace std;

class sol{
    public:
    int solution(vector<vector<int>> &mat, int r, int c, int k){
        int n = mat.size(), m = mat[0].size();

        queue<pair<int, pair<int,int>>> q; //{val, {row, col}}
        q.push({k, {r, c}});

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,1,-1};
        int steps; int prevkey = 0;
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int key = q.front().first;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];

                if(nrow==n-1 || nrow==0 || ncol==0 || nrow==m-1) return prevkey!=0? steps:-1;

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m
                    && mat[nrow][ncol]!=-1){
                    if(prevkey!=0){
                        steps++;
                        prevkey = mat[nrow][ncol];
                    }
                    if(prevkey==0){
                        steps++;
                    }
                }
            }

        }
        return -1;
    }
};