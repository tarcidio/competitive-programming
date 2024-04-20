// Time: O(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(), 0);
        // Loop through temperatures
        for(int i = 0; i < temperatures.size(); i++){
            // Verify if the top is lower than current temperature
            while(!st.empty() && temperatures[i] > st.top().first ){
                // If yes, so update answer vector
                int lastTemp = st.top().first;
                int lastIndice = st.top().second;
                st.pop();

                ans[lastIndice] =  i - lastIndice;
            }
            // Put the value to future analysis
            st.push(make_pair(temperatures[i], i));
        }

        return ans;
    }   
};
