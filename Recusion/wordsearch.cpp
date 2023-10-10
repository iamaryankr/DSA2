#include<bits/stdc++.h>
using namespace std;


//my solution which did not work
class Solution {
public:
    bool func(vector<vector<char>> &board, string &word, int row, int col,
    int ind){
        int n = board.size(), m = board[0].size();
        bool found;
        if(ind==word.size()-1){
            return true;
        }
        if (row < 0 || row >= n || col < 0 || col >= m || 
        board[row][col] != word[ind]) {
            return false;
        }
        int delrow[] ={0,1,0-1};
        int delcol[] ={-1,0,1,0};
        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(board[nrow][ncol]==word[ind+1] && nrow<n && nrow>=0 
            && ncol<m && ncol>=0){
                char temp = board[nrow][ncol];
                board[nrow][ncol] = '#'; 
                found = func(board, word, nrow, ncol, ind+1);
                board[nrow][ncol] = temp;
            }   
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(func(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};

//correct solution
class Solution {
public:
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
        if(n == word.size()) return true; 
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
        board[i][j] = '0';
        
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
};