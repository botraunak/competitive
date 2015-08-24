/*

 SPOJ PROBLEM : ONP - Transform the Expression
 URL : http://www.spoj.com/problems/ONP/

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// function to check if its operand
bool check_if_operand(char a){
	if(a == '+' || a == '-' || a == '/' || a == '*' ||  a == '^' || a == '(' || a == ')')
		return true;
	return false;
}

// function to get priority same = 0 , lower -1 , higher 1
int get_priority(char a,char b){
	if (a == '^' )
		return 1;
	if (b == '^')
		return -1;
	if ((a == '+' || a == '-') && (b == '-' || b =='+'))
		return 0;
	if ((a == '*' || a == '/') && (b == '*' || b =='/'))
		return 0;
	if ((a == '*' || a == '/') && (b == '+' || b == '/'))
		return 1;
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	int t; // number of expressions
	cin>>t;
	std::string expression; // expression to conver to RPN  
	while(t--){
		stack<char> op_stack,test; // Stack of operators
		cin>>expression;
		std::string rpn;
		int counter = 0;
		char op;
		for(int i=0;i<expression.length();i++){
			bool is_operator = check_if_operand(expression[i]);
			if(is_operator){
				op = expression[i];
				if (op == '(')
					op_stack.push(op);
					// cout<<op;
				if (op == ')'){
					// pop all elements and add to rpn
					while(op_stack.top() != '(' || op_stack.empty()){
						rpn += op_stack.top();
						op_stack.pop();
					}
					op_stack.pop();
				}
				if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' )
				{
					// // getting the last operand
					char top_op = op_stack.top();
					int priority = get_priority(top_op,op);
					if(priority == -1)
						op_stack.push(op);
					if(priority == 0){
						rpn += top_op;
						op_stack.push(op);	
						op_stack.push(op);	
					}
				}
			}else{
				// Add operand Directly
				rpn += expression[i];
			}	
		}	
		// Printing the result RPN
		cout<<rpn<<endl;
	}
return 0;
}