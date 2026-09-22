# LeetCode 686 — Repeated String Match

## Problem

Given two strings `a` and `b`, return the **minimum number of times** `a` needs to be repeated so that `b` becomes a substring of the repeated string.

If it is impossible for `b` to become a substring, return `-1`.

For example:

```text id="c5f4hx"
"a" repeated 0 times = ""
"a" repeated 1 time  = "a"
"a" repeated 2 times = "aa"
```

## Examples

### Example 1

```text id="a8e5pv"
Input:
a = "abcd"
b = "cdabcdab"

Output:
3
```

**Explanation:**

Repeating `a` three times gives:

```text id="c0c5tj"
"abcdabcdabcd"
```

The string `"cdabcdab"` is a substring, so the answer is `3`.

### Example 2

```text id="9j5g8u"
Input:
a = "a"
b = "aa"

Output:
2
```

**Explanation:**

```text id="xg7r8k"
"a" + "a" = "aa"
```

Therefore, `a` must be repeated `2` times.

## Approach

We repeatedly append `a` until the resulting string is at least as long as `b`.

For example:

```text id="b2v0gj"
a = "abcd"
b = "cdabcdab"
```

After two repetitions:

```text id="q0m7rf"
"abcdabcd"
```

This is long enough, but `b` is not completely contained yet.

There is an important edge case: `b` can cross the boundary between two repetitions of `a`.

Therefore, after reaching the required length, we try **one additional repetition**.

If `b` is still not found, it is impossible and we return `-1`.

## Algorithm

1. Initialize an empty string `repeated`.
2. Keep appending `a` until:

   ```text
   repeated.length() >= b.length()
   ```
3. Check whether `b` is a substring of `repeated`.
4. If yes, return the current repetition count.
5. Append `a` one more time.
6. Check again.
7. If `b` is still not found, return `-1`.

## C++ Implementation

```cpp id="5w8r2n"
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;

        // Repeat a until its length is at least b's length
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check with the current number of repetitions
        if (repeated.find(b) != string::npos) {
            return count;
        }

        // One extra repetition may be required
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};
```

## Complexity

Let:

* `n` = length of `a`
* `m` = length of `b`

The repeated string has length `O(n + m)`.

* **Time Complexity:** `O((n + m)²)` in the worst case when considering standard substring-search behavior.
* **Space Complexity:** `O(n + m)` for the repeated string.

## Key Concept

**String Repetition + Substring Search**

The important observation is that we only need to check:

```text
ceil(m / n)
```

repetitions and at most **one additional repetition**.

The extra repetition handles cases where `b` starts near the end of one copy of `a` and continues into the next copy.

## Tags

`String` `String Matching` `Substring` `Simulation` `Medium`
