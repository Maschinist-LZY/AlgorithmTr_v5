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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)return true;
        else if(p==nullptr || q==nullptr)return false;
        queue<TreeNode *> p_q, q_q;
        p_q.push(p);
        q_q.push(q);
        while(!p_q.empty() && !q_q.empty()){
            auto node1 = p_q.front();
            p_q.pop();
            auto node2 = q_q.front();
            q_q.pop();
            if(node1->val!=node2->val)return false;
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            if(left1==nullptr ^ left2==nullptr)return false;
            if(right1==nullptr ^ right2==nullptr)return false;
            if(left1!=nullptr)p_q.push(left1);
            if(right1!=nullptr)p_q.push(right1);
            if(left2!=nullptr)q_q.push(left2);
            if(right2!=nullptr)q_q.push(right2);
        }
        return true;
    }
};