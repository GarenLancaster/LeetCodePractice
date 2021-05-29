//
// Created by Administrator on 2021/2/8.
//

#include<iostream>
using namespace std;
class Solution {
public:
//找最长是当前的，替换k次，得到最长值，接着跳到本最长的第一个替换的位置，以这个为基准找最长
    int characterReplacement(string s, int k) {
        char op=(char)s[0];//当前操作字符
        int ku;//k的剩余使用次数
        int sum,maxSum=0,indexFirst=0;//总值，最大值，下次操作的index

        if(k<0)
            k=0;
        for(int i=0;i<s.length()&&indexFirst!=-1;i=indexFirst)
        {
            sum=1;
            ku=k;
            indexFirst=-1;
            for(int step=1,flag=1;ku!=-1&&flag==1;step++)
            {
                if(i+step<s.length())//未越界
                {
                    if(s[i+step]!=op)
                    {
                        ku--;
                        if(ku+1==k)//第一次执行，锁定下次开始的位置
                            indexFirst=i+step;
                    }
                }
                else
                    flag=0;//出循环
                sum++;
            }
            sum--;

            if(ku>=0)
                sum+=ku;
            else
                op=(char)s[indexFirst];
            if(sum>=s.length())//辅助前面及整个函数
                return s.length();
            if(maxSum<sum)
                maxSum=sum;
        }
        return maxSum;
    }
};

<<<<<<< Updated upstream:LeetCode/String/LC424.cpp
int emain(){
=======
////////////////////参考答案////////////////////////////
class SolutionAN {
public:
//找最长是当前的，替换k次，得到最长值，接着跳到本最长的第一个替换的位置，以这个为基准找最长
    int cnt[26];
    int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }

    int get_max()    {
        int ret =0;
        for(int i=0;i<26;i++)        
            ret=max(ret,cnt[i]);
        return ret;        
    }

    int characterReplacement(string s, int k) {
        int size=s.length();
        if(k>=size){
            return size;
        }
        int ret=0;
        int l=0,r=-1;

        for(;l<size;cnt[s[l]-'A']--,l++)
        {
            while(r+l<size&& ((r+1-l+1)-max(cnt[s[r+1]-'A']+1,get_max())<=k))
                cnt[s[++r]-'A']++;
            ret=max(ret,r-l+1);
        }
        return ret;
    }
};
////////////////////////////////////////////////

int main(){
>>>>>>> Stashed changes:LeetCode/String/424.cpp
    cout<<"START PROGRAM "<<endl;
    Solution s;
    cout <<"Long:"<< s.characterReplacement("AAAA",0)<<endl;

    SolutionAN san;
    cout <<"LongAN:"<< san.characterReplacement("AAAA",0)<<endl;

    getchar();
    return 0;
}