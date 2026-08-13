#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int preLen, sufLen, maxLen, len;
    char preChar, sufChar;
};

class Solution {
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.preChar = left.preChar;
        res.sufChar = right.sufChar;
        
        res.preLen = left.preLen;
        if (left.preLen == left.len && left.preChar == right.preChar) {
            res.preLen += right.preLen;
        }
        
        res.sufLen = right.sufLen;
        if (right.sufLen == right.len && right.sufChar == left.sufChar) {
            res.sufLen += left.sufLen;
        }
        
        res.maxLen = max(left.maxLen, right.maxLen);
        if (left.sufChar == right.preChar) {
            res.maxLen = max(res.maxLen, left.sufLen + right.preLen);
        }
        
        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n + 1);
        build(s, 1, 0, n - 1);
        
        vector<int> ans;
        int k = queryIndices.size();
        ans.reserve(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].maxLen);
        }
        return ans;
    }
};