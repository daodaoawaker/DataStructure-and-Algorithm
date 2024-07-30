#include <vector>
#include <string>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



/************************* Solution-02 ************************
 * 解题思路：
 *     二叉搜索树的特点是对于任意节点，其左子树上所有节点的值都小于其根节点的值，
 * 其右子树上所有节点的值都大于其根节点的值。根据这个特点，我们无需遍历此二叉搜索
 * 树上的每一个节点。
 *     从树的根节点开始，若当前根节点的值大于指定的两个节点的值，则将根节点
 * 置为其左孩子节点，若当前根节点小于指定的两个节点的值，则将根节点置为其右孩子
 * 节点。若当前根节点的值恰好位于两者之间，或者等于其中的某一节点的值，则认为该
 * 根节点即为最近的公共祖先节点。
*/
class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) return -1;

        TreeNode* ancestor = findHelper(root, p, q);
        if (!ancestor) {
            return -1;
        } else {
            return ancestor->val;
        }
    }

    TreeNode* findHelper(TreeNode* root, int p, int q) {
        // 到达叶子也未能找到满足条件的公共节点，说明这两个节点超出了此二叉搜索树的范围
        if (!root) return nullptr;

        int root_value = root->val;
        if (p == root_value || q == root_value) return root;

        if (root_value > p && root_value > q) {
            // 说明此时指定的两个节点都在当前根节点的左子树上
            return findHelper(root->left, p, q);
        } else if (root_value < p && root_value < q) {
            // 说明此时指定的两个节点都在当前根节点的右子树上
            return findHelper(root->right, p, q);
        } else {
            // 当前根节点的值在两个指定节点之间，即为目标节点
            return root;
        }
    }

};