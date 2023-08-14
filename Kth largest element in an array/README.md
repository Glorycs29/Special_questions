<code>

# STL
This problem needs to use partial sorting. In STL, there are two built-in functions (nth_element and partial_sort) for this.
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```
Note the off-by-1 difference in the second argument of the two built-in functions.

We may also use a heap to solve this problem. We can maintain the largest k elements in a heap with the smallest among them at the top. Or we can add all the elements to a heap, with the largest at the top, and then pop the heap for k - 1 times, then the one on the top is our target. The first one is min-heap and the second one is max-heap. In STL, both priority_queue and multiset can be used as a min/max-heap.

# min-heap using priority_queue
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
```
# max-heap using priority_queue
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
```
# min-heap using multiset
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        for (int num : nums) {
            mset.insert(num);
            if (mset.size() > k) {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }
};
```
# max-heap using multiset
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mset(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};
```
# Partition
The partition subroutine of quicksort can also be used to solve this problem. In partition, we divide the array into

elements>=pivot pivot elements<=pivot
Then, according to the index of pivot, we will know whther the kth largest element is to the left or right of pivot or just itself.

In average, this algorithm reduces the size of the problem by approximately one half after each partition, giving the recurrence T(n) = T(n/2) + O(n) with O(n) being the time for partition. The solution is T(n) = O(n), which means we have found an average linear-time solution. However, in the worst case, the recurrence will become T(n) = T(n - 1) + O(n) and T(n) = O(n^2).
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
```
# Heapsort
In the above we have presented heap solutions using STL. You may also implement your own heap if you are interested. I suggest you to read the Heapsort chapter of Introduction to Algorithms if you are not familiar with it. The following code implements a max-heap.
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i) {
        return (i << 1) + 1;
    }
    
    int right(int i) {
        return (i << 1) + 2;
    }
    
    void maxHeapify(vector<int>& nums, int i) {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            maxHeapify(nums, i);
        }
    }
};
```

# Quick Select :
Also known as **Hoare's selection algorithm**, is an algorithm for finding the kth smallest element in an unordered list. It is significant because it has an average runtime of O(n).

Quickselect uses the same idea as Quicksort. First, we choose a pivot index. The most common way to choose the pivot is random. We partition nums into 3 sections: elements equal to the pivot, elements greater than the pivot, and elements less than the pivot.

Next, we count the elements in each section. Let's denote the sections as follows:

left is the section with elements less than the pivot
mid is the section with elements equal to the pivot
right is the section with elements greater than the pivot
Quickselect is normally used to find the kth 
th
  smallest element, but we want the kth
th
  largest. To account for this, we will swap what left and right represent - left will be the section with elements greater than the pivot and right will be the section with elements less than the pivot.

If the number of elements in left is greater than or equal to k, the answer must be in left - any other element would be less than the kth
  largest element. We restart the process in left.



If the number of elements in left and mid is less than k, the answer must be in right - any element in left or mid would not be large enough to be the kth
  largest element. We restart the process in right.



There's one extra step if the answer is in right. When we go to search in right, we are effectively "deleting" the elements in left and mid (since they will never be considered again). Because the elements in left and mid are greater than the answer, deleting them means we must shift k. Let's say we're looking for the 8th
  greatest element, but then we delete the 4 greatest elements. In the remaining data, we would be looking for the 4th
th
  greatest element, not the 8th
th
 . Therefore, we need to subtract the length of left and mid from k when we search in right.

We don't need to modify k when we search in left because when we search in left, we delete elements smaller than the answer, which doesn't affect k.



If the answer is in neither left or right, it must be in mid. Since mid only has elements equal to the pivot, the pivot must be the answer.

The easiest way to implement this repetitive process is by using recursion.

Algorithm

Note: The implementation we use here is not a standard Quickselect implementation. We will be using slightly more space (still the same complexity), but in exchange, we will be writing significantly less code.

Define a quickSelect function that takes arguments nums and k. This function will return the kth the greatest element in nums (the nums and k given to it as input, not the original nums and k).

Select a random element as the pivot.
Create left, mid, and right as described above.
If k <= left.length, return quickSelect(left, k).
If left.length + mid.length < k, return quickSelect(right, k - left.length - mid.length).
Otherwise, return pivot.
Call quickSelect with the original nums and k, and return the answer.

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k);
    }

    int quickSelect(vector<int>& nums, int k){
        int pivot = nums[rand()%nums.size()];
        vector<int> left, right, mid;

         for (int num: nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        if(k <= left.size()){
            return quickSelect(left,k);
        }
        if(k > left.size() + mid.size()){
            return quickSelect(right, k-left.size()-mid.size());
        }
        return pivot;
    }
};

```

</code>
