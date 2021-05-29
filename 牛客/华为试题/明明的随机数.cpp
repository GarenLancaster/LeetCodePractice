///
/**
描述
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据(用于不同的调查)，希望大家能正确处理)。


注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。

当没有新的输入时，说明输入结束。

输入描述：
注意：输入可能有多组数据(用于不同的调查)。每组数据都包括多行，第一行先输入随机整数的个数N，接下来的N行再输入相应个数的整数。具体格式请看下面的"示例"。

输出描述：
返回多行，处理后的结果

题目网址： https://www.nowcoder.com/ta/huawei
**/
////

#include<iostream>
using namespace std;

struct ListNode
{
    double value;
    ListNode *next,*pre;
};

int main(){
    int x;
    int num=-1;
    ListNode *lHead=new ListNode;
    ListNode *prn=new ListNode;
    lHead->next=prn;
    prn->pre=lHead;
    lHead->value=-1;
        
    ListNode *t;
    while(true)
    {
        if(num==-1)
        {
            if(!(cin>>num))
                break;
            cin>>prn->value;
        }
        else
        {
            for(int i=0;i<num-1;i++)
            {
                cin>>x;
                t=prn;
                if(x==t->value)
                {
                    continue;
                }
               else if(x>t->value)
               { 
                   ListNode *ln=new ListNode;
                    prn->next=ln;
                   ln->next=nullptr;
                    ln->pre=prn;
                    ln->value=x;
                    prn=ln;
                }                
                else
                {
                    while(x<t->value)
                    {
                        t=t->pre;
                    }
                    if(x==t->value)
                    {
                        continue;
                    }else{
                        ListNode *ln=new ListNode;
                        ln->next=t->next;
                        ln->pre=t;
                        ln->value=x;
                        
                        t->next=ln;
                        ln->next->pre=ln;
                    }
                }
            }
            t=lHead->next;
            if(num>0)
            {
                while(t!=nullptr)
                {
                    cout<<t->value<<endl;
                    t=t->next;
                }
            }
            num=-1;
            
            lHead->next=prn;
            prn->pre=lHead;
            prn->next=nullptr;
        }
    }
}