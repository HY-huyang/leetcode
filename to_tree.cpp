#include<iostream>
#include<vector>
#include<optional>
#include<deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
template <typename Tp>
class MemoManager {
    /// RAII. ±ÜÃâÄÚ´æÐ¹Â¶
public:
    vector<Tp> buf;
    Tp create(Tp ptr) {
        buf.push_back(ptr);
        return ptr;
    }
    void clear() {
        for (int i = 0; i < buf.size(); ++i) {
            delete buf[i];
        }
    }
    ~MemoManager() { clear(); }
};
MemoManager<TreeNode*> __tn_mm;

TreeNode* to_tree(const vector<optional<int>>& v) {
    int n = v.size();
    if (n == 0) {
        return nullptr;
    }
    TreeNode* root = __tn_mm.create(new TreeNode(v[0].value()));
    deque<TreeNode*> dq = { root };
    int i = 1;
    while (!dq.empty()) {
        TreeNode* parent = dq.front();
        dq.pop_front();
        //
        if (i >= n) {
            break;
        }
        const optional<int>& lc_x = v[i];
        ++i;
        if (lc_x.has_value()) {
            TreeNode* lc = __tn_mm.create(new TreeNode(lc_x.value()));
            dq.push_back(lc);
            parent->left = lc;
        }
        //
        if (i >= n) {
            break;
        }
        const optional<int>& rc_x = v[i];
        ++i;
        if (rc_x.has_value()) {
            TreeNode* rc = __tn_mm.create(new TreeNode(rc_x.value()));
            dq.push_back(rc);
            parent->right = rc;
        }
    }
    return root;
}

int main() {
    TreeNode* T = to_tree({ 1,2,3 });
}
