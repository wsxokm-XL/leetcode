//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 示例 4: 
//
// 
//输入: s = ""
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
// Related Topics 哈希表 字符串 滑动窗口 👍 6063 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int s_length=s.length(),length=0,tmp_length=0,start=0;
        if(s_length<=1)
            return s_length;

        for(int i=0;i<s_length;i++){
            if(mp.find(s[i])==mp.end()||mp[s[i]]<start){
                tmp_length++;
            }
            else {
                if(tmp_length>length) length=tmp_length;
                start=mp[s[i]]+1;
                tmp_length=i-mp[s[i]];
            }
            mp[s[i]]=i;
        }

        if(tmp_length>length) length=tmp_length;

        return length;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
