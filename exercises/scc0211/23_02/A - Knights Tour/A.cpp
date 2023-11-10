#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y, int solution_flag) {
  return x < 8 && y < 8 && y >= 0 && x>= 0 && solution_flag == -1;
}

int warnsdorffs(int x, int y, int solution[8][8]){
  int count = 0;
  for(int i = 0; i < 8; i++){
    int next_x = x + dx[i];
    int next_y = y + dy[i];
    if(isValid(next_x, next_y, solution[next_x][next_y]))
      count++;
  }
  return count;
}

bool solve(int x, int y, int move, int solution[8][8]) {
  solution[x][y] = move;
  
  if (move == 8 * 8)
    return true;
  
  int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

  vector<pair<int,int>> counts;
  //Check the number of possibilites
  for (int i = 0; i < 8; i++) {
    int next_x = x + dx[i];
    int next_y = y + dy[i];
    if (isValid(next_x, next_y, solution[next_x][next_y])) {
      int count = warnsdorffs(next_x,next_y,solution);
      counts.push_back(make_pair(count,i));
    }
  }

  //Sort the counts
  sort(counts.begin(), counts.end());
  
  //Doing the tour
  for (auto it : counts) {
    // Test a moviment to each delta
    int next_x = x + dx[it.second];
    int next_y = y + dy[it.second];
    // Verify is valid
    if(solve(next_x, next_y, move + 1, solution))
        return true;
  }
  
  solution[x][y] = -1;
  return false;
}

void knight_solve(int x, int y) {
  int move = 1;
  int solution[8][8];
  memset(solution, -1, sizeof(solution));

  if (solve(x, y, move, solution)) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++){
        /*if(solution[i][j]/10 < 1)
          cout << " ";*/
        cout << solution[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No solution";
  }
}

int main() {
  int x, y;
  cin >> x >> y;
  knight_solve(y - 1, x - 1);
}
