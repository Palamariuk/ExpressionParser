

#include "ExpressionParser.h"

ExpressionParser::ExpressionParser(const string &_expression) {
    changeExpression(_expression);
}

void ExpressionParser::createPostfix() {
    stack<string> operations;
    for(auto &i: infix){
        if(isdigit(i[0]) || i.length() > 1){
            postfix.push_back(i);
        } else if(i[0] == '('){
            operations.push(i);
        } else if(i[0] == ')'){
            while(operations.top() != "("){
                postfix.push_back(operations.top());
                operations.pop();
            }
            operations.pop();
        } else{
            if(!operations.empty()){
                if(getPriority(operations.top()) >= getPriority(i)){
                    postfix.push_back(operations.top());
                    operations.pop();
                }
            }
            operations.push(i);
        }
    }
    while(!operations.empty()) {
        postfix.push_back(operations.top());
        operations.pop();
    }
}

/*
 * Calculates a result of operation 'op' and numbers 'a' and 'b'.
 * Returns double as a result.
 * */
double ExpressionParser::calculateOperation(double a, double b, string op) {
    char oper = op[0];
    double result = 0;
    switch (oper) {
        case '+': result = b + a; break;
        case '-': result = b - a; break;
        case '*': result = b * a; break;
        case '/': result = b / a; break;
        case '^': result = pow(b, a); break;
    }
    return result;
}

double ExpressionParser::calculatePostfix() {
    stack<double> numbers;
    for(auto &i: postfix){
        if(isdigit(i[0]) || i.length() > 1){
            numbers.push(stod(i));
        } else {
            double a = numbers.top();
            numbers.pop();
            double b = numbers.top();
            numbers.pop();
            double num = calculateOperation(a, b, i);
            numbers.push(num);
        }
    }
    return numbers.top();
}

//Returns a priority of operations.
int ExpressionParser::getPriority(string op) {
    char oper = op[0];
    switch (oper) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void ExpressionParser::changeExpression(const string &_expression) {
    expression = " " + _expression + " ";

    infix.clear();
    postfix.clear();

    //Divide the expression into components
    for(int i = 0; i < expression.length(); ++i){
        if(valid.find(expression[i]) != std::string::npos){
            if(expression[i] == '-' && (expression[i - 1] == '(' || expression[i - 1] == ' ') && isdigit(expression[i + 1])){
                string str = string(1, expression[i]) + expression[i + 1];
                infix.push_back(str);
                ++i;
                continue;
            }
            infix.push_back(string(1, expression[i]));
        } else if(isdigit(expression[i]) || expression[i] == '.'){
            if(isdigit(expression[i - 1]) || expression[i - 1] == '.'){
                infix[infix.size() - 1] += expression[i];
            } else {
                infix.push_back(string(1, expression[i]));
            }
        }
    }

    createPostfix();
}

string ExpressionParser::makePostfixString() {
    string result;
    for(auto &i: postfix) result += i + " ";
    return result;
}

string ExpressionParser::makeInfixString() {
    string result;
    for(auto &i: infix) result += i + " ";
    return result;
}

