#include <bits/stdc++.h>

#define OPERAND 1
#define OPERATOR 0

// to check if the current character is an operand
int isOperand(char oper);

using namespace std;

// DRIVER FUNCTION
int main()
{
    // Input is the postfix expression
    char postfix[] = "73426^*+*8+";
    int res, postfix_ind, postfix_size, op1, op2;
    //declaring a stack to store the operands
    stack<int> operands;
    //traversing the input postfix expression
    for (postfix_ind = 0; postfix[postfix_ind]; postfix_ind++)
    {
        //if the current character is an operand, then push 
        //it to the stack
        if (isOperand(postfix[postfix_ind]) == OPERAND)
            operands.push(postfix[postfix_ind] - '0');
        //if the current character is an operator, then the
        //corresponding operation is performed
        else
        {
            op2 = operands.top();
            operands.pop();
            op1 = operands.top();
            operands.pop();

            switch (postfix[postfix_ind])
            {
            case '+':
                operands.push(op1 + op2);
                break;
            case '-':
                operands.push(op1 - op2);
                break;
            case '*':
                operands.push(op1 * op2);
                break;
            case '^':
                operands.push((int)pow(op1, op2));
                break;
            }
        }
    }
    // The final value of the expression is stored in res
    res = operands.top();
    operands.pop();
    // Printing the value of the evaluated postfix expression
    printf("\nThe value of the postfix expression is : %d", res);

    return 0;
}

int isOperand(char oper)
{
    return isdigit(oper);
}
