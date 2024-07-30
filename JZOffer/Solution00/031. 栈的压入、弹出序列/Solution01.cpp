#include <stack>
#include <vector>


using namespace std;



/************************* Solution-01 ************************
 * 解题思路：
 *     使用一个栈来模拟栈的压入和弹出。需要注意的是每当完成一个压入和弹出组合后，需要判断
 * 下一个待弹出的元素和当前的栈顶元素是否相等，若相等则继续完成一次弹出操作。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int>popV) {
        if (pushV.empty() && popV.empty()) return true;
        if (pushV.empty() || popV.empty()) return false;
        
        int i = 0, j = 0;
        while (i < pushV.size()) {
            if (pushV[i] == popV[j]) {
                ++i;
                ++j;
                while (!my_st.empty() && popV[j] == my_st.top()) {
                    my_st.pop();
                    ++j;
                }
            } else {
                my_st.push(pushV[i]);
                ++i;
            }
        }

        return my_st.empty();
    }

private:
    stack<int> my_st;

};