# LeetCode 3525 — Find X Value of Array II

## Problem

You are given an array of positive integers `nums`, a positive integer `k`, and a list of queries.

Each query has the form:

```text
[index, value, start, x]
```

For every query:

1. Update `nums[index]` to `value`.
2. Remove the prefix `nums[0..start-1]`.
3. From the remaining array `nums[start..n-1]`, remove any suffix while keeping the array non-empty.
4. Count the number of possible remaining arrays whose product has remainder `x` modulo `k`.

Return the answer for every query.

The important observation is that after fixing `start`, every possible remaining array is a **non-empty prefix of `nums[start..n-1]`**.

Because the array is modified by point updates and each query asks about a range, a **Segment Tree** is suitable.

## Examples

### Example 1

```text
Input:
nums = [1,2,3,4,5]
k = 3
queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]

Output:
[2,2,2]
```

### Example 2

```text
Input:
nums = [1,2,4,8,16,32]
k = 4
queries = [[0,2,0,2],[0,2,0,1]]

Output:
[1,0]
```

### Example 3

```text
Input:
nums = [1,1,2,1,1]
k = 2
queries = [[2,1,0,1]]

Output:
[5]
```

## Approach

A query starting at `start` considers all non-empty prefixes of:

```text
nums[start...n-1]
```

For every segment in the Segment Tree, store:

* `product`: product of all elements in the segment modulo `k`.
* `cnt[r]`: number of non-empty prefixes whose product has remainder `r`.

Since `k <= 5`, each node only needs at most five remainder counts.

### Combining Two Segments

Suppose a node consists of:

```text
A + B
```

There are two types of prefixes:

1. Prefixes completely inside `A`.
2. Prefixes containing all of `A` and extending into `B`.

For a prefix of `B` whose product has remainder `r`, its product after adding all of `A` becomes:

```text
(product(A) * r) % k
```

Therefore, we can combine the information from the two children in `O(k)` time.

## Algorithm

### Build

1. Build a Segment Tree over `nums`.
2. For each leaf:

   * Store `nums[i] % k` as its product.
   * Set the count of that remainder to `1`.

### Update

For every query:

1. Update the value at `index`.
2. Recalculate the affected Segment Tree nodes.

### Query

1. Query the range:

```text
[start, n - 1]
```

2. The resulting node contains the number of prefixes for every possible remainder.
3. Return `cnt[x]`.

## C++ Implementation

```cpp
class Solution {
public:
    struct Node {
        array<int, 5> cnt{};
        int product = 1;
    };

    int n, k;
    vector<Node> seg;

    Node combine(const Node& a, const Node& b) {
        Node res;

        res.product = (a.product * b.product) % k;

        // Prefixes completely inside the left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes that extend into the right segment
        for (int r = 0; r < k; r++) {
            int newRemainder = (a.product * r) % k;
            res.cnt[newRemainder] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            seg[node].product = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = combine(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, int value) {
        if (l == r) {
            seg[node] = Node();

            int rem = value % k;
            seg[node].product = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            update(node * 2, l, mid, index, value);
        else
            update(node * 2 + 1, mid + 1, r, index, value);

        seg[node] = combine(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return combine(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Apply the persistent update
            update(1, 0, n - 1, index, value);

            // Count valid prefixes starting from 'start'
            Node ans = query(1, 0, n - 1, start, n - 1);

            result.push_back(ans.cnt[x]);
        }

        return result;
    }
};
```

## Complexity

Let `n` be the size of `nums` and `q` the number of queries.

Since `k <= 5`:

* **Build:** `O(nk)`
* **Each update:** `O(k log n)`
* **Each query:** `O(k log n)`
* **Total:** `O(nk + qk log n)`
* **Space:** `O(nk)`

Because `k` is at most `5`, this is effectively:

```text
O(n + q log n)
```

## Key Concept

**Segment Tree + Product Remainder DP**

Each Segment Tree node stores the distribution of product remainders for all non-empty prefixes of that segment.

The small constraint:

```text
k <= 5
```

makes it possible to store only `k` remainder states per node.

## Tags

`Segment Tree` `Range Query` `Point Update` `Dynamic Programming` `Modular Arithmetic` `Array` `Hard`
