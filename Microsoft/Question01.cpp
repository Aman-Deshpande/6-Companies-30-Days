// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto s: tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                if(s=="+"){
                    a=b+a;
                }else if(s=="-"){
                    a=b-a;
                }else if(s=="/"){
                    a=b/a;
                }else if(s=="*"){
                    a=b*a;
                }

                st.push(a);
            }else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};