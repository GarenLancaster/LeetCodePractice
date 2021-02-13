//
// Created by Administrator on 2021/2/8.
//
#include<iostream>

using namespace std;

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resutle=l1;//不含头节点,结果
        ListNode* nodeOrg=l1;//执行相加的被加数
        ListNode* nodeVassal=l2;//指向加数
        ListNode* nodePrever;
        int sum;
        int valL2=0,valL1=0;
        int carry=0;
        bool endl1= false,endl2= false;
        while(true)
        {
            if(nodeOrg!= nullptr)
            {
                valL1=nodeOrg->val;
            }
            else
                valL1=0;
            if(nodeVassal!= nullptr)
            {
                valL2=nodeVassal->val;
            }
            else
                valL2=0;

            sum=valL1+valL2+carry;

            if(endl1&&!endl2)//将较长的l2切断并接入l1尾端，保证接下来的按照l1是最长的方案执行
            {
                nodePrever->next=nodeVassal;
                nodeOrg=nodeVassal;
                nodeVassal= nullptr;

                //重置flag，防止再次进入
                endl2= true;
                endl1= false;
            }

            if(sum<10) {
                nodeOrg->val = sum;
                carry = 0;
            }
            else {
                nodeOrg->val = sum % 10;
                carry=1;
            }
            if(nodeOrg!= nullptr) {
                nodePrever=nodeOrg;
                nodeOrg = nodeOrg->next;
            }
            if(nodeOrg== nullptr)
            {
                endl1 = true;
            }
            if(nodeVassal!= nullptr)
                nodeVassal=nodeVassal->next;

            if(nodeOrg== nullptr&&nodeVassal== nullptr)
            {
                if(carry>0){
                    ListNode *node=new ListNode(carry);
                    nodePrever->next=node;
                }

                return resutle;
            }
        }
    }
};
string PrintList(ListNode *l)
{
    ListNode* p=l;
    while(p!= nullptr)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    return "";
}
int amain(){
    ListNode *l1,*l2;
    ListNode *p1,*p2;
    p1=l1=new ListNode(9);
    p2=l2=new ListNode(9);
    for(int i=0;i<8;i++)
    {
        if(i%2==0)
        {
            p1->next=new ListNode(9);
            p1=p1->next;
        }
        if(i%3==0)
        {
            p2->next=new ListNode(9);
            p2=p2->next;
        }
    }


    cout<<"L1:" << PrintList(l1)<<endl;
    cout<<"L2:"<< PrintList(l2)<<endl;
    Solution *s=new Solution();
   cout<<"LR:"<<PrintList(s->addTwoNumbers(l1,l2));

   return 0;
}