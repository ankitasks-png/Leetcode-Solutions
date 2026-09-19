# LeetCode 1401 — Circle and Rectangle Overlapping

## Problem

You are given a circle represented by:

```text
(radius, xCenter, yCenter)
```

and an **axis-aligned rectangle** represented by:

```text
(x1, y1, x2, y2)
```

where:

* `(x1, y1)` is the **bottom-left** corner of the rectangle.
* `(x2, y2)` is the **top-right** corner of the rectangle.

Return `true` if the circle and rectangle overlap.

In other words, there must be at least one point that belongs to both the circle and the rectangle.

---

## Examples

### Example 1

**Input:**

```text
radius = 1
xCenter = 0
yCenter = 0
x1 = 1
y1 = -1
x2 = 3
y2 = 1
```

**Output:**

```text
true
```

**Explanation:**

The circle and rectangle share the point:

```text
(1, 0)
```

---

### Example 2

**Input:**

```text
radius = 1
xCenter = 1
yCenter = 1
x1 = 1
y1 = -3
x2 = 2
y2 = -1
```

**Output:**

```text
false
```

**Explanation:**

The closest point of the rectangle to the circle's center is outside the circle.

---

## Approach

### Closest Point on Rectangle

The key idea is to find the point inside the rectangle that is **closest to the center of the circle**.

For the x-coordinate, clamp `xCenter` between `x1` and `x2`:

```text
closestX = max(x1, min(xCenter, x2))
```

Similarly, for the y-coordinate:

```text
closestY = max(y1, min(yCenter, y2))
```

The point `(closestX, closestY)` is the closest point on the rectangle to the circle's center.

We then calculate the squared distance between the circle's center and this point:

```text
distance² = (xCenter - closestX)² + (yCenter - closestY)²
```

If:

```text
distance² <= radius²
```

the circle and rectangle overlap.

---

## Algorithm

1. Find the closest x-coordinate on the rectangle to `xCenter`.
2. Find the closest y-coordinate on the rectangle to `yCenter`.
3. Calculate the squared distance between the circle's center and the closest point.
4. Compare the squared distance with `radius²`.
5. Return `true` if the distance is less than or equal to the radius; otherwise return `false`.

---

## C++ Implementation

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};
```

---

## Complexity

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

Only a constant number of calculations are performed.

---

## Key Concept

The key concept is **clamping coordinates to find the closest point**.

If the circle's center lies inside the rectangle, the closest point is the center itself.

Otherwise, the closest point lies on one of the rectangle's edges or corners.

We can then use the distance formula to determine whether that point lies inside the circle.

---

## Tags

`Geometry` `Math` `Rectangle` `Circle` `Distance`
