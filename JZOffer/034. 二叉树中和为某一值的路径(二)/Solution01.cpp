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
 *     这道题跟第一题的区别是必须将所有满足条件的路径都找出来，搜索过程中需要注意的地方
 * 就在于必须保持当前路径path的动态更新。
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