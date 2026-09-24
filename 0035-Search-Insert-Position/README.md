# LeetCode 35 — Search Insert Position

## Problem

Given a sorted array of distinct integers `nums` and a target value, return the index if the target is found.

If the target is not found, return the index where it would be inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

## Examples

### Example 1

**Input:**

```text
nums = [1,3,5,6]
target = 5
```

**Output:**

```text
2
```

### Example 2

**Input:**

```text
nums = [1,3,5,6]
target = 2
```

**Output:**

```text
1
```

**Explanation:**

`2` should be inserted between `1` and `3`.

### Example 3

**Input:**

```text
nums = [1,3,5,6]
target = 7
```

**Output:**

```text
4
```

**Explanation:**

`7` should be inserted after the last element.

## Approach

Because the array is already sorted, **Binary Search** can be used.

Maintain two pointers:

* `left` — beginning of the search range.
* `right` — end of the search range.

For every iteration:

* If `nums[mid] == target`, return `mid`.
* If `nums[mid] < target`, search the right half.
* If `nums[mid] > target`, search the left half.

If the target is not found, `left` will point to the correct insertion position.

## Algorithm

1. Set `left = 0` and `right = nums.size() - 1`.
2. Calculate the middle index.
3. Compare `nums[mid]` with `target`.
4. Adjust `left` or `right` accordingly.
5. If the target is found, return `mid`.
6. When the loop ends, return `left`.

## C++ Implementation

```cpp id="p8m3kx"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};
```

## Complexity

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

## Key Concept

**Binary Search** — Use the sorted nature of the array to repeatedly eliminate half of the search space.

## Tags

`Array` `Binary Search` `Easy`
