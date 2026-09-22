# LeetCode 28 — Find the Index of the First Occurrence in a String

## Problem

Given two strings `needle` and `haystack`, return the index of the **first occurrence** of `needle` in `haystack`.

If `needle` is not present in `haystack`, return `-1`.

## Examples

### Example 1

```text
Input:
haystack = "sadbutsad"
needle = "sad"

Output:
0
```

**Explanation:**

The string `"sad"` occurs at indices `0` and `6`.

The first occurrence is at index `0`.

### Example 2

```text
Input:
haystack = "leetcode"
needle = "leeto"

Output:
-1
```

**Explanation:**

`"leeto"` does not occur in `"leetcode"`, so we return `-1`.

## Approach

We can check every possible starting position of `needle` inside `haystack`.

For each position:

1. Compare the characters of `needle` with the corresponding characters in `haystack`.
2. If all characters match, return the current starting index.
3. If a mismatch occurs, move to the next starting position.
4. If no position matches, return `-1`.

Since `needle` has length `m`, the last possible starting position is:

```text
n - m
```

where `n` is the length of `haystack`.

## Algorithm

1. Store the lengths of `haystack` and `needle`.
2. Loop from `i = 0` to `i <= n - m`.
3. Set `j = 0`.
4. Compare:

   ```text
   haystack[i + j] == needle[j]
   ```
5. Continue while the characters match.
6. If `j == m`, the entire `needle` has been matched, so return `i`.
7. If no match is found, return `-1`.

## C++ Implementation

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};
```

## Complexity

Let:

* `n` = length of `haystack`

* `m` = length of `needle`

* **Time Complexity:** `O(n × m)` in the worst case.

* **Space Complexity:** `O(1)`.

## Key Concept

**String Matching**

The solution checks each possible starting position and compares the characters of `needle` with the corresponding portion of `haystack`.

## Tags

`String` `String Matching` `Two Pointers` `Easy`
