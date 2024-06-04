#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



/****************************** Solution-01 ******************************
 * 解题思路：
 *     该题比较简单，通过后序递归遍历二叉树的各个节点即可
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;

        int L = TreeDepth(pRoot->left);
        int R = TreeDepth(pRoot->right);
        // 算上当前结点个数， +1
        int MAX = max(L, R) + 1;

        return  MAX;
    }

}