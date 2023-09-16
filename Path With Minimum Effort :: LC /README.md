Certainly! Below is the provided code formatted in Markdown for GitHub:

```cpp
```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;

        minHeap.emplace(0,0,0);
        dist[0][0] = 0;

        int drs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!minHeap.empty()){
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            if(effort > dist[x][y]) continue;
            if(x == r-1 && y == c-1) return effort;

            for(auto& dir : drs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >=0 && nx < r && ny >=0 && ny < c){
                    int new_effort = max(effort, abs(mat[x][y] - mat[nx][ny]));
                    if(new_effort < dist[nx][ny]){
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }    
        return -1;
    }
};
```

## Problem Statement

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

### Examples

#### Example 1:
```plaintext
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells. This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

#### Example 2:
```plaintext
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

#### Example 3:
```plaintext
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

### Constraints
- `rows == heights.length`
- `columns == heights[i].length`
- `1 <= rows, columns <= 100`
- `1 <= heights[i][j] <= 106`
```
