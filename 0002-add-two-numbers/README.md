# LeetCode 2 — Add Two Numbers

## Problem

You are given two **non-empty** linked lists representing two non-negative integers.

The digits are stored in **reverse order**, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

You may assume that the two numbers do not contain leading zeros, except for the number `0` itself.

---

## Examples

### Example 1

**Input:**

```text
l1 = [2,4,3]
l2 = [5,6,4]
```

**Output:**

```text
[7,0,8]
```

**Explanation:**

The linked lists represent:

```text
342 + 465 = 807
```

Since the digits are stored in reverse order, the result is:

```text
[7,0,8]
```

---

### Example 2

**Input:**

```text
l1 = [0]
l2 = [0]
```

**Output:**

```text
[0]
```

---

### Example 3

**Input:**

```text
l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]
```

**Output:**

```text
[8,9,9,9,0,0,0,1]
```

---

## Approach

### Linked List Traversal + Carry

Since the digits are stored in **reverse order**, we can add the numbers from left to right directly by traversing both linked lists.

For every pair of digits:

1. Add the current digit from `l1`.
2. Add the current digit from `l2`.
3. Add the carry from the previous calculation.
4. Store `sum % 10` in the result list.
5. Update the carry using `sum / 10`.

We continue until both lists are completely traversed.

If a carry remains after both lists end, we add one final node.

A **dummy node** is used to simplify construction of the result linked list.

---

## Algorithm

1. Create a dummy node and set `current` to it.
2. Initialize `carry = 0`.
3. Traverse while `l1`, `l2`, or `carry` exists.
4. Get the current values from both lists. If a list has ended, use `0`.
5. Calculate:

   ```text
   sum = val1 + val2 + carry
   ```
6. Create a new node containing:

   ```text
   sum % 10
   ```
7. Update:

   ```text
   carry = sum / 10
   ```
8. Move to the next nodes.
9. Return `dummy->next`.

---

## C++ Implementation

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;

            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }

        return dummy->next;
    }
};
```

---

## Complexity

Let `m` and `n` be the lengths of the two linked lists.

* **Time Complexity:** `O(max(m, n))`
* **Space Complexity:** `O(max(m, n))`

The space is required for the resulting linked list.

---

## Key Concept

The key idea is to use the **reverse order of the digits** to perform addition exactly like normal column-wise addition.

For example:

```text
  342
+ 465
-----
  807
```

The linked lists store:

```text
[2,4,3]
[5,6,4]
```

So we can process the digits directly from the head while maintaining a `carry`.

---

## Tags

`Linked List` `Math` `Recursion` `Carry`
