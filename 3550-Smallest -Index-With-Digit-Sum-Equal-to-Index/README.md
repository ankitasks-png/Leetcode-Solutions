# LeetCode 3550 — Smallest Index With Digit Sum Equal to Index

## Problem

You are given an integer array `nums`.

Return the **smallest index** `i` such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

## Examples

### Example 1

```text
Input:
nums = [1,3,2]

Output:
2
```

**Explanation:**

For index `2`:

```text
nums[2] = 2
```

The digit sum is:

```text
2
```

which is equal to the index `2`.

Therefore, the answer is `2`.

### Example 2

```text
Input:
nums = [1,10,11]

Output:
1
```

**Explanation:**

For index `1`:

```text
nums[1] = 10
```

Digit sum:

```text
1 + 0 = 1
```

which equals the index.

Although index `2` also satisfies the condition:

```text
1 + 1 = 2
```

we return `1` because it is the **smallest valid index**.

### Example 3

```text
Input:
nums = [1,2,3]

Output:
-1
```

No index has a digit sum equal to its index.

## Approach

Traverse the array from left to right.

For every index `i`:

1. Take `nums[i]`.
2. Calculate its digit sum by repeatedly extracting the last digit.
3. Compare the digit sum with `i`.
4. Since we traverse from the smallest index, the first match is automatically the answer.

If no index satisfies the condition, return `-1`.

## Algorithm

1. Loop through every index `i`.
2. Set `num = nums[i]` and `digitSum = 0`.
3. While `num > 0`:

   * Extract the last digit using `num % 10`.
   * Add it to `digitSum`.
   * Remove the last digit using `num /= 10`.
4. If `digitSum == i`, return `i`.
5. After checking all elements, return `-1`.

## C++ Implementation

```cpp
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int digitSum = 0;

            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }

            if (digitSum == i) {
                return i;
            }
        }

        return -1;
    }
};
```

## Complexity

Let `n` be the number of elements and `d` be the maximum number of digits in an element.

* **Time Complexity:** `O(n × d)`
* **Space Complexity:** `O(1)`

Since `nums[i] <= 1000`, each number has at most 4 digits, making this effectively `O(n)`.

## Key Concept

**Digit Manipulation + Linear Search**

The digits of a number can be extracted using:

```text
num % 10
```

and the last digit can be removed using:

```text
num /= 10
```

Because the array is traversed from left to right, the first matching index is guaranteed to be the smallest.

## Tags

`Array` `Math` `Digit Manipulation` `Easy`
