#include <vector>
#include <string>

using namespace std;


// 定义二叉树的结点结构
typedef int elemType;
struct TreeNode {
    elemType val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(elemType x) : val(x), left(nullptr), right(nullptr) {}
}



/************************** Solution-01 **************************
 * 解题思路：
 *    递归的思想————输入是二叉树的前序遍历序列和中序遍历序列，则先根据前序遍历序列找到根节点，再结合
 * 中序遍历序列分别找出左、右子树的前序遍历序列和中序遍历序列，由此递归下去构建出整个二叉树。
 */

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len_pre = (int)pre.size();
        int len_vin = (int)vin.size();
        if (len_pre == 0 || len_vin == 0) return nullptr;

        // 注意这里要添加当遍历序列中只有一个元素的情况，否则后续vec的切片操作会出现越界
        if (len_pre == 1) {
            return new TreeNode(pre[0]);
        }

        int root = pre[0];   // 整棵树的根节点
        TreeNode* node = new TreeNode(root);
        vector<int> left_pre;
        vector<int> left_vin;
        vector<int> right_pre;
        vector<int> right_vin;

        for (int i = 0; i < len_vin; ++i) {
            if (root == vin[i]) {
                left_pre = vector<int>(pre.begin() + 1, pre.begin() + i + 1);
                right_pre = vector<int>(pre.begin() + i + 1, pre.end());
                left_vin = vector<int>(vin.begin(), vin.begin() + i);
                right_vin = vector<int>(vin.begin() + i + 1, vin.end());
                break;
            }
        }
        
        node->left = reConstructBinaryTree(left_pre, left_vin);
        node->right = reConstructBinaryTree(right_pre, right_vin);
        return node;
    }
};




/************************** Solution-02 *************************
 * 解题思路：
 *     总体的思路一样的，还是先找到根节点在中序遍历序列中的位置，然后不断地找出左、右子树各自在
 * 前序和中序序列中的范围。只是换了递归函数的写法，使用左右子树的范围索引作为参数
*/

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        // pre和vin的长度是相等的
        PreSequence = pre;
        InSequence = vin;
        int size = (int)pre.size();
        if (size == 0) return nullptr;

        TreeNode* root = buildBiTree(0, size - 1, 0, size - 1); 
        return root;       
    }

    TreeNode* buildBiTree(int pre_l, int pre_r, int in_l, int in_r) {
        // 递归出口
        if (pre_l > pre_r) return nullptr;
        
        int root = PreSequence[pre_l];
        TreeNode* node = new TreeNode(root);
        int id = 0;
        // 遍历中序序列找到根节点的索引位置
        while (id <= in_r) {
            if (root == InSequence[id]) { break; }
            id++;
        }
        // 新的序列长度
        int len = id - in_l; 

        // 分别递归查找左右子节点
        node->left = buildBiTree(pre_l + 1, pre_l + len, in_l, in_l + len - 1);
        node->right = buildBiTree(pre_l + len + 1, pre_r, in_l + len + 1, in_r);
        return node;
    }

public:
    vector<int> PreSequence;
    vector<int> InSequence;

};
