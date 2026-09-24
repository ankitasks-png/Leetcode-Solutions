# LeetCode 66 — Plus One

## Problem

You are given a large integer represented as an array of digits, where each `digits[i]` is the `i`-th digit of the integer.

The digits are ordered from most significant to least significant.

Increment the large integer by one and return the resulting array of digits.

### Example

**Input:**

```text
digits = [1,2,3]
```

**Output:**

```text
[1,2,4]
```

**Explanation:**
The array represents the number `123`. Adding one gives `124`.

---

## Approach

Start from the **last digit** because addition begins from the least significant digit.

* If the digit is less than `9`, simply increase it by `1` and return.
* If the digit is `9`, change it to `0` and continue to the previous digit.
* If every digit is `9`, all digits become `0`, so insert `1` at the beginning.

This handles cases such as:

```text
[1,2,3] → [1,2,4]
[1,2,9] → [1,3,0]
[9,9,9] → [1,0,0,0]
```

## Algorithm

1. Start from the last index of the array.
2. Traverse the digits from right to left.
3. If the current digit is less than `9`:

   * Increment it.
   * Return the array.
4. If the current digit is `9`:

   * Set it to `0`.
   * Continue to the previous digit.
5. If the loop finishes, insert `1` at the beginning.
6. Return the resulting array.

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` auxiliary space

## Key Concept

**Carry Propagation** — Process the number from right to left, carrying `1` whenever a digit is `9`.

## Tags

`Array` `Math` `Carry` `Easy`
