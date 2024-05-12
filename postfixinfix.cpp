#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
string postfixToInfix(queue<char> q) {
    stack<string> s;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        if (isalnum(c)) {
            string operand(1, c);
            s.push(operand);
        } 
        else if (isOperator(c)) {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string expression = "(" + operand1 + c + operand2 + ")";
            s.push(expression);
        }
    }
    return s.top();
}
// Print the queue
void showq(queue<char> gq) {
    queue<char> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
int main() {
    queue<char> postFixExpression;

    //enqueue  postfix expression
    postFixExpression.push('2');
    postFixExpression.push('3');
    postFixExpression.push('1');
    postFixExpression.push('*');
    postFixExpression.push('+');
    postFixExpression.push('9');
    postFixExpression.push('-');

    cout << "Postfix expression: ";
    showq(postFixExpression);

    string infixExpr = postfixToInfix(postFixExpression);
    cout << "Infix expression: " << infixExpr << endl;

    return 0;
}
