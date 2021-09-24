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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)return 0;
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* node, int temp){
        temp = temp*10 + node->val;
        if(!node->left && !node->right) res+=temp;
        if(node->left)dfs(node->left, temp);
        if(node->right)dfs(node->right, temp);
    }
};

class Solution {
public:
    queue<TreeNode *>myqueue;
    queue<int>myqueue2;
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)return 0;
        myqueue.push(root);
        myqueue2.push(root->val);
        int res = 0;
        while(!myqueue.empty()){
            int size = myqueue.size();
            while(size>0){
                auto node = myqueue.front();
                myqueue.pop();
                int temp = myqueue2.front();
                myqueue2.pop();
                if(!node->left && !node->right) res+=temp;
                if(node->left){
                    myqueue.push(node->left);
                    myqueue2.push(temp*10 + node->left->val);
                }
                if(node->right){
                    myqueue.push(node->right);
                    myqueue2.push(temp*10 + node->right->val);
                }
            }
            

        }
        return res;
    }
};