# LeetCode 2996 — Smallest Missing Integer Greater Than Sequential Prefix Sum

## Problem

You are given a **0-indexed** array of integers `nums`.

A prefix `nums[0..i]` is called **sequential** if:

```text
nums[j] = nums[j - 1] + 1
```

for every `1 <= j <= i`.

The prefix containing only `nums[0]` is always sequential.

Return the **smallest integer** `x` that:

* Is greater than or equal to the sum of the longest sequential prefix.
* Does not appear in `nums`.

## Examples

### Example 1

```text
Input:
nums = [1,2,3,2,5]

Output:
6
```

**Explanation:**

The longest sequential prefix is:

```text
[1,2,3]
```

Its sum is:

```text
1 + 2 + 3 = 6
```

Since `6` is not present in the array, the answer is `6`.

### Example 2

```text
Input:
nums = [3,4,5,1,12,14,13]

Output:
15
```

**Explanation:**

The longest sequential prefix is:

```text
[3,4,5]
```

Its sum is:

```text
3 + 4 + 5 = 12
```

The values `12`, `13`, and `14` are present in the array. Therefore, the smallest missing integer greater than or equal to `12` is `15`.

## Approach

The solution can be divided into two steps:

1. Find the longest sequential prefix and calculate its sum.
2. Starting from this sum, find the smallest integer that does not exist in the array.

For the first step, compare each element with the previous element plus one. Stop as soon as the sequence is broken.

For the second step, check whether the current candidate exists in `nums`. If it exists, increment the candidate and continue searching.

## Algorithm

1. Initialize `sum` with `nums[0]`.
2. Traverse the array from index `1`.
3. If `nums[i] == nums[i - 1] + 1`, add `nums[i]` to `sum`.
4. Otherwise, stop because the sequential prefix has ended.
5. Use `sum` as the initial candidate.
6. Check whether the candidate exists in the array.
7. If it exists, increment the candidate.
8. Otherwise, return the candidate.

## C++ Implementation

```cpp
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find the longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find the smallest missing integer >= sum
        while (true) {
            bool found = false;

            for (int num : nums) {
                if (num == sum) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return sum;
            }

            sum++;
        }
    }
};
```

## Complexity

Let `n` be the number of elements in `nums`.

* **Time Complexity:** `O(n²)` in the worst case. Finding the sequential prefix takes `O(n)`, and checking candidate values can take `O(n)` for each candidate.
* **Space Complexity:** `O(1)` auxiliary space because only a few variables are used.

## Key Concept

**Sequential Prefix + Linear Search**

The longest sequential prefix is found by checking consecutive elements. After calculating its sum, linear search is used to find the first missing integer.

## Tags

`Array` `Sequential Prefix` `Greedy` `Linear Search` `Easy`
