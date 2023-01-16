// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* curr = head;

        unordered_map<int, ListNode*> m;
        m[0]=dummy;

        int prefixSum = 0;
        while(curr){
            prefixSum+=curr->val;
            if(m.find(prefixSum)!=m.end()){
                ListNode *p = m[prefixSum]->next;
                int val = prefixSum;
                while(p!=curr){
                    val+=p->val;
                    m.erase(val);
                    p=p->next;
                }
                m[prefixSum]->next=curr->next;
            }else{
                m[prefixSum]=curr;
            }

            curr=curr->next;
        }

        return dummy->next;
    }
};