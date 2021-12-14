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
 *     序列化是将二叉树按照先序遍历的顺序依次保存下来(保存为一个字符串形式)，反序列化就是
 * 根据这个字符串依次取出首元素，再按照先序遍历的顺序重新递归地构建出二叉树。
 *     思路上感觉不难，但很多细节需要注意，比如到达叶子结点的空指针域，也就是递归的出口时也
 * 要对相应的变量进行更新操作。
 * 
*/
class Solution {
public:
    string Serialize(TreeNode* root) {
        // 递归出口，注意此处也要对res进行更新
        if (!root) {
            res += "#";
            string empty;
            return empty;
        }
        string elem = to_string(root->val);
        res += elem;

        Serialize(root->left);
        Serialize(root->right);
        return res;
    }

    TreeNode* Deserialize(string& str) {
        // 递归出口，注意此处也要对str进行更新
        if (str.at(0) == '#') {
            str = str.substr(1);
            return nullptr;
        }

        char s = str[0];
        string first(1, s);
        int val = stoi(first);
        TreeNode* root = new TreeNode(val);

        str = str.substr(1);
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }

private:
    string res;

};