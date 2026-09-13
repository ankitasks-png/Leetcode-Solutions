# LeetCode 16 — 3Sum Closest

## Problem

Given an integer array `nums` and an integer `target`, find three integers at **distinct indices** whose sum is closest to `target`.

Return the sum of those three integers.

It is guaranteed that there is exactly one solution.

---

## Examples

### Example 1

**Input:**

```text
nums = [-1, 2, 1, -4]
target = 1
```

**Output:**

```text
2
```

Explanation:

```text
-1 + 2 + 1 = 2
```

The sum `2` is closest to the target `1`.

---

### Example 2

**Input:**

```text
nums = [0, 0, 0]
target = 1
```

**Output:**

```text
0
```

Explanation:

```text
0 + 0 + 0 = 0
```

---

## Approach

The problem can be solved efficiently using **Sorting + Two Pointers**.

First, sort the array.

For every element `nums[i]`, treat it as the first element of the triplet. Then use two pointers:

```text
i       left              right
↓        ↓                  ↓
nums[i] nums[left]      nums[right]
```

Calculate the sum of the three elements.

### Pointer Movement

If:

```text
sum < target
```

the sum needs to become larger, so move `left` forward.

If:

```text
sum > target
```

the sum needs to become smaller, so move `right` backward.

If:

```text
sum == target
```

we have found the exact target, so we can immediately return it.

---

## Algorithm

1. Sort `nums`.
2. Initialize `closest` using the first three elements.
3. Iterate through the array with index `i`.
4. Set:

   * `left = i + 1`
   * `right = n - 1`
5. Calculate the current three-element sum.
6. Update `closest` if the current sum is closer to `target`.
7. Move the appropriate pointer:

   * `sum < target` → `left++`
   * `sum > target` → `right--`
8. If `sum == target`, return immediately.
9. Return `closest`.

---

## Example Walkthrough

```text
nums = [-1, 2, 1, -4]
target = 1
```

After sorting:

```text
[-4, -1, 1, 2]
```

One of the combinations considered is:

```text
-1 + 1 + 2 = 2
```

Difference from target:

```text
|2 - 1| = 1
```

This is the closest possible sum.

Therefore:

```text
Answer = 2
```

---

## C++ Implementation

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    return sum;
                }

                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest;
    }
};
```

---

## Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)` auxiliary space

The `O(n²)` complexity comes from fixing one element and performing a two-pointer search over the remaining elements.

---

## Key Concept

The main technique is:

**Sorting + Two Pointers**

Instead of checking every possible triplet in `O(n³)`, sorting allows us to efficiently move the two pointers and reduce the solution to `O(n²)`.

---

## Tags

`#LeetCode` `#C++` `#Array` `#Sorting` `#TwoPointers` `#Medium`
