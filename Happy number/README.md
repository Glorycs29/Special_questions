<code>

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1

</code>


```

class Solution {
public:
// we can simply adapt the Floyd Cycle detection algorithm. I believe that many people have seen this in the Linked List Cycle detection problem. 
    int digitSquareSum(int n){
        int sum=0, tmp;
        while(n){
            tmp = n%10;
            sum += tmp*tmp;
            n/=10;
        }
        return sum;
    }


    bool isHappy(int n) {
       int slow,fast;
       slow=fast=n;
       do{
           slow = digitSquareSum(slow);
           fast = digitSquareSum(fast);
           fast = digitSquareSum(fast);
       } while(slow!=fast);
           if(slow==1)return 1;
           else return 0;
    }
};

```
