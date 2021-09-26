/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode *> q;
        if(root==NULL){
            str = "#";
            return str;
        }
        q.push(root);
        while(!q.empty()){
            //int size = q.size();
            //while(size>0){
            auto node = q.front();
            q.pop();
            if(node){
                str += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                str += "# ";
            }

        }
        
        str.pop_back();
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#")return NULL;
        stringstream ss(data);
        string s;
        ss>>s;
        TreeNode *root = new TreeNode(stoi(s));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto Node = q.front();
            q.pop();
            ss>>s;
            if(s!="#"){
                Node->left = new TreeNode(stoi(s));
                q.push(Node->left);
            }
            ss>>s;
            if(s!="#"){
                Node->right = new TreeNode(stoi(s));
                q.push(Node->right);
            }
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));