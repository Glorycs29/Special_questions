Dima got into number sequences. Now he's got sequence a1, a2, ..., an, consisting of n positive integers. Also, Dima has got a function f(x), which can be defined with the following recurrence:

f(0) = 0;

f(2·x) = f(x);

f(2·x + 1) = f(x) + 1. 


Dima wonders, how many pairs of indexes (i, j) (1 ≤ i < j ≤ n) are there, such that f(ai) = f(aj). Help him, count the number of such pairs.

Input

The first line contains integer n (1 ≤ n ≤ 105). The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

The numbers in the lines are separated by single spaces.

Output

In a single line print the answer to the problem.

Please, don't use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

- Examples

* inputCopy

  3
  
  1 2 4
* outputCopy
  
  3
* inputCopy
  
  3

  5 3 1
* outputCopy
  
  1
