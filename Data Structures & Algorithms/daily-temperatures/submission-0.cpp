class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //how do i use a stack for this
        //backwards stack?

        //monotonic stack
        stack<int> stk;
        vector<int> days(temperatures.size());
        int currTemp;
        for (int i = 0; i < temperatures.size(); ++i){
            currTemp = temperatures[i];
            if (stk.empty()){
                stk.push(i);
            } else {
                if (currTemp <= temperatures[stk.top()]){
                    stk.push(i);
                } else {
                    while(!stk.empty() && (temperatures[stk.top()] < currTemp)){
                        days[stk.top()] = i - stk.top();
                        stk.pop();
                    }
                    stk.push(i);
                }
            }
        }
        return days;

    }
};
