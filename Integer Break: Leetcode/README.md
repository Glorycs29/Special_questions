

## Algorithm: DP-Top-down

1. If \(n \leq 3\), then return \(n - 1\).
2. Define a memoized function `dp(num)`:
   - Base case: if \(num \leq 3\), then return \(num\).
   - Initialize \(ans = num\). This is the case of not splitting the number at all.
   - Iterate \(i\) from 2 until \(num\):
     - Try to update \(ans\) with \(i \times dp(num - i)\) if it is larger.
   - Return \(ans\).
3. Return `dp(n)`.


## Complexity Analysis

- **Time complexity:** \(O(n^2)\)
  - There are \(O(n)\) possible states of `num` that `dp` can be called with. Due to memoization, we only calculate each state once. To calculate a state, we iterate from 2 until `num`, which costs up to \(O(n)\). Thus, we have a time complexity of \(O(n^2)\).

- **Space complexity:** \(O(n)\)
  - The recursion call stack can grow up to \(O(n)\). Also, we require \(O(n)\) space to memoize the function.


