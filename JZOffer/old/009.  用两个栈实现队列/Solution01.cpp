#include <stack>

using namespace std;



/************************* Solution-01 ************************
 * 解题思路：
 *     本题主要是通过栈的接口实现队列的压入和弹出操作。只需要注意在队列弹出时的逻辑是
 * 先第一个栈中的元素全部搬进第二个栈中，然后再取栈顶元素进行出栈弹出操作。
*/
class Solution {
public:
    void push(int val) {
        st1.push(val);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                int top_1 = st1.top();
                st2.push(top_1);
                st1.pop();
            }
        }
        int ret = st2.top();
        st2.pop();
        return ret;
    }

private:
    stack<int> st1;
    stack<int> st2;

};