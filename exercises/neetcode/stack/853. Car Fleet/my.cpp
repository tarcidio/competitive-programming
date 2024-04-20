// Time: O(N)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> pos_speed(n);
        for(int i = 0; i < n; i++){
            pos_speed[i] = make_pair(position[i], speed[i]);
        }
        sort(pos_speed.rbegin(), pos_speed.rend());

        vector<float> time(n);
        for(int i = 0; i < n; i++)
            time[i] = (target - pos_speed[i].first)/pos_speed[i].second;
        
        int i = 0, j = 1, ans = 1;

        while(j < time.size()){
            float tcar1 = time[i];
            float tcar2 = time[j];
            if( !(tcar2 <= tcar1) ){
                i = j;
                ans++;
            }               
            j++;
        }

        return ans;
    }
};
