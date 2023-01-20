// https://leetcode.com/problems/house-robber-iii/description/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
    int solve(TreeNode* root, map<TreeNode*, int> &m){
        if(!root){
            return 0;
        }

        int ans = root->val;

        if(m.find(root)!=m.end()){
            return m[root];
        }

        if(root->left){
            ans+=solve(root->left->left, m) + solve(root->left->right, m);
        }
        if(root->right){
            ans+=solve(root->right->left, m) + solve(root->right->right, m);
        }

        return m[root]=max(ans, (solve(root->left, m)+solve(root->right, m)));
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode*, int> m;
        return solve(root, m);
    }
};