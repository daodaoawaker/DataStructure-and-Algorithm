#include <queue>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};




/************************* Solution-01 ************************
 * 解题思路：
 *     遍历二叉树的每一个节点，判断当前节点是否是指定的两个节点的祖先，可以使用两
 * 个标志位变量is_a、is_b来记录结果。若遍历某个节点后，这两个变量均为true说明当前
 * 节点是二者的祖先，记录下该节点的值,但此节点并不一定是最近的祖先节点。接着依次往
 * 下遍历，不断地对祖先节点进行更新，直至遍历完所有节点。
*/
class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) return -1;        

        queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode* cur;
        int res;

        // 层序遍历
        while (!node_queue.empty()) {
            cur = node_queue.front();
            node_queue.pop();

            if (cur->left) node_queue.push(cur->left);
            if (cur->right) node_queue.push(cur->right);

            is_a = isAncestor(cur, p);
            is_b = isAncestor(cur, q);
            if (is_a && is_b) {
                res = cur->val;
            }

            is_a = false;
            is_b = false;
        }

        return res;
    }

    bool isAncestor(TreeNode* pNode, int tar) {
        if (!pNode) return false;
        if (pNode->val == tar) {
            return true;
        }

        return isAncestor(pNode->left, tar) || isAncestor(pNode->right, tar);
    }

private:
    bool is_a = false;
    bool is_b = false;

};