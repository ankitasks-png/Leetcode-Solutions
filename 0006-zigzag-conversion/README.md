# LeetCode 6 — Zigzag Conversion

## Problem

The string `"PAYPALISHIRING"` is written in a zigzag pattern across a given number of rows.

For example, with `numRows = 3`:

```text
P   A   H   N
A P L S I I G
Y   I   R
```

Reading the rows from top to bottom gives:

```text
PAHNAPLSIIGYIR
```

Given a string `s` and an integer `numRows`, return the converted string.

---

## Examples

### Example 1

**Input:**

```text
s = "PAYPALISHIRING"
numRows = 3
```

**Output:**

```text
"PAHNAPLSIIGYIR"
```

### Example 2

**Input:**

```text
s = "PAYPALISHIRING"
numRows = 4
```

**Output:**

```text
"PINALSIGYAHRPI"
```

The pattern is:

```text
P     I    N
A   L S  I G
Y A   H R
P     I
```

### Example 3

**Input:**

```text
s = "A"
numRows = 1
```

**Output:**

```text
"A"
```

---

## Approach

We simulate the zigzag movement through the rows.

The characters move:

↓
↓
↓
↗
↗
↗
↓
↓
↓
```

We maintain:

* `currentRow` — the row where the current character is placed.
* `goingDown` — the current direction of movement.
* `rows` — a vector of strings storing characters belonging to each row.

Whenever we reach:

* the **top row (`0`)**, or
* the **bottom row (`numRows - 1`)**

we reverse the direction.

Finally, we concatenate all rows to obtain the answer.

---

## Algorithm

1. If `numRows == 1` or `numRows >= s.length()`, return `s`.
2. Create `numRows` empty strings.
3. Start at row `0`.
4. For every character:

   * Add it to the current row.
   * If we reach the top or bottom, reverse direction.
   * Move one
