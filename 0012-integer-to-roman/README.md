# LeetCode 12 — Integer to Roman

## Problem

Given an integer, convert it into its corresponding **Roman numeral**.

Roman numerals use the following symbols:

| Symbol | Value |
| :----: | ----: |
|    I   |     1 |
|    V   |     5 |
|    X   |    10 |
|    L   |    50 |
|    C   |   100 |
|    D   |   500 |
|    M   |  1000 |

Roman numerals are constructed from the largest values to the smallest values.

There are six special **subtractive forms**:

| Value | Roman |
| :---: | :---: |
|   4   |   IV  |
|   9   |   IX  |
|   40  |   XL  |
|   90  |   XC  |
|  400  |   CD  |
|  900  |   CM  |

---

## Examples

### Example 1

**Input:**

```text
num = 3749
```

**Output:**

```text
"MMMDCCXLIX"
```

Explanation:

```text
3000 = MMM
 700 = DCC
  40 = XL
   9 = IX
```

Therefore:

```text
MMMDCCXLIX
```

---

### Example 2

**Input:**

```text
num = 58
```

**Output:**

```text
"LVIII"
```

Explanation:

```text
50 = L
 8 = VIII
```

---

### Example 3

**Input:**

```text
num = 1994
```

**Output:**

```text
"MCMXCIV"
```

Explanation:

```text
1000 = M
 900 = CM
  90 = XC
   4 = IV
```

---

## Approach

We use a **greedy approach**.

Store all Roman numeral values and their corresponding symbols in descending order:

```text
1000 → M
900  → CM
500  → D
400  → CD
100  → C
90   → XC
50   → L
40   → XL
10   → X
9    → IX
5    → V
4    → IV
1    → I
```

For each value:

1. Check whether the current number is greater than or equal to that value.
2. If it is, append the corresponding Roman symbol.
3. Subtract the value from `num`.
4. Continue until the value can no longer be used.
5. Move to the next smaller value.

---

## Example Walkthrough

Consider:

```text
num = 1994
```

Start with the largest value:

```text
1994 >= 1000
```

Append `M`:

```text
M
remaining = 994
```

Next:

```text
994 >= 900
```

Append `CM`:

```text
MCM
remaining = 94
```

Next:

```text
94 >= 90
```

Append `XC`:

```text
MCMXC
remaining = 4
```

Finally:

```text
4 >= 4
```

Append `IV`:

```text
MCMXCIV
```

Therefore:

```text
Answer = "MCMXCIV"
```

---

## Algorithm

```text
Create Roman numeral values in descending order

result = ""

For each value:
    while num >= value:
        append corresponding Roman symbol
        subtract value from num

Return result
```

---

## C++ Implementation

```cpp
class Solution {
public:
    string intToRoman(int num) {

        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string result = "";

        for (int i = 0; i < values.size(); i++) {

            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};
```

---

## Complexity

Since the input is limited to `1 <= num <= 3999`, the number of Roman numeral symbols generated is bounded.

* **Time:** `O(1)` — bounded by the fixed set of Roman numeral values
* **Space:** `O(1)` — excluding the output string

---

## Key Concept

The important technique used here is the **Greedy Algorithm**.

Always choose the **largest possible Roman numeral value** and subtract it from the number.

For example:

```text
58
↓
50 → L
8  → VIII
↓
LVIII
```

The inclusion of the subtractive values (`IV`, `IX`, `XL`, `XC`, `CD`, `CM`) ensures that the generated Roman numeral follows the required format.

---

## Tags

`#LeetCode` `#C++` `#Greedy` `#String` `#Math` `#Medium`
