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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode *> myqueue;
        myqueue.push(root);
        int depth = 0;
        while(!myqueue.empty()){
            TreeNode *node = myqueue.front();
            myqueue.pop();
            int sz = myqueue.size();
            while(sz>0){
                if(node->left){
                    myqueue.push(node->left);
                }
                if(node->right){
                    myqueue.push(node->right);
                }
            }
            
            depth++;
        }
        return depth;
    }
};