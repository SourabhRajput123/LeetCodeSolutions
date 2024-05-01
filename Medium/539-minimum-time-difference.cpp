class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
         vector<int> minutes;
        for (const string& time : timePoints) {
            minutes.push_back(convertToMinutes(time));
        }
        
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        minDiff = min(minDiff, 24 * 60 - (minutes.back() - minutes.front()));
        
        return minDiff;
    }
    
private:
    int convertToMinutes(const string& time) {
        stringstream ss(time);
        int hours, minutes;
        char colon;
        ss >> hours >> colon >> minutes;
        return hours * 60 + minutes;
    }
};