#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



/************************ Solution-01 ***********************
 * 解题思路：
 *     递归的思路，借助一个辅助函数求出每颗子树的高度
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;

        int depth_l = DFS(pRoot->left);
        int depth_r = DFS(pRoot->right);
        if (abs(depth_l - depth_r) > 1) return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    int DFS(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = DFS(root->left);
        int r = DFS(root->right);
        int depth = max(l, r) + 1;

        return depth;
    }
};