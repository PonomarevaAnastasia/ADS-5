// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int getPrior(char a) {
    if (a == '(')
        return 0;
    else if (a == ')')
        return 1;
    else if (a == '+' || a == '-')
        return 2;
    else if (a == '*' || a == '/')
        return 3;
    return 0;
}
std::string infx2pstfx(std::string inf) {
    std::string str = "";
    int Obj = 0;
    TStack<char> myStack;
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] >= '0' && inf[i] <= '9') {
            if (i < inf.size() - 1 && inf[i + 1] >= '0' && inf[i + 1] <= '9') {
                str.push_back(static_cast<char>(inf[i]));
            } else {
                str.push_back(static_cast<char>(inf[i]));
                str.push_back(' ');
            }
        } else {
            Obj = getPrior(inf[i]);
            if ((Obj == 0) || (myStack.isEmpty()) || (pr > getPrior(myStack.get()))) {
            if (pr == 0 || myStack.isEmpty() || Obj > getPrior(myStack.get())) {
                myStack.push(inf[i]);
            } else if (Obj == 1) {
                while (myStack.get() != '(') {
                    if (myStack.get() != ')' && myStack.get() != '(') {
                        str.push_back(myStack.get());
                        str.push_back(' ');
                    }
                    myStack.pop();
                }
                myStack.pop();
            } else {
                while (!myStack.isEmpty() && getPrior(myStack.get()) >= Obj) {
                    str.push_back(myStack.get());
                    str.push_back(' ');
                    myStack.pop();
                }
                myStack.push(inf[i]);
            }
        }
    }
    while (!myStack.isEmpty()) {
        str.push_back(myStack.get());
        str.push_back(' ');
        myStack.pop();
    }
    str.pop_back();
    return str;
}

int eval(std::string pref) {
 int eval(std::string post) {
    TStack<int> stack1;
    int num = 0;
    for (int i = 0; i < post.size(); i++) {
        if (post[i] >= '0' && post[i] <= '9') {
            num = num * 10 + (post[i] - '0');
        } else if (post[i] == ' ') {
            if (num != 0) {
                stack1.push(num);
                num = 0;
            }
        } else {
            int per1 = stack1.get();
            stack1.pop();
            int per2 = stack1.get();
            stack1.pop();
            switch (post[i]) {
            case '+':
                stack1.push(per2 + per1);
                break;
            case '-':
                stack1.push(per2 - per1);
                break;
            case '*':
                stack1.push(per2 * per1);
                break;
            case '/':
                if (op1 != 0) {
                    stack1.push(per2 / per1);
                } else {
                    throw "Delenie na null";
                }
                break;
            }
        }
    }
    return stack1.get();
}
