# LeetCode 58 — Length of Last Word

## Problem

Given a string `s` consisting of words and spaces, return the **length of the last word** in the string.

A word is a maximal substring consisting of non-space characters only.

## Examples

### Example 1

**Input:**

```text
s = "Hello World"
```

**Output:**

```text
5
```

**Explanation:**

The last word is `"World"`, which has a length of `5`.

### Example 2

**Input:**

```text
s = "   fly me   to   the moon  "
```

**Output:**

```text
4
```

**Explanation:**

The last word is `"moon"`, which has a length of `4`.

### Example 3

**Input:**

```text
s = "luffy is still joyboy"
```

**Output:**

```text
6
```

**Explanation:**

The last word is `"joyboy"`, which has a length of `6`.

## Approach

Traverse the string from **right to left**.

1. Skip any spaces at the end of the string.
2. Count characters until a space is encountered.
3. The count is the length of the last word.

This avoids creating extra strings and directly finds the answer.

## Algorithm

1. Set `i` to the last index of the string.
2. Skip trailing spaces.
3. Initialize `length = 0`.
4. While `i` is valid and the current character is not a space:

   * Increment `length`.
   * Move `i` backward.
5. Return `length`.

## C++ Implementation

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

## Key Concept

**Reverse Traversal** — Start from the end, ignore trailing spaces, and count the characters of the last word.

## Tags

`String` `Two Pointers` `Reverse Traversal` `Easy`
