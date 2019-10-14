#include <iostream>
#include <stack>
using namespace std;

bool balancedParenthesis(string s){
    int n = s.length();
    if(n == 0)  
        return true;

    stack<char> st;
    for(int i=0; i<n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if(st.empty())
            return false;
        else if((s[i] == '}' && st.top() == '{') || (s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '['))
            st.pop();
        else    
            return false;
    }

    if(st.empty())
        return true;
    return false;
}

int main(){
    string str;
    cin >> str;
    if(balancedParenthesis(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}