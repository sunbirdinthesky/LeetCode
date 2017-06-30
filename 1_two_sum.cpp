//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//      Because nums[0] + nums[1] = 2 + 7 = 9,
//      return [0, 1].
//

class Solution {
  public:
    vector<int> twoSum(vector<int> input, int target) {
      //最高复杂度介于O（n）与O（nlogn）之间，从概率上讲为O（n）
      vector <int> ans;
      unordered_map <int, int> pool;
      for (int i = 0, len = input.size(); i < len; i++) {
        if (pool.find(target - input[i]) != pool.end()) {
          ans.push_back(i);
          ans.push_back(pool[target-input[i]]);
        }
        pool[input[i]] = i;
      }
      if (ans[0] > ans[1]) swap(ans[0], ans[1]);
      return ans;
    }
};

