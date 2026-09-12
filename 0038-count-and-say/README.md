# LeetCode 38 — Count and Say

## Problem

The **Count and Say** sequence is a sequence of digit strings defined recursively.

The first element is:

```text
countAndSay(1) = "1"
```

For every following element, we describe the previous string using **run-length encoding (RLE)**.

Run-length encoding replaces consecutive identical characters with:

```text
count + character
```

For example:

```text
"3322251"
```

can be described as:

```text
33    → two 3s   → "23"
222   → three 2s → "32"
5     → one 5    → "15"
1     → one 1    → "11"
```

Therefore:

```text
"3322251" → "23321511"
```

---

## Examples

### Example 1

**Input:**

```text
n = 4
```

**Sequence:**

```text
countAndSay(1) = "1"
countAndSay(2) = "11"
countAndSay(3) = "21"
countAndSay(4) = "1211"
```

**Output:**

```text
"1211"
```

### Example 2

**Input:**

```text
n = 1
```

**Output:**

```text
"1"
```

---

## Approach

We solve the problem **iteratively**.

Instead of using recursion, we start with:

```text
result = "1"
```

Then generate the next sequence element one at a time until we reach `n`.

For each string:

1. Start from the first character.
2. Count how many consecutive times that character appears.
3. Append the count followed by the character.
4. Move to the next group of characters.
5. Repeat until the entire string is processed.
6. Use the generated string as the input for the next iteration.

---

## Example Walkthrough

Suppose:

```text
n = 5
```

Start:

```text
"1"
```

### Step 1

```text
"1"
```

There is one `1`:

```text
"11"
```

### Step 2

```text
"11"
```

There are two `1`s:

```text
"21"
```

### Step 3

```text
"21"
```

There is one `2` and one `1`:

```text
"1211"
```

### Step 4

```text
"1211"
```

There is:

```text
one 1
one 2
two 1s
```

Therefore:

```text
"111221"
```

So:

```text
countAndSay(5) = "111221"
```

---

## Algorithm

```text
result = "1"

for i = 2 to n:

    next = ""

    scan result from left to right

    for each group of identical characters:
        count the characters
        append count + character to next

    result = next

return result
```

---

## C++ Implementation

```cpp
class Solution {
public:
    string countAndSay(int n) {

        string result = "1";

        for (int i = 2; i <= n; i++) {

            string next = "";

            int j = 0;

            while (j < result.length()) {

                int count = 0;
                char current = result[j];

                // Count consecutive identical characters
                while (j < result.length() && result[j] == current) {
                    count++;
                    j++;
                }

                // Append count followed by the character
                next += to_string(count);
                next += current;
            }

            result = next;
        }

        return result;
    }
};
```

---

## Complexity

Let `L` be the length of the generated string.

For each iteration, we scan the current string once.

* **Time:** `O(n × L)` approximately
* **Space:** `O(L)`

Since `n <= 30`, this iterative approach is easily fast enough.

---

## Key Concept

The main idea is **Run-Length Encoding (RLE)**:

```text
"111221"
```

becomes:

```text
"31" + "22" + "11"
```

which gives:

```text
"312211"
```

The important thing is that we count **consecutive** identical digits, not the total number of occurrences of each digit.

---

## Tags

`#LeetCode` `#C++` `#Strings` `#RunLengthEncoding` `#Iteration` `#Medium`
