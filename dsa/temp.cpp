#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> uf;
    vector<int> rank;

    // Find the root of x.
    int find(int x) {
        if (x != uf[x]) {
            uf[x] = find(uf[x]);
        }
        return uf[x];
    }
    // Union the root of x and y
    void uni(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                uf[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                uf[rootX] = rootY;
            } else {
                uf[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    int maximumMinimumPath(vector<vector<int>> &grid) {
        int R = grid.size(), C = grid[0].size();

        vector<vector<int>> vals;
        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        rank = vector<int>(R * C, 1);
        uf = vector<int>(R * C, 0);

        vector<vector<bool>> visited(R, vector<bool>(C));

        for (int row = 0; row < R; ++row) {
            for (int col = 0; col < C; ++col) {
                uf[row * C + col] = row * C + col;
                vals.push_back({grid[row][col], row, col});
            }
        }

        sort(vals.begin(), vals.end(), greater<vector<int>>());

        for (vector<int> &curGrid : vals) {
            int curRow = curGrid[1], curCol = curGrid[2];
            int curPos = curRow * C + curCol;

            // Mark the current cell as visited.
            visited[curRow][curCol] = true;
            for (vector<int> dir : dirs) {
                int newRow = curRow + dir[0], newCol = curCol + dir[1];
                int newPos = newRow * C + newCol;

                if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C && visited[newRow][newCol]) {
                    uni(curPos, newPos);
                }
            }
            if (find(0) == find(R * C - 1)) {
                return grid[curRow][curCol];
            }
        }
        return 0;
    }
};