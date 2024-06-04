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
 *     这道题跟第二题相比又增加了一定的难度(因为不要求满足条件的路径必须从根节点开始，到叶子节
 * 点结束)，因此必须从根节点开始，一个节点一个节点地进行深度优先搜索DFS。所以大致分为两层循环，
 * 一是依次从二叉树的根节点开始，确定搜索的起始节点；二是从起始节点出发，深度优先遍历所有子节点。
 * 总得来就是使用了两次深度优先搜索。
 *     只是需要注意的是，在写DFS函数时找到满足条件的路径后注意不要return返回，可能后续的节点和
 * 加起来会为0，如此以来又可能产生新的满足条件的路径。
 *     
*/
class Solution {
public:
    // 外层函数通过递归遍历地方式不断地确定搜索的起始节点
    int FindPath(TreeNode* root, int sum) {
        if (!root) return res;

        DFS(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);

        return res;
    }

    // 内层函数通过深搜的方式不断地在当前这颗子树上寻找记录满足条件的路径
    void DFS(TreeNode* pNode, int leftValue) {
        if (!pNode) return;

        int val = pNode->val;
        if (val == leftValue) {
            // ！！注意这里不要 return
            // 虽然到这里已经找到了满足条件的路径，但可能后续的节点和加起来为0，
            // 如此以来，又可能产生新的满足条件的路径，如后续是(-1,0,1)这样
            res++;
        }

        DFS(pNode->left, leftValue - val);
        DFS(pNode->right, leftValue - val);
    }

private:
    int res = 0;

};