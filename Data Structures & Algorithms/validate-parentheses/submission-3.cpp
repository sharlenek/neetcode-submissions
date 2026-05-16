class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s.size() == 1){
            return false;
        }
        stack<char> stack;
        for (char c : s ){
            if (c == '(' || c =='[' || c == '{'){
                stack.push(c);
            } else {
                if (!stack.empty()){
                    char top = stack.top();
                    stack.pop();
                    if (c == ')'){
                        if (top != '('){
                            return false;
                        }
                    } else if (c == '}'){
                        if (top != '{'){
                            return false;
                        }
                    } else if (c == ']'){
                        if (top != '['){
                            return false;
                        }
                    } 
                } else {
                    return false;
                }
            }
        }
        if (!stack.empty()){
            return false;
        }
        return true;
    }
};
