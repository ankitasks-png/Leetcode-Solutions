# LeetCode 100 — Same Tree

## Problem

Given the roots of two binary trees `p` and `q`, determine whether the two trees are **the same**.

Two binary trees are considered the same if they have the same structure and all corresponding nodes have the same values.

## Examples

### Example 1

**Input:**

```text
p = [1,2,3]
q = [1,2,3]
```

**Output:**

```text
true
```

**Explanation:**

Both trees have the same structure and the same node values.

### Example 2

**Input:**

```text
p = [1,2]
q = [1,null,2]
```

**Output:**

```text
false
```

**Explanation:**

The two trees have different structures.

### Example 3

**Input:**

```text
p = [1,2,1]
q = [1,1,2]
```

**Output:**

```text
false
```

**Explanation:**

The structures may be similar, but corresponding node values are different.

## Approach

Use **recursion** to compare the two trees node by node.

For every pair of corresponding nodes:

* If both nodes are `nullptr`, they are equal.
* If only one node is `nullptr`, the trees are different.
* If their values are different, the trees are different.
* Recursively compare their left subtrees.
* Recursively compare their right subtrees.

The trees are the same only if all these checks succeed.

## Algorithm

1. If both nodes are `nullptr`, return `true`.
2. If only one node is `nullptr`, return `false`.
3. If their values are different, return `false`.
4. Compare the left subtrees recursively.
5. Compare the right subtrees recursively.
6. Return `true` only if both subtree comparisons are `true`.

## C++ Implementation

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
```

## Complexity

* **Time Complexity:** `O(n)`, where `n` is the number of nodes compared.
* **Space Complexity:** `O(h)`, where `h` is the height of the tree due to recursion.

## Key Concept

**Recursion + Binary Tree Traversal**

Compare corresponding nodes while recursively checking their left and right subtrees.

## Tags

`Binary Tree` `Recursion` `DFS` `Tree` `Easy`
