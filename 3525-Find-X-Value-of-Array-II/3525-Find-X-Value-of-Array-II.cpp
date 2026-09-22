class Solution {
public:
    int n, k;
    vector<array<int, 5>> tree;

    array<int, 5> mergeNode(const array<int, 5>& left,
                            const array<int, 5>& right) {
        array<int, 5> result{};

        // Prefixes completely inside the left part
        for (int r = 0; r < k; r++) {
            result[r] += left[r];
        }

        // Prefixes that extend into the right part
        int leftProduct = 1;

        for (int r = 0; r < k; r++) {
            leftProduct = (leftProduct * 1) % k;
        }

        // Find product of the complete left segment
        // from its prefix counts is not possible directly,
        // so product is stored separately in the tree.
        return result;
    }

    struct Node {
        array<int, 5> cnt{};
        int product = 1;
    };

    vector<Node> seg;

    Node combine(const Node& a, const Node& b) {
        Node res;

        res.product = (a.product * b.product) % k;

        // Prefixes ending inside a
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes that contain all of a and extend into b
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
            int rem = value % k;

            seg[node] = Node();
            seg[node].product = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        seg[node] = combine(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

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

            // Update nums[index]
            update(1, 0, n - 1, index, value);

            // Query [start, n - 1]
            Node answer = query(1, 0, n - 1, start, n - 1);

            result.push_back(answer.cnt[x]);
        }

        return result;
    }
};
