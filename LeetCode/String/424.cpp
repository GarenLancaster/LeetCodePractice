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
            for(int step=1;ku!=-1;step++)
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
                    ku=-1;//出循环
                sum++;
            }
            sum--;

            if(indexFirst==-1)
                sum+=k;
            if(sum>s.length())//辅助前面及整个函数
                return s.length();
            if(maxSum<sum)
                maxSum=sum;
        }
        return maxSum;
    }
};

int main(){
    cout<<"START PROGRAM "<<endl;
    Solution s;
    cout <<"Long:"<< s.characterReplacement("ABAB",2)<<endl;

    getchar();
    return 0;
}