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

 
 //add in reverse order
 //or simply unreverse them then add and then reverse them finally
int reverse(int<vector>&gg)
{

    int start = 0;
    int end = gg.size() - 1;


    while(start<=end)
    {
        swap(gg[start++],gg[end--]);

    }

    int add(int a,int b)
    {
        return a+b;

    }

}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        vector<int>ll = reverse(l1);
        vector<int>gl = reverse(l2);

        vector<int>summ = add(l1,l2);


        return reverse(summ);

    }
};