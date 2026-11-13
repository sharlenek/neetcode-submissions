class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //have to go one level at a time
        vector<vector<int>> courses(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int r = 0; r < prerequisites.size(); ++r){
                int course = prerequisites[r][0];
                int prereq = prerequisites[r][1];

                //indegree is how many courses it needs before u can reach it
                indegree[course]++;
                courses[prereq].push_back(course);

            
        }

        //making a queue of courses that have no pre req

        queue<int> noprereq;
        for (int i = 0; i < courses.size(); ++i){
            if (indegree[i] == 0){
                noprereq.push(i);
            }
        }

        //for every course with no prereq. go thru what courses need it (level
        //by level) and then track if its visited?

        int completedcourses = 0;
        while (!noprereq.empty()){
            int currcourse = noprereq.front();
            noprereq.pop();
            completedcourses++;

            for (int i = 0; i < courses[currcourse].size(); ++i){
                int nextcourse = courses[currcourse][i];

                indegree[nextcourse]--;

                if (indegree[nextcourse] == 0){
                    noprereq.push(nextcourse);
                }
            }
        }

        if (completedcourses == numCourses){
            return true;
        }
        return false;

    }
};
