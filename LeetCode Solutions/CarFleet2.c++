class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double>res(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            // check if the car ahead is slower
            while (!s.empty() && cars[i][1] <= cars[s.top()][1]) {
                s.pop();
            }
            while (!s.empty()) {
                double collisionTime = (double)(cars[s.top()][0] - cars[i][0]) / (cars[i][1] - cars[s.top()][1]);
                if (collisionTime <= res[s.top()] || res[s.top()] == -1) {
                    res[i] = collisionTime;
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
