class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;
        for (string s : tokens){
            int one;
            int two;
            int result;
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                two = sk.top();
                sk.pop();
                one = sk.top();
                sk.pop();
                if (s == "+"){
                    result = one + two;
                } else if (s == "-"){
                    result = one - two;
                } else if (s == "*"){
                    result = one * two;
                } else if (s == "/"){
                    result = one / two;
                }
                sk.push(result);
            } else {
                sk.push(stoi(s));
            }
        }
        return sk.top();
    }
};
