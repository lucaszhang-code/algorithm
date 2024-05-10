#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str, output;
    getline(cin, str);
    stack<char> st;

    // Lambda 表达式，用于检查字符是否为数字
    auto isDigit = [](char ch) -> bool {
        return ch >= '0' && ch <= '9';
    };

    // Lambda 表达式，用于确定操作符的优先级
    auto precedence = [](char op) -> int {
        switch (op) {
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    };

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') continue;

        if (isDigit(str[i])) {
            output += str[i];
            // 检查下一个字符是否也是数字，如果不是或者是字符串的末尾，则添加空格
            if (i + 1 == str.size() || !isDigit(str[i + 1])) {
                output += " ";
            }
        }
        else if (str[i] == '(') {
            st.push(str[i]);
        }
        else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                output += " ";
                st.pop();
            }
            if (!st.empty()) st.pop(); // 弹出左括号
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(str[i])) {
                output += st.top();
                output += " ";
                st.pop();
            }
            st.push(str[i]);
        }
    }

    // 弹出所有剩余的操作符
    while (!st.empty()) {
        output += st.top();
        output += " ";
        st.pop();
    }

    cout << output << endl;
    return 0;
}
