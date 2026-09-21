# LeetCode 14 — Longest Common Prefix

## Problem

Write a function to find the **longest common prefix** string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

A prefix is a sequence of characters that appears at the beginning of every string.

---

## Examples

### Example 1

**Input:**

```text id="p9j5ha"
strs = ["flower", "flow", "flight"]
```

**Output:**

```text id="0ol6kk"
"fl"
```

**Explanation:**

The strings are:

```text id="qj9n2g"
flower
flow
flight
```

The longest sequence of characters shared by all three strings is:

```text id="1f2d89"
fl
```

---

### Example 2

**Input:**

```text id="m7jp2c"
strs = ["dog", "racecar", "car"]
```

**Output:**

```text id="q0l4z7"
""
```

**Explanation:**

There is no common prefix among the three strings.

---

## Approach

### Horizontal Scanning

Start by assuming that the first string is the longest common prefix.

Then compare it with every other string one by one.

For each string:

1. Compare characters from the beginning.
2. Stop when two characters are different or one string ends.
3. Keep only the matching portion as the new prefix.
4. If the prefix becomes empty, return `""`.

For example:

```text id="4y1w29"
["flower", "flow", "flight"]
```

Initially:

```text id="8h6u8v"
prefix = "flower"
```

After comparing with `"flow"`:

```text id="f7k5kg"
prefix = "flow"
```

After comparing with `"flight"`:

```text id="t8wqhz"
prefix = "fl"
```

Therefore, the answer is:

```text id="r5tq9g"
"fl"
```

---

## Algorithm

1. Set `prefix` to the first string.
2. Iterate through the remaining strings.
3. Compare `prefix` with the current string character by character.
4. Find the length of their matching prefix.
5. Update `prefix` using the matching characters.
6. If `prefix` becomes empty, return `""`.
7. After checking all strings, return `prefix`.

---

## C++ Implementation

```cpp id="6xkq3p"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            while (j < prefix.size() &&
                   j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty()) {
                return "";
            }
        }

        return prefix;
    }
};
```

---

## Complexity

Let:

* `n` = number of strings
* `m` = length of the shortest string

In the worst case, we compare up to `m` characters across `n` strings.

* **Time Complexity:** `O(n × m)`
* **Space Complexity:** `O(m)`

---

## Key Concept

The key idea is **horizontal scanning**.

Instead of comparing every possible prefix, we continuously shorten the current prefix until it matches every string.

```text id="t6dy0w"
flower
  ↓
flow
  ↓
fl
```

The remaining prefix after checking all strings is the **Longest Common Prefix**.

---

## Tags

`Array` `String` `String Matching`
