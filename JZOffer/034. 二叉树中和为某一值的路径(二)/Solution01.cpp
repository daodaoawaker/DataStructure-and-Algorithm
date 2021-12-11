#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



/**************************** Solution-01 ***************************
 * 解题思路：
 *     思路肯定是首先考虑使用递归，递归的出口条件就是必须到达叶子节点，并且
 * 当前叶子节点的值和剩余target的值相等。然后就是递归遍历每个子节点，需要注
 * 意的就是一些实现细节。
*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (!root) return result;
        // 将当前根节点的值添加进path中
        int val = root->val;
        path.push_back(val);  
        
        if (!root->left && !root->right && val == expectNumber) {
            // 到达叶子节点
            result.push_back(path);
        }
        FindPath(root->left, expectNumber - val);
        FindPath(root->right, expectNumber - val);

        // !!!千万别忘了将当前根节点的值从path中剔除，以保证当前路径的实时更新
        path.pop_back();
        
        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> path;

};