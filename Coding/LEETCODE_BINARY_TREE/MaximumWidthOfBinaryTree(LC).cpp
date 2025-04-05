// LEETCODE: 662. Maximum Width of Binary Tree ( QUEUE, BFS )

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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root) return 0;
        queue<pair<TreeNode*,int>> qu;
        qu.push({root,0}); // NODE , INDEX
        while(!qu.empty())
        {  
            int size=qu.size();
            int reset_to_zero= qu.front().second ;// reset id to zero to make it starting index
            int first,last;

            for(int i=0;i<size;i++)
            {
                long long current_id= qu.front().second-reset_to_zero;
                TreeNode* node=qu.front().first;
                qu.pop();

                if(i==0) first=current_id;
                if(i==size-1) last=current_id;

                if(node->left) qu.push({node->left,2*current_id+1}); // 2*i+1
                if(node->right) qu.push({node->right,2*current_id+2});// 2*i+1
            }
            ans=max(ans,(last-first+1));
        }
    return ans;
    }
};
