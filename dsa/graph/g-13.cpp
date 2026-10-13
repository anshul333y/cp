#include <bits/stdc++.h>
using namespace std;

// ── 01 Matrix ────────────────────────────────────────────────

// T: O(n*m) S: O(n*m)
class ZeroOneMatrix {
private:
  void bfs(vector<vector<int>> &visited, vector<vector<int>> &mat,
           vector<vector<int>> &ans, queue<pair<pair<int, int>, int>> &que) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!que.empty()) {
      int row = que.front().first.first;
      int col = que.front().first.second;
      int level = que.front().second;
      que.pop();
      ans[row][col] = level;
      for (auto it : dir) {
        int newRow = row + it[0];
        int newCol = col + it[1];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            !visited[newRow][newCol]) {
          visited[newRow][newCol] = 1;
          que.push({{newRow, newCol}, level + 1});
        }
      }
    }
  }

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0)), ans = mat;
    queue<pair<pair<int, int>, int>> que;
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        if (mat[row][col] == 0) {
          visited[row][col] = 1;
          que.push({{row, col}, 0});
        }
      }
    }
    bfs(visited, mat, ans, que);
    return ans;
  }
};
