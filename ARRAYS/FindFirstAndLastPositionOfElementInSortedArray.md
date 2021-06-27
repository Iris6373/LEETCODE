# Problem

[34.  Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/)


# Problem Description

```
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
 
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

# Solution

## 1) BRUTE FORCE

   Traverse the array to find first and last occurrence of the element `t`.
   Return the indices in a vector if found, else return `{-1,-1}`
      
   Time Complexity  : O(N)   Since we traverse the array once.
   
   Space Complexity : O(1)   Since no auxillary space is used.

## 2) Modified Binary Search

   Perform a `binary search` on the array to find the leftmost `t`
   Inorder to do that, we move to the left once 't' is found
      
   Similarly, perform a binary search on the array to find the rightmost `t`
   Alternatively, we move to the right once `t` is found
      
     
   ### Code (.cpp)
      
      class Solution {
      public:
          vector<int> searchRange(vector<int>& v, int t) {
              vector<int> ans;
              if (v.size() == 0) return {-1,-1};
              // Search for the left most 't' by modified binary search
              // If mid element is t, we move towards left, inorder to find the left most one
              int i, l=0, h=v.size()-1, m=0, a=-1;
              while (l <= h) {
                  m = l + (h-l)/2;
                  if (v[m] == t) {
                      a = m;
                      h = m-1;    
                  }
                  else if (v[m] < t) l = m+1;
                  else h = m-1;
              }

              // If even 1 instance of t is not found, then we can return {-1,-1}
              if (a != -1) ans.push_back(a);
              else return {-1,-1};

              // Search for the right most 't' by modified binary search
              // If mid element is t, we move towards rightt, inorder to find the right most one
              l=0, h=v.size()-1, m=0, a=-1;
              while (l <= h) {
                  m = l + (h-l)/2;
                  if (v[m] == t) {
                      a = m;
                      l = m+1;    
                  }
                  else if (v[m] < t) l = m+1;
                  else h = m-1;
              }

              ans.push_back(a);
              return ans;
          }
      };

      //Below code improves IO runtime
      static const int _ = []() {
          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
          return 0;
      }();
   
      
   Time Complexity  : O(log(N))   Since we use binary search twice on the array.
   
   Space Complexity : O(1)   Since no auxillary space is used.
      
      
      
## 3) Binary Search using STL lower_bound

   Using `lower_bound` function, find the leftmost `t` and leftmost `t+1`
       
   lower_bound : 
          ARRAY  :  `int res = binary_search(a, a+n, x) - a;`		
          VECTOR :  `int res = binary_search(a.begin(), a.end(), x) - a.begin();`
      If x found, returns index of first occurrence of x
      Else, return index of next greater element of x
	    If x is lesser than the smallest element in array, it returns `0`
	    If x is greater than the largest element in array, it returns `n` or `a.end()`.
        
        
   ### Code (.cpp)     
        
      class Solution {
      public:
          vector<int> searchRange(vector<int>& a, int x) {
              int n = a.size();
              if (n == 0) return {-1,-1};
              int b = lower_bound(a.begin(), a.end(), x) - a.begin();
              int c = lower_bound(a.begin(), a.end(), x+1) - a.begin();
              if (b == n || a[b] != x) return {-1,-1};
              else return {b,c-1};
          }
      };
        
    
   Time Complexity  : O(log(N))   Since lower_bound takes O(log(N)) time to find the element
   
   Space Complexity : O(1)   Since no auxillary space is used.
