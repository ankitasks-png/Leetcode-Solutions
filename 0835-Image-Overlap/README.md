# LeetCode 835 — Image Overlap

## Problem

You are given two binary square matrices `img1` and `img2` of size `n × n`.

You can **translate** one image by sliding all its `1` bits left, right, up, or down any number of units. Rotation is not allowed.

After translating the image, place it over the other image and calculate the **overlap** by counting the positions where both images contain a `1`.

Return the **largest possible overlap**.

---

## Examples

### Example 1

**Input:**

```text
img1 = [[1,1,0],
        [0,1,0],
        [0,1,0]]

img2 = [[0,0,0],
        [0,1,1],
        [0,0,1]]
```

**Output:**

```text
3
```

**Explanation:**

Translate `img1` **right by 1 unit** and **down by 1 unit**.

This produces an overlap of `3`.

---

### Example 2

**Input:**

```text
img1 = [[1]]
img2 = [[1]]
```

**Output:**

```text
1
```

---

### Example 3

**Input:**

```text
img1 = [[0]]
img2 = [[0]]
```

**Output:**

```text
0
```

---

## Approach

### Coordinate Translation

Instead of actually translating the entire matrices, we can work only with the positions of the `1`s.

Suppose a `1` in `img1` is located at:

```text
(i, j)
```

and a `1` in `img2` is located at:

```text
(x, y)
```

For these two positions to overlap, `img1` needs to be translated by:

```text
dx = x - i
dy = y - j
```

If the **same translation** occurs for multiple pairs of `1`s, all those pairs will overlap at the same time.

Therefore, we count how frequently each translation `(dx, dy)` occurs.

The maximum frequency is the largest possible overlap.

---

## Algorithm

1. Store the coordinates of all `1`s in `img1`.
2. Store the coordinates of all `1`s in `img2`.
3. For every pair of `1`s:

   * Take one position from `img1`.
   * Take one position from `img2`.
   * Calculate the required translation:

     ```text
     dx = x2 - x1
     dy = y2 - y1
     ```
4. Store the frequency of each translation using a map.
5. Keep track of the maximum frequency.
6. Return the maximum frequency as the largest possible overlap.

---

## C++ Implementation

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Store positions of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> shifts;
        int answer = 0;

        // Count how many pairs have the same translation
        for (auto a : ones1) {
            for (auto b : ones2) {
                int dx = b.first - a.first;
                int dy = b.second - a.second;

                shifts[{dx, dy}]++;
                answer = max(answer, shifts[{dx, dy}]);
            }
        }

        return answer;
    }
};
```

---

## Complexity

Let `k` be the number of `1`s in each image.

* **Time Complexity:** `O(k² log k)`
* **Space Complexity:** `O(k²)`

The `log k²` factor comes from using `map` to store the translation frequencies.

Since `n ≤ 30`, there can be at most `900` ones in an image, so this approach is efficient enough.

---

## Key Concept

The key idea is to **avoid physically translating the images**.

Instead, calculate the relative displacement between every pair of `1`s.

If several pairs require the same displacement, those `1`s overlap after applying that translation.

> **Maximum frequency of a translation = Maximum image overlap**

---

## Tags

`Array` `Hash Table` `Matrix` `Counting` `Coordinate Geometry` `Translation`
