#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>
struct Node
        {
    T data;
    Node<T>* next;
        };

// implementing stack using singly linked list
template <typename T>
class Stack
        {
        private:
            Node<T>* top;
        public:
            Stack()
            {
                top = NULL;
            }

            // checking if the stack is empty
            bool isEmpty()
            {
                if (top == NULL)    {return true;}
                else                {return false;}
            }

            // pushing data onto stack
            void push(T data)
            {
                Node<T>* temp = new Node<T>;
                temp -> data = data;
                temp -> next = top;
                top = temp;
            }

            // peeking the top of the stack
            T peek()
            {
                return top -> data;
            }

            // pop out the top of the stack
            T pop()
            {
                T temp = top -> data;
                top = top -> next;
                return temp;
            }

            // display the stack
            void display()
            {
                Node<T>* temp = top;
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp -> next;
                }
                cout << endl;
            }
        };

// function to check if the character is an operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')   {return true;}
    else                                                            {return false;}
}

// precedence order of operators
int precedence(char c)
{
    if (c == '^')                   {return 3;}
    else if (c == '*' || c == '/')  {return 2;}
    else if (c == '+' || c == '-')  {return 1;}
    else                            {return -1;}
}

// infix to postfix conversion function
string infixToPostfix(Stack<char> s, string infix)
{
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        // printing operands as they arrive
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }

            // opening and closing brackets
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.peek() != '(') && (!s.isEmpty()))
            {
                postfix += s.peek();
                s.pop();
            }
            if (s.peek() == '(')
            {
                s.pop();
            }
        }

            // operators
        else if (isOperator(infix[i]))
        {
            if (s.isEmpty())
            {
                s.push(infix[i]);
            }
            else
            {
                // higher precedence
                if (precedence(infix[i]) > precedence(s.peek()))
                {
                    s.push(infix[i]);
                }

                // equal precedence and R->L associativity
                else if ((precedence(infix[i]) == precedence(s.peek())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }

                // lower precedence or equal precedence & L->R associativity
                else
                {
                    while ((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.peek())))
                    {
                        postfix += s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    // remaining operators in the stack
    while (!s.isEmpty())
    {
        postfix += s.peek();
        s.pop();
    }

    return postfix;
}

// infix to prefix conversion function
string infixToPrefix(Stack <char> s, string infix)
{
    string prefix;

    // reversing the infix expression
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')        {infix[i] = ')';}
        else if (infix[i] == ')')   {infix[i] = '(';}
    }

    for (int i = 0; i < infix.length(); i++)
    {
        // printing operands as they arrive
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            prefix += infix[i];
        }

        // opening and closing brackets
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.peek() != '(') && (!s.isEmpty()))
            {
                prefix += s.peek();
                s.pop();
            }
            if (s.peek() == '(')
            {
                s.pop();
            }
        }

        // operators
        else if (isOperator(infix[i]))
        {
            if (s.isEmpty())
            {
                s.push(infix[i]);
            }
            else
            {
                // higher precedence
                if (precedence(infix[i]) > precedence(s.peek()))
                {
                    s.push(infix[i]);
                }

                // equal precedence and R->L associativity
                else if ((precedence(infix[i]) == precedence(s.peek())) && (infix[i] == '^'))
                {
                    while ((precedence(infix[i]) == precedence(s.peek())) && (infix[i] == '^'))
                    {
                        prefix += s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }

                // equal precedence and L->R associativity
                else if (precedence(infix[i]) == precedence(s.peek()))
                {
                    s.push(infix[i]);
                }

                // lower precedence
                else
                {
                    while ((!s.isEmpty()) && (precedence(infix[i]) < precedence(s.peek())))
                    {
                        prefix += s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    // remaining operators in the stack
    while (!s.isEmpty())
    {
        prefix += s.peek();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// evaluating prefix and postfix expressions
int operation(char c, int a, int b)
{
    if (c == '+')           {return b+a;}
    else if (c == '-')      {return b-a;}
    else if (c == '*')      {return b*a;}
    else if (c == '/')      {return b/a;}
    else if (c == '^')      {return pow(b,a);}
    else                    {return 0;}
}

int postfixEvaluation(string postfix)
{
    Stack<int> stack;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperator(postfix[i]))
        {
            int a = stack.pop();
            int b = stack.pop();
            int result = operation(postfix[i], a, b);
            stack.push(result);
        }
        else
        {
            stack.push(postfix[i] - '0');
        }
    }
    return stack.pop();
}

int prefixEvaluation(string prefix)
{
    reverse(prefix.begin(), prefix.end());
    return postfixEvaluation(prefix);
}

int main()
{
    cout << "Infix to prefix & postfix conversion using stack data structure:" << endl;
    cout << "\n1 - Convert infix expression to prefix expression" << endl;
    cout << "2 - Convert infix expression to postfix expression" << endl;
    cout << "3 - Evaluate prefix expression" << endl;
    cout << "4 - Evaluate postfix expression" << endl;
    cout << "0 - Exit" << endl;
    cout << "Choose the option:";
    int choice;
    cin >> choice;

    switch (choice)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            string infixExp1, prefixExp1;
            cout << "Enter an infix expression (without spaces):";
            cin >> infixExp1;
            Stack <char> stack1;
            cout << "Infix Expression: " << infixExp1 << endl;
            prefixExp1 = infixToPrefix(stack1, infixExp1);
            cout << "Prefix Expression: " << prefixExp1 << endl;
            break;
        }
        case 2:
        {
            string infixExp2, postfixExp1;
            cout << "Enter an Infix Expression (without spaces):";
            cin >> infixExp2;
            Stack <char> stack2;
            cout << "Infix Expression: " << infixExp2 << endl;
            postfixExp1 = infixToPostfix(stack2, infixExp2);
            cout << "Postfix Expression: " << postfixExp1 << endl;
            break;
        }
        case 3:
        {
            string prefixExp2;
            cout << "Enter a prefix expression (without spaces):";
            cin >> prefixExp2;
            int evaluation1 = prefixEvaluation(prefixExp2);
            cout << "Evaluation of given prefix expression gives the result: " << evaluation1 << endl;
            break;
        }
        case 4:
        {
            string postfixExp2;
            cout << "Enter a prefix expression (without spaces):";
            cin >> postfixExp2;
            int evaluation2 = postfixEvaluation(postfixExp2);
            cout << "Evaluation of given prefix expression gives the result: " << evaluation2 << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}
