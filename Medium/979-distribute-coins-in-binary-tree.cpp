/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }

private:
    int dfs(TreeNode* node, int& moves) {
        if (!node) return 0;
        
        int leftExcess = dfs(node->left, moves);
        int rightExcess = dfs(node->right, moves);
        
        moves += abs(leftExcess) + abs(rightExcess);
        return node->val + leftExcess + rightExcess - 1;
    }
};