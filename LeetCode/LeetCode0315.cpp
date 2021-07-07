// LeetCode0315_CountOfSmallerNumbersAfterSelf.cpp
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
struct Range {
    int start, end;

    Range(int s, int e): start(s), end(e) { }

    int getMid() {
        return (start + end) / 2;
    }
};

class SegmentTree {
private:
    int* tree;
    int minIdx, maxIdx;

public:
    SegmentTree(int size) {
        minIdx = 0, maxIdx = size - 1;
        tree = new int[maxIdx * 4];
        fill(tree, tree + maxIdx * 4, 0);
    }

    ~SegmentTree() {
        delete[] tree;
    }

    int get(int start, int end) {
        return get(1, Range(start, end), Range(minIdx, maxIdx));
    }

    int get(int treeIdx, Range target, Range curr) {
        if (target.start <= curr.start && curr.end <= target.end)
            return tree[treeIdx];
        else if (curr.end < target.start || target.end < curr.start) {
            return 0;
        } else {
            int mid = curr.getMid();
            return get(treeIdx * 2, target, Range(curr.start, mid)) + get(treeIdx * 2 + 1, target, Range(mid + 1, curr.end));
        }
    }

    void add(int target, int value) {
        add(1, target, Range(minIdx, maxIdx), value);
    }

    void add(int treeIdx, int target, Range curr, int value) {
        if (curr.start == curr.end && curr.start == target)
            tree[treeIdx] += value;
        else if (curr.start <= target && target <= curr.end) {
            int mid = curr.getMid();
            add(treeIdx * 2, target, Range(curr.start, mid), value);
            add(treeIdx * 2 + 1, target, Range(mid + 1, curr.end), value);

            tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size());

        SegmentTree st(20'001);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int mapIdx = nums[i] + 10'000;
            counts[i] = st.get(0, mapIdx - 1);
            st.add(mapIdx, 1);
        }

        return counts;
    }
};