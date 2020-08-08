/*
*   Solved Simple Variation: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
*   To print all such paths just replace #36 base case to false. as we did in N queen problem to find all possible configuration
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool ratInMaze(char maze[10][10], int soln[][10], int i , int j, int m, int n)
{
    if(i==m || j==n){
        soln[m][n] = 1;
        //Print the Path
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }
    //Rat should be inside grid
    if(i>m || j>n){
        return false;
    }

    if(maze[i][j] == 'X'){
        return false;
    }

    //Assume solution exists through current cell
    soln[i][j] = 1;

    //Recursive Case
    bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n);
    bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);

    //Backtracking
    if(rightSuccess || downSuccess){
        return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char maze[10][10]={"0000",
                       "00X0",
                       "000X",
                       "0X00"};
    int solu[10][10]={0};
    int m = 4, n=4;

    bool ans = ratInMaze(maze, soln, 0, 0, m-1, n-1);

    if(ans == false){
        cout << "Path doesn't exist!";
    }

    return 0;
}
