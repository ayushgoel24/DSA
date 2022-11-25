#include <iostream>
#include <string.h>
#include <stack>

class Solution {
private:
    inline bool is_op( char c ) {
        return ( c == '/' || c == '*' || c == '+' || c == '-' );
    }

public:
    int calculate1(std::string s) {
        s += '+';
        
        std::stack<int> expressionContainer; 
        long long int expressionResult = 0, currentExpression = 0;
        char opr = '+';
        
        for ( int i=0; i < s.size(); i++ ) {
            
            // Until we reach any operator, we keep on forming the number
            if ( isdigit(s[i]) ) currentExpression = currentExpression * 10 + ( s[i]-'0' );
            
            else if ( s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-' ) {
                
                // Divide the value on the top of stack with the current number and then push it to stack
                if ( opr == '/' ) {
                    int previousNumInStack = expressionContainer.top();
                    expressionContainer.pop(); 
                    expressionContainer.push( previousNumInStack / currentExpression );
                } else if ( opr == '*' ) {
                    // Multiply the value on the top of stack with the current number and then push it to stack
                    int previousNumInStack = expressionContainer.top();
                    expressionContainer.pop(); 
                    expressionContainer.push( previousNumInStack * currentExpression );
                } else if ( opr == '+' ) {
                    // Adds the number in the stack so that it gets added in the expression
                    expressionContainer.push( currentExpression );
                } else if ( opr == '-' ) {
                    // Adds the negative of the number in the stack so that it gets added in the expression
                    expressionContainer.push( -1 * currentExpression );
                }
                
                currentExpression = 0; 
                opr = s[i]; 
            }
        }
        
        while (!expressionContainer.empty()) {
            expressionResult += expressionContainer.top(); 
            expressionContainer.pop();
        }
            
        return expressionResult;    
    }

    int calculate(std::string s) {
        long long int expressionResult = 0, currentExpression = 0, previousExpression = 0;
        char opr = '+';
        
        for ( int i=0; i < s.length(); i++ ) {
            
            // Until we reach any operator, we keep on forming the number
            if ( isdigit(s[i]) ) currentExpression = currentExpression * 10 + ( s[i] - '0' );
            
            if ( is_op( s[i] ) || i == s.length() - 1 ) {
                
                // Divide the value on the top of stack with the current number and then push it to stack
                if ( opr == '/' && currentExpression != 0 ) previousExpression /= currentExpression;
                else if ( opr == '*' ) previousExpression *= currentExpression;
                else if ( opr == '+' || opr == '-' ) {
                    expressionResult += previousExpression;
                    previousExpression = ( opr == '+' ? currentExpression : -currentExpression );
                }
                
                currentExpression = 0; 
                opr = s[i]; 
            }
        }
        expressionResult += previousExpression;
            
        return (int) expressionResult;    
    }
};