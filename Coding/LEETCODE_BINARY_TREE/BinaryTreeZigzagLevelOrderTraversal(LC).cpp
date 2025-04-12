LEETCODE: 103. Binary Tree Zigzag Level Order Traversal (QUEUE + BFS)

// USE LEVEL ORDER TRAVERSAL TO SOLVE THIS PROBLEM

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;

        queue<TreeNode*> qu;
        qu.push(root);
        bool zigzag=true;
        while(!qu.empty())
        {  
            int size= qu.size();
            vector<int>level(size);

            for(int i=0;i<size;i++)
            {
                TreeNode* node=qu.front();
                qu.pop();
                if(node->left!=NULL)
                {
                    qu.push(node->left);
                }
                if(node->right!=NULL)
                {
                    qu.push(node->right);
                }

                int index=zigzag ? i : (size-1-i);
                level[index]=(node->val);
            }
            zigzag=!zigzag;
            ans.push_back(level);

        }
        return ans;
    }
};

// ✅ Time Complexity: O(n)
// ✅ Space Complexity: O(n)
