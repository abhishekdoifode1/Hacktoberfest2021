#include<bits/stdc++.h>
using namespace std;
class sudoku {
public:
    bool row[10][10],col[10][10],sqr[10][10],flag=false,single_call=true;
    
    void default_values(vector<vector<char>> board)
    {
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(sqr,false,sizeof(sqr));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
               { 
                    int num=board[i][j]-'0',temp=3*(i/3)+j/3;
                    row[i][num]=true;
                    col[num][j]=true;
                    sqr[temp][num]=true;
                }
                
            }
                
        }
        single_call=false;
    }
    void solve(vector<vector<char>>& board,int u=0,int v=0) {
        if(single_call)
        {
            default_values(board);
        }
        if(flag)
            return;
        
         if(v>=9)
         {
             v=0;
             u=u+1;
         }
        if(u>=9)
        {
            flag=true;
            return;
        }
           if(board[u][v]=='.')
           {
               int temp=3*(u/3)+v/3;
               for(char i='1';i<='9';i++)
               {
                   int num=i-'0';
                   if(!row[u][num] && !col[num][v] && !sqr[temp][num])
                   {
                       row[u][num]=col[num][v]=sqr[temp][num]=true;
                       board[u][v]=i;
                       solve(board,u,v+1);
                       if(flag)
                           return;
                       row[u][num]=col[num][v]=sqr[temp][num]=false;
                       board[u][v]='.';
                   }
               }
           }
           else
            {
                solve(board,u,v+1);
            }
        
    }
    void print_board(vector<vector<char>> board){
        for(auto i:board){
            for(auto j:i)
            cout<<j<<" ";
            cout<<endl;
        }
    }
};
int main()
{
    vector<vector<char>> board = {
                                    {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}
                                };
    sudoku Sudoku ;
    Sudoku.solve(board);
    Sudoku.print_board(board);

    return 0;
}