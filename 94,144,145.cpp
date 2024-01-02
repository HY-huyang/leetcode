#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {                        //中序遍历（递归）
public:
    void traversval(TreeNode* root, vector<int>&rec) {
        if (root == nullptr) {
            return;
        }
        traversval(root->left,rec);
        rec.push_back(root->val);
        traversval(root->right, rec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>val;
        traversval(root, val);
        return val;
    }
};

class Solution {                              //中序遍历（迭代）
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        TreeNode* cur = root;
        while (cur != nullptr||!st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

class Solution {                           //  前序遍历（递归）                      
public:
    void traversal(TreeNode* root, vector<int>& rec) {
        if (root == nullptr) {
            return;
        }
        rec.push_back(root->val);
        traversal(root->left, rec);
        traversal(root->right, rec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>rec;
        traversal(root, rec);
        return rec;
    }
};

class Solution {                      //前序遍历（迭代）
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        if (root == nullptr) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        return result;
    }
};

class Solution {                   //后序遍历（递归）
public:
    void traversal(TreeNode* root, vector<int>& rec) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left, rec);
        traversal(root->right, rec); 
        rec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>rec;
        traversal(root, rec);
        return rec;
    }
};

class Solution {                   //后序遍历(迭代）
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        if (root == nullptr) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {

}