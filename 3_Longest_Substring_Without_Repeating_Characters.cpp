//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int ans = 0;
      int pos_appered[256];
      memset(pos_appered, -1, sizeof(pos_appered));

      int cnt = 0;
      for (int i = 0, len = s.size(); i < len; i++) {
        if (pos_appered[s[i]] == -1) pos_appered[s[i]] = i, cnt++;
        else {
          ans = max(cnt, ans);
          int cnt_now = i-pos_appered[s[i]];
          for (int p = pos_appered[s[i]]-(cnt-cnt_now); p <= pos_appered[s[i]]; p++) pos_appered[s[p]] = -1;
          pos_appered[s[i]] = i;
          cnt = cnt_now;
        }
        //      cout << "round" << i << ": ";
        //      for (int i = 'a'; i <= 'z'; i++)  cout << pos_appered[i] << ' ';
        //      cout << endl;
      }
      ans = max(cnt, ans);
      return ans;
    }
};
