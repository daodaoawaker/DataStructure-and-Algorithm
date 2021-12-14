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
 *     对二叉搜索树进行中序遍历就能得到一个按照元素值升序排序的数组，因此可以先对二叉树作一个中序遍历
 * 将结果保存下来。然后对这个保存下来的序列进行for循环查找即可。
*/
class Solution {
public:
    TreeNode* kthNode(TreeNode* pRoot, int k) {
        if (!pRoot) return nullptr;

        InOrderTraverse(pRoot);
        if (k > array.size()) return nullptr;
        
        return array[k - 1];
    }

    void InOrderTraverse(TreeNode* root) {
        if (!root) return nullptr;

        InOrderTraverse(root->left);
        array.push_back(root);
        InOrderTraverse(root->right);
    }

private:
    vector<TreeNode*> array;

};