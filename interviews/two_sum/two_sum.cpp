#include <algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        int value;
        unordered_map<int, int> hash;

        for (int i = 0; i < numbers.size(); i++) {
            value = target - numbers[i];
            if (hash.find(value) != hash.end()) {
                result.push_back(hash[value]);
                result.push_back(i);
                return result;
            }
            hash[numbers[i]] = i;
        }
        return result;
    }
    
};
