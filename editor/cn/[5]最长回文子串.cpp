//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出："a"
// 
//
// 示例 4： 
//
// 
//输入：s = "ac"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母（大写和/或小写）组成 
// 
// Related Topics 字符串 动态规划 👍 4057 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int s_length=s.length();
        if (s_length==1)
            return s;
        int start,end,res_start=0,res_end=0,res_length=1;
        for (int i=1;i<s_length;i++){
            if(s[i-1]==s[i+1]){
                start=i-1;
                end=i+1;
                while(start-1>=0&&end+1<s_length&&s[start-1]==s[end+1]){
                    start--;
                    end++;
                }
                if (end-start+1>res_length){
                    res_start=start;
                    res_end=end;
                    res_length=end-start+1;
                }
            }
            if (s[i-1]==s[i]){
                start=i-1;
                end=i;
                while(start-1>=0&&end+1<s_length&&s[start-1]==s[end+1]){
                    start--;
                    end++;
                }
                if (end-start+1>res_length){
                    res_start=start;
                    res_end=end;
                    res_length=end-start+1;
                }
            }
        }

        return s.substr(res_start,res_length);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
