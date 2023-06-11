#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
  int row=0;
  int col=0;
  int lastrow=n-1;
  int lastcol=m-1;
  while(row<lastrow && col<lastcol)
  {
     
     int prev=mat[row+1][col];
     for(int i=col;i<=lastcol;i++)
     {
         int curr=mat[row][i];
         mat[row][i]=prev;
         prev=curr;
     }
     row++;
     for(int i=row;i<=lastrow;i++)
     {
          int curr=mat[i][lastcol];
         mat[i][lastcol]=prev;
         prev=curr;
     }
     lastcol--;
     for(int i=lastcol;i>=col;i--)
     {
         int curr=mat[lastrow][i];
         mat[lastrow][i]=prev;
         prev=curr;
     }
     lastrow--;
      for(int i=lastrow;i>=row;i--)
     {
         int curr=mat[i][col];
         mat[i][col]=prev;
         prev=curr;
     }
     col++;

  }
 

}