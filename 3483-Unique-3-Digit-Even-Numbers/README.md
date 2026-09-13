# LeetCode 3483 — Unique 3-Digit Even Numbers

## Problem

You are given an array of digits called `digits`.

Your task is to determine the number of **distinct three-digit even numbers** that can be formed using these digits.

### Rules

* Each copy of a digit can be used **only once per number**.
* The number cannot have a **leading zero**.
* The last digit must be **even** (`0, 2, 4, 6, 8`).
* Each distinct three-digit number is counted only once.

---

## Examples

### Example 1

**Input:**

```text
digits = [1,2,3,4]
```

**Output:**

```text
12
```

**Explanation:**

The 12 distinct numbers are:

```text
124, 132, 134, 142,
214, 234,
312, 314, 324, 342,
412, 432
```

---

### Example 2

**Input:**

```text
digits = [0,2,2]
```

**Output:**

```text
2
```

**Explanation:**

The only valid numbers are:

```text
202, 220
```

The digit `2` can be used twice because it appears twice in the input.

---

### Example 3

**Input:**

```text
digits = [6,6,6]
```

**Output:**

```text
1
```

**Explanation:**

Only:

```text
666
```

can be formed.

---

### Example 4

**Input:**

```text
digits = [1,3,5]
```

**Output:**

```text
0
```

**Explanation:**

There are no even digits, so no three-digit even number can be formed.

---

## Approach

### Frequency Counting + Brute Force

Since there are only **10 possible digits (`0–9`)**, we can store the frequency of every digit.

Then we try every possible combination of:

1. **Hundreds digit** — must be `1–9`
2. **Tens digit** — can be `0–9`
3. **Ones digit** — must be even: `0, 2, 4, 6, 8`

Before selecting a digit, we check whether it is available in the input.

After temporarily using a digit, we decrease its frequency. Once that position has been processed, we restore the frequency so it can be used in other combinations.

This automatically handles repeated digits correctly.

---

## Algorithm

1. Create a frequency array `count[10]`.
2. Count how many times each digit appears in `digits`.
3. Try every possible hundreds digit from `1` to `9`.
4. Temporarily use that digit.
5. Try every possible tens digit from `0` to `9`.
6. Temporarily use that digit.
7. Try every even ones digit: `0, 2, 4, 6, 8`.
8. If the ones digit is available, increment the answer.
9. Restore the frequencies after each selection.
10. Return the total count.

---

## C++ Implementation

```cpp
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {};

        for (int digit : digits) {
            count[digit]++;
        }

        int answer = 0;

        for (int hundreds = 1; hundreds <= 9; hundreds++) {
            if (count[hundreds] == 0) continue;

            count[hundreds]--;

            for (int tens = 0; tens <= 9; tens++) {
                if (count[tens] == 0) continue;

                count[tens]--;

                for (int ones = 0; ones <= 8; ones += 2) {
                    if (count[ones] > 0) {
                        answer++;
                    }
                }

                count[tens]++;
            }

            count[hundreds]++;
        }

        return answer;
    }
};
```

---

## Complexity

There are only:

```text
9 × 10 × 5 = 450
```

possible combinations to check.

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

The frequency array always contains only 10 elements.

---

## Key Concept

The key idea is **frequency counting**.

Instead of generating every permutation and then removing duplicates, we directly check whether each digit is available.

This ensures:

* No leading zero
* Correct handling of duplicate digits
* Only even numbers are counted
* Each distinct number is counted exactly once

---

## Tags

`Array` `Hash Table` `Counting` `Enumeration` `Brute Force`
