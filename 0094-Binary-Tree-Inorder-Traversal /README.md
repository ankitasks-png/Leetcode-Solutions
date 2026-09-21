# LeetCode 94 — Binary Tree Inorder Traversal

## Problem

Given the `root` of a binary tree, return the **inorder traversal** of its nodes' values.

Inorder traversal visits nodes in the following order:

```text
Left → Root → Right
```

The follow-up asks for an **iterative** solution instead of using recursion.

## Examples

### Example 1

```text
Input:
root = [1,null,2,3]

Output:
[1,3,2]
```

**Explanation:**

The tree is:

```text
    1
     \
      2
     /
    3
```

Inorder traversal:

```text
3 → 2 → 1
```

Wait—the actual tree representation gives the traversal:

```text
1 → 3 → 2
```

Therefore:

```text
Output = [1,3,2]
```

### Example 2

```text
Input:
root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output:
[4,2,6,5,7,1,3,9,8]
```

### Example 3

```text
Input:
root = []

Output:
[]
```

### Example 4

```text
Input:
root = [1]

Output:
[1]
```

## Approach

Normally, inorder traversal is implemented recursively:

1. Traverse the left subtree.
2. Visit the current node.
3. Traverse the right subtree.

To make it **iterative**, we use a stack to simulate the recursive call stack.

For every node, we first keep moving to the left and push each node onto the stack.

When there is no more left child:

1. Pop the top node.
2. Add its value to the result.
3. Move to its right child.
4. Repeat the process.

The traversal is complete when both `current` is `nullptr` and the stack is empty.

## Algorithm

1. Create an empty result vector.
2. Create an empty stack of `TreeNode*`.
3. Set `current = root`.
4. While `current` is not `nullptr` or the stack is not empty:

   * Push `current` and move to its left child while possible.
   * Pop the top node from the stack.
   * Add its value to the result.
   * Move `current` to the popped node's right child.
5. Return the result.

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {

            // Go as far left as possible
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Process the current node
            current = st.top();
            st.pop();

            result.push_back(current->val);

            // Move to the right subtree
            current = current->right;
        }

        return result;
    }
};
```

## Complexity

Let `n` be the number of nodes in the binary tree.

* **Time Complexity:** `O(n)` — every node is pushed and popped from the stack once.
* **Space Complexity:** `O(n)` in the worst case due to the stack.

## Key Concept

**Iterative Tree Traversal using Stack**

The stack simulates the behavior of recursion and allows us to perform:

```text
Left → Root → Right
```

without using recursive function calls.

## Tags

`Binary Tree` `Depth-First Search` `Stack` `Tree Traversal` `Inorder Traversal` `Easy`
