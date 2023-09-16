
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



----

### Step-by-Step Explanation:

1. **Function Signature:**
  

2. **Initialize Variables:**
   - `r` and `c` are initialized to the number of rows and columns in the given matrix `mat`.
   - `dist` is a 2D vector initialized with maximum integer values, representing the effort needed to reach each cell.
   - `minHeap` is a priority queue of tuples representing (effort, x-coordinate, y-coordinate), sorted by effort in ascending order.
   - `drs` is an array representing the four possible directions: right, left, down, and up.

3. **Push the Starting Point to the Heap and Update Distance:**
   - The starting point (0, 0) is pushed onto the heap with an effort of 0, and the distance to reach this point is updated to 0 in `dist`.

4. **Dijkstra's Algorithm using Priority Queue:**
   - The code utilizes Dijkstra's algorithm to find the minimum effort path.
   - While the heap is not empty, pop the element with the minimum effort.
   - If the effort to reach the current cell is greater than the effort stored in `dist`, continue to the next iteration.
   - If the current cell is the bottom-right cell, return the effort to reach this cell.
   - Iterate through the four possible directions and update the effort and distance for each neighboring cell accordingly.
   
5. **Return -1 if No Valid Path Found:**
   - If the function reaches this point, it means there is no valid path to reach the bottom-right cell, so -1 is returned.

The algorithm finds the minimum effort path by exploring cells in a way that minimizes the maximum absolute difference in heights between consecutive cells along the path, effectively solving the given problem.

---



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
