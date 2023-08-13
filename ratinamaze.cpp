#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, int row, int col, int arr[][4],
 vector<vector<bool> > &visited) {
  if( ((x>=0 && x < row) && (y >= 0 && y < col)) &&
      (arr[x][y] == 1 ) &&
      (visited[x][y]==false)) {
    return true;
  }
  else {
    return false;
  }
}

void solveMaze(int arr[][4], int row,int col, int x, int y,
vector<vector<bool> > &visited, vector<string>& path, string output  ) {

  //base case
  if(x == row-1 && y == col-1) {
    //answer found
    path.push_back(output);
    return;
  } 

  //Down -> x+1, y
  if(isSafe(x+1, y, row, col, arr, visited)) {
    visited[x+1][y] = true;
    solveMaze(arr, row, col, x+1, y, visited, path, output + 'D');
    //backtrack 
    visited[x+1][y] = false;
  }

  //Left -> x, y-1
  if(isSafe(x, y-1, row, col, arr, visited)) {
    visited[x][y-1] = true;
    solveMaze(arr, row, col, x, y-1, visited, path, output + 'L');
    //backtrack 
    visited[x][y-1] = false;
  }

  //Right -> x, y+1
  if(isSafe(x, y+1, row, col, arr, visited)) {
    visited[x][y+1] = true;
    solveMaze(arr, row, col, x, y+1, visited, path, output + 'R');
    //backtrack 
    visited[x][y+1] = false;
  }

  //Up-> x-1, y
if(isSafe(x-1, y, row, col, arr, visited)) {
    visited[x-1][y] = true;
    solveMaze(arr, row, col, x-1, y, visited, path, output + 'U');
    //backtrack 
    visited[x-1][y] = false;
  }


}

int main() {
  int maze[4][4] = { {1,0,0,0}, 
                {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};

  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }

  int row = 4;
  int col = 4;

  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //src ki value k true mark kredete h 
  visited[0][0] = true;

  vector<string> path;
  string output = "";

  solveMaze(maze,row,col, 0,0, visited, path, output);

  cout << "printing the results " << endl;
  for(auto x: path) {
    cout << x << " ";
  }
  cout << endl;
  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }

  
  return 0;
}