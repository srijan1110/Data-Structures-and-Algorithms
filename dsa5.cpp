#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Stack {
public:
    int top;
    int arr[MAX_SIZE];

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << " popped from stack" << endl;
    cout << s.peek() << " is at the top of the stack" << endl;

    return 0;
}