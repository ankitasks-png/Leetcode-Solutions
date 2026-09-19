# LeetCode 9 — Palindrome Number

## Problem

Given an integer `x`, return `true` if `x` is a **palindrome**, and `false` otherwise.

A palindrome number reads the same from left to right and right to left.

The solution should be implemented **without converting the integer to a string**.

---

## Examples

### Example 1

**Input:**

```text
x = 121
```

**Output:**

```text
true
```

**Explanation:**

`121` reads as `121` from both left to right and right to left.

---

### Example 2

**Input:**

```text
x = -121
```

**Output:**

```text
false
```

**Explanation:**

From left to right, the number is `-121`.

From right to left, it becomes `121-`.

Therefore, it is not a palindrome.

---

### Example 3

**Input:**

```text
x = 10
```

**Output:**

```text
false
```

**Explanation:**

Reading `10` from right to left gives `01`, which is not the same number.

---

## Approach

### Reverse the Integer

Instead of converting the number into a string, we reverse its digits mathematically.

For every iteration:

1. Extract the last digit using:

   ```text
   digit = x % 10
   ```
2. Add the digit to the reversed number:

   ```text
   reversed = reversed × 10 + digit
   ```
3. Remove the last digit from `x`:

   ```text
   x = x / 10
   ```

After reversing all the digits, compare the reversed number with the original number.

If they are equal, the number is a palindrome.

---

## Algorithm

1. If `x < 0`, return `false`.
2. Store the original value of `x`.
3. Initialize `reversed = 0`.
4. While `x > 0`:

   * Extract the last digit.
   * Append it to `reversed`.
   * Remove the last digit from `x`.
5. Compare `original` and `reversed`.
6. Return `true` if they are equal; otherwise return `false`.

---

## C++ Implementation

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes
        if (x < 0) {
            return false;
        }

        int original = x;
        long long reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};
```

---

## Complexity

Let `d` be the number of digits in `x`.

* **Time Complexity:** `O(d)` or `O(log x)`
* **Space Complexity:** `O(1)`

The algorithm uses only a few variables and does not create a string or another data structure.

---

## Key Concept

The key concept is **digit manipulation using modulo and division**.

```text
x % 10
```

extracts the last digit, while:

```text
x / 10
```

removes the last digit.

For example:

```text
x = 121

121 % 10 = 1
121 / 10 = 12

12 % 10 = 2
12 / 10 = 1

1 % 10 = 1
1 / 10 = 0
```

The reversed number becomes `121`, which matches the original number.

---

## Tags

`Math` `Number` `Palindrome` `Digit Manipulation`
