// Reverse Polish Notation
// Valid characters: + - * / ^ ( ) and any number
// Valid form for input string: 1 + (5 - 3) * (3 - 1) ^ 2

#include <iostream>
#include "ExpressionParser.h"

using namespace std;

int main() {

    vector<string> expressions = {
            "-4.32^ 3 + 2.25 * 4 - ((-3 - 4) + (2 - 10 * 0.3)) / 7",
            "1 + 3",
            "2 + 2 * 2",
            "(2 + 2) * 2",
            "-56 * 0.25",
            "2 ^ 2 ^ 2 ^ 2",
            "12 + 2 * ( ( 3 * 4 ) + ( 10 / 5 ) )",
            "3 +4 * 2 / (1-5) ^ 2",
            "1 / 9",
            "-1 + (-5) * (2 - (2 / 5))",
            "45*789 + 78 ^ ( 1 / 6 + 6 / 8 )",
            "897 / 78 + 453 ^ ( -0.5 )",
            "( 343 * ( -89 ) + 18 ) - 12 ^ 2.9"
    };

    ExpressionParser expression;
    for(int i = 0, n = expressions.size(); i < n; ++i){
        expression.changeExpression(expressions[i]);

        double result = expression.calculatePostfix();
        string infix = expression.makeInfixString();
        string postfix = expression.makePostfixString();

        cout << i + 1 << ".\t" << infix << " = " << result << endl;
        cout << "\t" << "Reverse polish notation: " << postfix << endl;
    }

}