//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
// 
//
// 示例 3： 
//
// 
//输入：nums = [3,3], target = 6
//输出：[0,1]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 只会存在一个有效答案 
// 
//
// 进阶：你可以想出一个时间复杂度小于 O(n²) 的算法吗？ 
// Related Topics 数组 哈希表 👍 12010 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(pair<int,int>(nums[i],i));
        }

        sort(nums.begin(),nums.end());
        int m=0,n=nums.size()-1,sum=nums[m]+nums[n];
        while(sum!=target){
            if(sum>target)
                n--;
            else
                m++;
            sum=nums[m]+nums[n];
        }

        int count=mp.count(nums[m]);
        if (count==1){
            m=mp.find(nums[m])->second;
            n=mp.find(nums[n])->second;
        }
        else if (count==2){
            m=mp.find(nums[m])->second;
            n=(++mp.find(nums[n]))->second;
        }
        return {m,n};
    }//排序 O(NlogN) 后 查找 双指针法 O(N) ;总时间复杂度O(NlogN)，空间复杂度O(N)
     //暴力枚举算法:遍历两次，时间复杂度O(N^2)，空间复杂度O(1)
     //哈希表：时间复杂度O(N)，空间复杂度O(N)
};
//leetcode submit region end(Prohibit modification and deletion)
