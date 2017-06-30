//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//
//Example:
//
//Input: "cbbd"
//
//Output: "bb"
//
class Solution {
  public:
    std::string longestPalindrome(const std::string s) {
      string str;
      str.reserve(s.size()*2+1);
      str.push_back(' ');
      for (auto val:s) str.push_back(val), str.push_back(' ');
      vector <int> bound_of_loop;
      bound_of_loop.resize(str.size());
      int max_right = -1, symmetry_axis = -1;
      //    cout << '@' << str  << '@' << endl;

      for (int pos_now = 0, len = str.size(); pos_now < len; ++pos_now) {
        int boundary;
        if (pos_now >= max_right) {
          boundary = 0;
          for (; pos_now+boundary < len && pos_now-boundary >= 0; boundary++)
            if (str[pos_now-boundary] != str[pos_now+boundary]) break;
          if (max_right < pos_now+boundary+1) {
            symmetry_axis = pos_now;
            max_right = pos_now+boundary-1;
          }
          bound_of_loop[pos_now] = boundary-1;
          //        cout << "pos_now" << pos_now << "boundary" << boundary << endl;
        } else {
          int pre_axis = symmetry_axis*2 - pos_now;
          if (pre_axis + bound_of_loop[pre_axis] > symmetry_axis) {
            boundary = max_right-pos_now;
          } else {
            boundary = bound_of_loop[pre_axis]+1;
          }
        }

        for (; pos_now+boundary < len && pos_now-boundary >= 0; boundary++)
          if (str[pos_now-boundary] != str[pos_now+boundary]) break;
        if (max_right < pos_now+boundary-1) {
          symmetry_axis = pos_now;
          max_right = pos_now+boundary-1;
        }
        bound_of_loop[pos_now] = boundary-1;
      }
      int max_symmetry_axis = -1;
      int max_boundary = -1;
      for (int i = 0, len = str.size(); i < len; i++) {
        if (max_boundary < bound_of_loop[i]) {
          max_boundary = bound_of_loop[i];
          max_symmetry_axis = i;
        }
      }
      //debug
      //for (auto val:bound_of_loop) cout << val << ' ';
      //cout << endl;
      //cout << max_symmetry_axis << ' ' << max_boundary << endl;
      //cout << (max_symmetry_axis-max_boundary)/2 << ' ' << max_boundary << endl;
      //debug over
      return s.substr((max_symmetry_axis-max_boundary)/2, max_boundary); 
    }
};

