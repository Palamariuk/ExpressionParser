/*
 * Created by palamariuk on 30.08.20.
 * */

#ifndef ___EXPRESSIONPARSER_H
#define ___EXPRESSIONPARSER_H

#include <string>
#include <cmath>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

class ExpressionParser {
private:
    string expression;
    vector<string> infix;
    vector<string> postfix;

    string valid = "+-*/()^";

    void createPostfix();

protected:

    static int getPriority(string op);

    static double calculateOperation(double a, double b, string op);

public:

    ExpressionParser()= default;

    explicit ExpressionParser(const string& _expression);

    void changeExpression(const string& _expression);

    string makeInfixString();
    string makePostfixString();

    double calculatePostfix();

};


#endif //___EXPRESSIONPARSER_H
