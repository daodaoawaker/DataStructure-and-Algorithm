#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};




/*************************** Solution-01 ************************
 * 解题思路：
 *     根据后序遍历的特点(左子树 -> 右子树 -> 根节点)，可知序列的最后一元素为根节点，并可以根据根节点的值将
 * 给定的序列分为三段(左子树+右子树+根节点)。若先得到右子树，则当左子树序列中存在大于根节点的值时，序列不合法。
 * 然后对于每段序列代表的子树，递归地判断其左右子树的合法性，当且仅当左右子树均合法性才返回true
 */
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int L = sequence.size();
        if (sequence.empty()) return false;
        return isValid(sequence, 0, L - 1);
    }

    bool isValid(vector<int>& vec, int left, int right) {
        if (left >= right) return true; // 此时当前序列中只有一个节点 
        
        // 当前序列中的根节点
        int root = vec[right];
        // 找到左子树的右端点
        int i = right - 1;
        while (i >= left && vec[i] > root) i--;
        // 判断左子树中是否存在大于根节点的元素
        for (int j = left; j < i; j++) {
            if (vec[j] > root) return false;
        }

        return isValid(vec, left, i) && isValid(vec, i + 1, right - 1);
    }
};