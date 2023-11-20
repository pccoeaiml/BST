#include <iostream>
#include <cctype>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(char c) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = c;
        } else {
            cerr << "Stack overflow!" << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cerr << "Stack underflow!" << endl;
            return '\0';
        }
    }

    char peek() const {
        if (top >= 0) {
            return arr[top];
        } else {
            cerr << "Stack is empty!" << endl;
            return '\0';
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// string infixToPostfix(const string& infix) {
//     Stack opStack;
//     string postfix = "";

//     for (char ch : infix) {
//         if (isalnum(ch)) {
//             postfix =postfix+ ch;
//         } else if (ch == '(') {
//             opStack.push(ch);
//         } else if (ch == ')') {
//             while (!opStack.isEmpty() && opStack.peek() != '(') {
//                 postfix += opStack.pop();
//             }
//             opStack.pop();
//         } else if (isOperator(ch)) {
//             while (!opStack.isEmpty() && getPrecedence(opStack.peek()) >= getPrecedence(ch)) {
//                 postfix += opStack.pop();
//             }
//             opStack.push(ch);
//         }
//     }

//     while (!opStack.isEmpty()) {
//         postfix += opStack.pop();
//     }

//     return postfix;
// }

string infixToPostfix(const string& infix){
    Stack obj;
    string postfix="";
    for(char ch:infix){
        if(isalnum(ch)){
            postfix=postfix+ch;
        }else if(ch=='('){
            obj.push(ch);
        }else if(ch==')'){
            while(!obj.isEmpty() && obj.peek()!='('){
                postfix=postfix+obj.pop();
            }
            obj.pop();
        }else if(isOperator(ch)){
            while(!obj.isEmpty() && getPrecedence(obj.peek())>=getPrecedence(ch)){
                postfix=postfix+obj.pop();
            }
            obj.push(ch);
        }
    }

    while(!obj.isEmpty()){
        postfix=postfix+obj.pop();
    }
    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
