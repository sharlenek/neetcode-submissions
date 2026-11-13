class Solution {
    public:
    vector<int> findOrder (int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        //how many prereqs it has
        vector<int> prereqcount(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); ++i){
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            courses[prereq].push_back(course);
            prereqcount[course]++;
        }

        //push all courses that can be taken now
        queue<int> availablecourses;
        for (int i = 0; i < numCourses; ++i){
            if (prereqcount[i] == 0){
                availablecourses.push(i);
            }
        }

        vector<int> validpath;

        while (!availablecourses.empty()){
                int currcourse = availablecourses.front();
                validpath.push_back(currcourse);
                availablecourses.pop();

                //check for each class that counts on this
                for (int j = 0; j < courses[currcourse].size(); ++j){
                    int nextcourse = courses[currcourse][j];

                    prereqcount[nextcourse]--;
                    if (prereqcount[nextcourse] == 0){
                        availablecourses.push(nextcourse);
                    }
                }
            
        }

        if (numCourses == validpath.size()){
            return validpath;
        }
        return {};


    }
};