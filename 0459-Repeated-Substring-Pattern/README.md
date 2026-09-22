# LeetCode 459 — Repeated Substring Pattern

## Problem

Given a string `s`, determine whether it can be constructed by taking a **substring of `s`** and appending multiple copies of that substring together.

Return `true` if such a pattern exists, otherwise return `false`.

## Examples

### Example 1

```text
Input:
s = "abab"

Output:
true
```

**Explanation:**

The string can be constructed by repeating `"ab"`:

```text
"ab" + "ab" = "abab"
```

### Example 2

```text
Input:
s = "aba"

Output:
false
```

**Explanation:**

There is no substring that can be repeated to form `"aba"`.

### Example 3

```text
Input:
s = "abcabcabcabc"

Output:
true
```

**Explanation:**

The string can be constructed using:

```text
"abc" + "abc" + "abc" + "abc"
```

or:

```text
"abcabc" + "abcabc"
```

## Approach

If a string is formed by repeating a substring, the length of that substring must **divide the total length** of the string.

For example:

```text
s = "ababab"
```

The length is `6`.

Possible repeating substring lengths include:

```text
1, 2, 3
```

We try every possible substring length from `1` to `n / 2`.

For each length:

1. Check whether `n` is divisible by the length.
2. Compare every character with the character at the corresponding position in the repeating substring.
3. If all characters match, return `true`.

If no repeating pattern is found, return `false`.

## Algorithm

1. Let `n` be the length of `s`.
2. Try every possible substring length `len` from `1` to `n / 2`.
3. If `n % len != 0`, skip this length.
4. Compare:

   ```text
   s[i] == s[i % len]
   ```

   for every `i` from `len` to `n - 1`.
5. If all characters match, return `true`.
6. If no length works, return `false`.

## C++ Implementation

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0) {
                continue;
            }

            bool valid = true;

            for (int i = len; i < n; i++) {
                if (s[i] != s[i % len]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                return true;
            }
        }

        return false;
    }
};
```

## Complexity

Let `n` be the length of `s`.

* **Time Complexity:** `O(n²)` in the worst case.
* **Space Complexity:** `O(1)`.

## Key Concept

**String Matching + Divisibility**

A repeated substring must have a length that divides the total string length.

The expression:

```text
s[i % len]
```

allows us to compare each character against the corresponding character in the repeating pattern without explicitly constructing the repeated string.

## Tags

`String` `String Matching` `Pattern Matching` `Easy`
