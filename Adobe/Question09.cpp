// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int count = 0;

private:
    pair<int, int> solve(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int sum = (left.first + right.first + root->val);
        int nodes = (left.second + right.second + 1);

        if (sum / nodes == root->val)
        {
            count++;
        }

        return {sum, nodes};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        solve(root);
        return count;
    }
};
