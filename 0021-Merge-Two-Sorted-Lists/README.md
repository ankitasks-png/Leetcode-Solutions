# LeetCode 21 — Merge Two Sorted Lists

## Problem

You are given the heads of two sorted linked lists, `list1` and `list2`.

Merge the two lists into one **sorted** linked list by splicing together the nodes of the original lists.

Return the head of the merged linked list.

## Examples

### Example 1

```text id="k8r2pj"
Input:
list1 = [1,2,4]
list2 = [1,3,4]

Output:
[1,1,2,3,4,4]
```

### Example 2

```text id="q6s7ny"
Input:
list1 = []
list2 = []

Output:
[]
```

### Example 3

```text id="w2m4ka"
Input:
list1 = []
list2 = [0]

Output:
[0]
```

## Approach

Since both linked lists are already sorted, we can merge them using two pointers.

A **dummy node** is used to simplify the process of building the merged list.

At every step:

1. Compare the values of the current nodes of `list1` and `list2`.
2. Attach the smaller node to the merged list.
3. Move the pointer of the list from which the node was taken.
4. Move the merged-list pointer forward.
5. When one list becomes empty, attach the remaining nodes from the other list.

The existing nodes are reused, so no new list nodes are required.

## Algorithm

1. Create a dummy node.
2. Set `current` to the dummy node.
3. While both lists are non-empty:

   * If `list1->val <= list2->val`, attach `list1`.
   * Otherwise, attach `list2`.
   * Move the selected list pointer forward.
   * Move `current` forward.
4. Attach whichever list still contains nodes.
5. Return `dummy.next`.

## C++ Implementation

```cpp id="8n4vqm"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next;
    }
};
```

## Complexity

Let:

* `n` = number of nodes in `list1`

* `m` = number of nodes in `list2`

* **Time Complexity:** `O(n + m)` — each node is visited once.

* **Space Complexity:** `O(1)` auxiliary space — existing nodes are reused.

## Key Concept

**Two Pointers + Linked List**

Because both lists are sorted, we can always choose the smaller current node and append it to the merged list.

The dummy node makes it easier to handle the head of the resulting linked list.

## Tags

`Linked List` `Two Pointers` `Merge` `Easy`
