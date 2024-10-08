#include <iostream>
#include <stack>
#include <string>
#include <cmath> // Include the cmath header

using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> stack;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();

            switch (c) {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    stack.push(op1 / op2);
                    break;
                case '^':
                    stack.push(pow(op1, op2));
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    string postfix = "23*5+";
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}