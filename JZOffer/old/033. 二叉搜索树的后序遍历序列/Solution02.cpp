#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



/******************************** Solution-02 *******************************
 * 解题思路：
 *     很巧妙的思路：二叉搜索树的中序遍历序列和后序遍历序列分别对应着栈的压入和弹出序列。
 *因此基于上面的这个结论，可以将该题转化为判断栈的压入、弹出合法性的问题。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        
        // 某个序列的升序排序便是二叉搜索树对应的中序遍历序列
        vector<int> inorder(sequence);
        sort(inorder.begin(), inorder.end());

        // 于是，对于得到的中序遍历序列，判断给定的原序列是否是合法的弹出序列。若是则说明它是对应的后序遍历序列
        return isPopOrder(inorder, sequence);
    }

    bool isPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() || popV.empty()) return false;

        int L = pushV.size();
        int i = 0, j = 0;
        stack<int> St;
        while (i < L) {
            St.push(pushV[i]);
            while (!St.empty() && popV[j] == St.top()) {
                St.pop();
                j++;
            }
            i++;
        }
        
        return j == L;
    }

};



/********************************** 关联题目 **********************************
 * 题意：
 *     给定一个入栈序列，判断第二个序列是不是对应的出栈序列
 * 
 * 思路：
 *     栈的弹出序列是指在压入元素的途中可以随时弹出若干元素，直到栈空为止，因此一个入栈序列可以
 * 对应多个出栈序列。
*/ 
class Solution {
public:
    bool isPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() || popV.empty()) return false;

        stack<int> St;
        int L = pushV.size();
        int i = 0, j = 0;
        // 不论出栈与否，入栈序列中的元素是都要被压入的。因为每当栈顶元素和出栈序列中的当前元素相等时，
        // 出栈操作后，出栈序列索引j都会自增1。所以最后若j不等于序列的长度，说明还有剩余元素没有出栈，
        // 返回fasle
        while (i < L) {
            St.push(pushV[i]);
            while (!St.empty() && popV[j] == St.top()) {
                St.pop();
                j++;
            }
            i++;
        }
        
        return j == L;
    }

};
