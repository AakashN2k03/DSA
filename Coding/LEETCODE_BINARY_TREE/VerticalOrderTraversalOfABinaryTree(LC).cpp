// LEETCODE: 987. Vertical Order Traversal of a Binary Tree (QUEUE, MAP, MULTISET, BFS )

// SEE CONCEPT MULTIPLE TIMES TO UNDERSTAND THIS PROBLEM

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodes; // eg {0: {0: {3}}} -> vertical line,level, node value
        queue<pair<TreeNode* ,pair<int,int>>> qu;
        qu.push({root,{0,0}}); // {root,vertical line,level}

        while(!qu.empty())
        {
            auto p = qu.front();    // can use pair<TreeNode*, pair<int, int>> p = qu.front();  (STRAIGHT FORWARD APPROACH)
            qu.pop();
            TreeNode* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;

            nodes[x][y].insert(temp->val); //map<int, map<int, multiset<int>>> nodes;

            if(temp->left)
            {
                qu.push({temp->left,{x-1,y+1}});
            }
            if(temp->right)
            {
                qu.push({temp->right,{x+1,y+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto p:nodes)
        {
            vector<int>col;

            for(auto q:p.second)
            {
                    col.insert(col.end(),q.second.begin(),q.second.end()); // insert(col.end(), ...) use to add multiple elements at the end
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};

// NOTE:
// ✅ Use map when:
// Keys must be sorted.
// Need to traverse elements in order.

// ✅ multiset<int> is necessary because:
// It allows storing duplicate node values and sort them in increasing order
