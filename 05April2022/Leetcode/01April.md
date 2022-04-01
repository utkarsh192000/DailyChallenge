# Explanation:
### Solution 01
Here we’re using **Extra Space** which doesn't satisfy the condition.
- We iterate the array elements from last and push it to the current vector.
- Then we’ll erase the first n elements from the vector and will get out the reverse string.
- Time complexity: **O(n)**.
### Solution 02
Here we’re using the **Two Pointer Approach**.
- We’ll use the swap function which takes O(1) time complexity.
- Take 2 pointers to start & end, swap them and move the pointer.
- Time complexity:**O(n)**.
### Solution 03
Here we’re using **STL** function reverse which takes O(n) time complexity.
Time complexity: **O(n)**.