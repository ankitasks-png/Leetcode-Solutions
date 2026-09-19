# LeetCode 1093 — Statistics from a Large Sample

## Problem

You are given a large sample of integers in the range `[0, 255]`.

Since the sample can be very large, it is represented using an array `count`, where:

```text
count[k] = number of times k appears in the sample
```

Calculate the following five statistics:

* **Minimum:** The smallest element in the sample.
* **Maximum:** The largest element in the sample.
* **Mean:** The average of all elements.
* **Median:** The middle element after sorting, or the average of the two middle elements when the sample size is even.
* **Mode:** The value that appears most frequently. The mode is guaranteed to be unique.

Return:

```text
[minimum, maximum, mean, median, mode]
```

as an array of floating-point numbers.

---

## Examples

### Example 1

**Input:**

```text
count = [0,1,3,4,0,0,...]
```

The represented sample is:

```text
[1,2,2,2,3,3,3,3]
```

**Output:**

```text
[1.00000, 3.00000, 2.37500, 2.50000, 3.00000]
```

**Explanation:**

* Minimum = `1`
* Maximum = `3`
* Mean = `(1 + 2 + 2 + 2 + 3 + 3 + 3 + 3) / 8 = 2.375`
* Median = `(2 + 3) / 2 = 2.5`
* Mode = `3`

---

### Example 2

**Input:**

```text
count = [0,4,3,2,2,0,0,...]
```

The represented sample is:

```text
[1,1,1,1,2,2,2,3,3,4,4]
```

**Output:**

```text
[1.00000, 4.00000, 2.18182, 2.00000, 1.00000]
```

**Explanation:**

* Minimum = `1`
* Maximum = `4`
* Mean = `24 / 11 = 2.181818...`
* Median = `2`
* Mode = `1`

---

## Approach

### Frequency Array

The important observation is that the values can only range from `0` to `255`.

Therefore, we do not need to construct the actual sample or sort it.

We can calculate all statistics directly from the frequency array.

### Minimum and Maximum

Traverse the array from left to right.

The first value with a non-zero frequency is the **minimum**.

The last value with a non-zero frequency is the **maximum**.

### Mean

Calculate:

```text
totalSum = Σ(value × frequency)
```

and:

```text
mean = totalSum / totalCount
```

Since the total frequency and sum can be very large, `long long` is used.

### Mode

Keep track of the largest frequency encountered.

The value with the highest frequency is the **mode**.

The problem guarantees that the mode is unique.

### Median

We do not need to create a sorted array.

Instead, accumulate the frequencies from `0` to `255`.

For an odd-sized sample, we need the middle position.

For an even-sized sample, we need the two middle positions and take their average.

The positions are:

```text
leftPos  = (totalCount + 1) / 2
rightPos = (totalCount + 2) / 2
```

This works for both odd and even sample sizes.

---

## Algorithm

1. Initialize variables for:

   * Minimum
   * Maximum
   * Mean
   * Median
   * Mode
2. Traverse `count` from `0` to `255`.
3. Find the first non-zero frequency as the minimum.
4. Find the last non-zero frequency as the maximum.
5. Calculate the total number of elements.
6. Calculate the total sum using:

   ```text
   value × frequency
   ```
7. Find the value with the highest frequency to determine the mode.
8. Calculate the two median positions.
9. Traverse the frequency array again while accumulating frequencies.
10. Find the values corresponding to the median positions.
11. Return:

```text
[minimum, maximum, mean, median, mode]
```

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = -1;
        double maximum = -1;
        double mean = 0;
        double median = 0;
        double mode = 0;

        long long totalCount = 0;
        long long totalSum = 0;

        int maxFrequency = 0;

        // Find minimum, maximum, mean, and mode
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                if (minimum == -1)
                    minimum = i;

                maximum = i;

                totalCount += count[i];
                totalSum += (long long)i * count[i];

                if (count[i] > maxFrequency) {
                    maxFrequency = count[i];
                    mode = i;
                }
            }
        }

        mean = (double)totalSum / totalCount;

        // Find median
        long long leftPos = (totalCount + 1) / 2;
        long long rightPos = (totalCount + 2) / 2;

        long long currentCount = 0;
        double leftValue = 0;
        double rightValue = 0;

        for (int i = 0; i < 256; i++) {
            if (count[i] == 0)
                continue;

            currentCount += count[i];

            if (currentCount >= leftPos && leftValue == 0) {
                leftValue = i;
            }

            if (currentCount >= rightPos) {
                rightValue = i;
                break;
            }
        }

        median = (leftValue + rightValue) / 2.0;

        return {minimum, maximum, mean, median, mode};
    }
};
```

---

## Complexity

The `count` array always contains exactly `256` elements.

* **Time Complexity:** `O(256)` → effectively `O(1)`
* **Space Complexity:** `O(1)`

No additional array proportional to the size of the sample is required.

---

## Key Concept

The key idea is to use the **frequency representation directly** instead of reconstructing the large sample.

Since every possible value is between `0` and `255`, we can efficiently calculate:

```text
Minimum → First non-zero frequency
Maximum → Last non-zero frequency
Mean    → Total sum / Total count
Median  → Cumulative frequency
Mode    → Highest frequency
```

Using `long long` for the total count and sum prevents integer overflow when frequencies are very large.

---

## Tags

`Array` `Counting` `Statistics` `Frequency Array` `Math`
