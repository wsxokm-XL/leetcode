//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
// Related Topics 递归 链表 数学 👍 6709 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ll1=l1,*ll2= l2,*head=nullptr,*tail=nullptr,*l3=nullptr,*tmp=nullptr;
        int sum,ten=0;
        while(1)
        {
            sum=ll1->val+ll2->val+ten;

            head=new ListNode;
            head->val=sum%10;
            head->next= nullptr; //head=new ListNode(sum%10,nullptr);

            ten=sum/10;
            if(l3==nullptr){
                l3=head;
                tail=l3;
            }
            else{
                tail->next=head;
            }
            tail=head;

            if(ll1->next==nullptr && ll2->next== nullptr) break;
            else if (ll1->next==nullptr) {
                tmp=new ListNode;
                tmp->val=0;
                tmp->next= nullptr;
                ll1->next=tmp;
            }
            else if (ll2->next==nullptr) {
                tmp=new ListNode;
                tmp->val=0;
                tmp->next= nullptr;
                ll2->next=tmp;
            }

            ll1=ll1->next;
            ll2=ll2->next;
        }

        if(ten==1){
            head=new ListNode;
            head->val=ten;
            tail->next=head;
            tail=head;
        }

        //delete tail;?
        return l3;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
