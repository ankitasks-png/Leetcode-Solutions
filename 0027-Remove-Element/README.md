# LeetCode 27 — Remove Element

## Problem

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` **in-place**.

The order of the remaining elements may be changed.

Return the number of elements in `nums` that are not equal to `val`.

Let the number of remaining elements be `k`.

The first `k` elements of `nums` should contain the elements that are not equal to `val`.

## Examples

### Example 1

```text
Input:
nums = [3,2,2,3]
val = 3

Output:
2

nums = [2,2,_,_]
```

The value `3` occurs twice, so the remaining elements are `[2,2]`.

### Example 2

```text
Input:
nums = [0,1,2,2,3,0,4,2]
val = 2

Output:
5

nums = [0,1,3,0,4,_,_,_]
```

The five elements that are different from `2` are:

```text
[0,1,3,0,4]
```

## Approach

Use a **two-pointer technique**.

Maintain a pointer `k` representing the position where the next valid element should be placed.

Traverse the array using `i`:

* If `nums[i]` is not equal to `val`, copy it to `nums[k]`.
* Increment `k`.
* If `nums[i] == val`, skip it.

After the traversal, `k` represents the number of elements that are not equal to `val`.

## Algorithm

1. Initialize `k = 0`.
2. Traverse every element using index `i`.
3. If `nums[i] != val`:

   * Set `nums[k] = nums[i]`.
   * Increment `k`.
4. Return `k`.

## C++ Implementation

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```

## Complexity

* **Time Complexity:** `O(n)` — every element is visited once.
* **Space Complexity:** `O(1)` — the array is modified in-place.

## Key Concept

**Two Pointers / In-Place Array Modification**

The `i` pointer scans the original array, while `k` keeps track of where the next element that should be retained is placed.

## Tags

`Array` `Two Pointers` `In-Place` `Easy`
