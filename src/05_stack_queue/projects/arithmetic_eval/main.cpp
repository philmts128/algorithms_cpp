/*
 * Programa para avaliar expressões matemáticas usando RPN e pilha
 * Autor: Philippe Matias
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "stack.h"
#include "queue.h"
#include "vector.h"


/*---------------------------------------------*/
bool is_number(const string&  str)
{
    for (char c : str)
        if (!std::isdigit(c))
            return false;
    return true;
}

/*---------------------------------------------*/
int operator_prec(const string& op)
{
    switch (op[0])
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^':           return 3;
    }

    return -1;
}

/*---------------------------------------------*/
bool is_operator(const string& str)
{
    if (str.size() != 1) return false;

    switch (str[0])
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
    }

    return false;
}

/*---------------------------------------------*/
auto tokenizer(const string& expr, const string& sep) -> pm::vector<string>
{
    pm::vector<string> tokens;
    string cur;

    auto is_delim = [&](char c) {
        return sep.find(c) != string::npos; };

    for (size_t i = 0; i < expr.size(); ++i)
    {
        char c = expr[i];

        if (isspace(c)) {
            continue;
        } else if (is_delim(c)) {
            if (!cur.empty())
                tokens.append(cur);
            tokens.append({c});
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }

    if (!cur.empty())
        tokens.append(cur);
    return tokens;
}


/*---------------------------------------------*/
auto post_fix(const pm::vector<string>& tokens)
{
    pm::queue<string> out;
    pm::stack<string> operators;

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        string tok = tokens[i];

        if (is_number(tok)) {
            out.enqueue(tok);
            continue;
        }

        if (is_operator(tok)) {
            int op_proc = operator_prec(tok);
            while (operator_prec(operators.top()) >= op_proc) {
                auto op = operators.top();
                operators.pop();
                out.enqueue(op);
            }

            operators.push(tok);
            continue;
        }

        if (tok == "(") {
            operators.push(tok);
            continue;
        }

        if (tok == ")") {
            while (operators.top() != "(") {
                out.enqueue(operators.top());
                operators.pop();
            }

            operators.pop();
            continue;
        }
    }

    while (! operators.is_empty()) {
        out.enqueue(operators.top());
        operators.pop();
    }

    return out;
}


/*---------------------------------------------*/
int evaluate(const string& expr)
{
    auto post = post_fix(tokenizer(expr, "+-*/()^"));

    pm::stack<int> values;
    while (!post.is_empty())
    {
        string tok = post.front();

        if (is_number(tok)) {
            values.push(std::stoi(tok));
        }

        if (is_operator(tok))
        {
            int b = values.top();
            values.pop();

            int a = values.top();
            values.pop();

            switch (tok[0])
            {
                case '+': a += b; break;
                case '-': a -= b; break;
                case '*': a *= b; break;
                case '/': a /= b; break;
                case '^': a = (int)pow(a, b); break;
                default: break; //pssível erro
            }

            values.push(a);
        }

        post.dequeue();
    }

    return values.top();
}


/*---------------------------------------------*/
int main()
{
    string e = "2*3+4*5";

    cout << evaluate(e);

    printf("\n\n");
    return 0;
}
