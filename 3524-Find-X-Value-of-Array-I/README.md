# LeetCode 3524 — Find X Value of Array I

## Problem

You are given an array of **positive** integers `nums` and a **positive** integer `k`.

You can perform one operation where you remove a **non-overlapping prefix and suffix** from `nums`, while keeping `nums` non-empty.

The **x-value** of `nums` is the number of ways to perform this operation such that the product of the remaining elements leaves a remainder of `x` when divided by `k`.

Return an array `result` of size `k`, where:

```text
result[x] = number of operations whose remaining product has remainder x
```

for:

```text
0 <= x < k
```

The prefix and suffix may also be empty.

---

## Key Observation

After removing a prefix and a suffix, the remaining elements always form a **non-empty contiguous subarray**.

Therefore, the problem is equivalent to:

> Count the product remainder modulo `k` for every non-empty contiguous subarray.

Since `k <= 5`, we can maintain the number of subarrays for each possible remainder using dynamic programming.

---

## Examples

### Example 1

**Input:**

```text
nums = [1,2,3,4,5]
k = 3
```

**Output:**

```text
[9,2,4]
```

There are:

* `9` subarrays whose product has remainder `0`
* `2` subarrays whose product has remainder `1`
* `4` subarrays whose product has remainder `2`

---

### Example 2

**Input:**

```text
nums = [1,2,4,8,16,32]
k = 4
```

**Output:**

```text
[18,1,2,0]
```

---

### Example 3

**Input:**

```text
nums = [1,1,2,1,1]
k = 2
```

**Output:**

```text
[9,6]
```

---

## Approach

### Dynamic Programming on Product Remainders

We maintain:

```text
dp[r]
```

where `dp[r]` represents the number of **non-empty contiguous subarrays ending at the previous position** whose product has remainder `r` modulo `k`.

For every new number:

```text
value = nums[i] % k
```

we perform two operations.

### 1. Start a New Subarray

The current number itself forms a new subarray.

Its product remainder is:

```text
value
```

So:

```text
next[value]++
```

### 2. Extend Previous Subarrays

For every previous remainder `r`, append the current number.

The new product remainder becomes:

```text
(r * value) % k
```

Therefore:

```text
next[(r * value) % k] += dp[r]
```

After processing the current number, `next` becomes the new `dp`.

All values in `dp` are then added to `result`.

---

## Algorithm

1. Initialize `result` with `k` zeros.
2. Initialize `dp` with `k` zeros.
3. For every number in `nums`:

   * Calculate `value = nums[i] % k`.
   * Create a new frequency array `next`.
   * Count the single-element subarray.
   * Extend every previous subarray using:

     ```text
     (remainder × value) % k
     ```
   * Set `dp = next`.
   * Add `dp` to `result`.
4. Return `result`.

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);

            int value = num % k;

            // Subarray containing only the current element
            next[value]++;

            // Extend every previous subarray
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * value) % k;
                    next[newRemainder] += dp[r];
                }
            }

            dp = next;

            // Add all subarrays ending at the current position
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};
```

---

## Complexity

Let `n` be the length of `nums`.

Since we maintain only `k` possible remainders:

* **Time Complexity:** `O(n × k)`
* **Space Complexity:** `O(k)`

Because `k <= 5`, the algorithm is effectively **O(n)**.

---

## Key Concept

The key idea is to convert the prefix/suffix operation into a **contiguous subarray problem**.

Every possible remaining array is a unique non-empty contiguous subarray:

```text
nums[l ... r]
```

We don't need to calculate the actual product because only its remainder modulo `k` matters.

The remainder can be updated efficiently using:

```text
new remainder = (old remainder × current value) % k
```

Using DP over the possible remainders allows us to count all subarrays without explicitly generating them.

---

## Tags

`Array` `Dynamic Programming` `Prefix` `Subarray` `Modulo` `Counting`
