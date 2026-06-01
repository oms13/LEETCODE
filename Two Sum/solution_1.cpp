#include <iostream>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valInd; // value->indices
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (valInd.find(complement) != valInd.end())
                return {valInd[complement], i};
            valInd[nums[i]] = i;
        }
        return {};
    }
};