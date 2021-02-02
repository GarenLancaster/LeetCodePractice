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
        for(int i=0;i<sizeof(s)&&indexFirst!=-1;i=indexFirst)
        {
            sum=1;
            ku=k;
            indexFirst=-1;
            // if(k!=0)
            // {
                for(int step=1;ku!=-1;step++)
                {
                    if(i+step==sizeof(s))//越界
                    {
                        break;
                    }
                    if(s[i+step]!=op)
                    {
                        ku--;
                        if(ku+1==k)//第一次执行，锁定下次开始的位置
                            indexFirst=i+step;
                    }
                    sum++;
                }
                sum--;
            // }
            // else
            // {
            //     int step=1;
            //     for(;s[i+step]==op&&(i+step)<sizeof(s);step++)
            //         sum++;
            //     if((i+step)<sizeof(s))
            //         indexFirst=i+step;
            // }
            
            if(indexFirst==-1)
                sum+=k;
            if(sum>sizeof(s))//辅助前面及整个函数
                return sizeof(s);
            if(maxSum<sum)
                maxSum=sum;
            // cout<<"Tsum"<<maxSum<<endl;
        }
        return maxSum;
    }
};

int main(){
    cout<<"START PROGRAM "<<endl;
    Solution s;
    cout <<"Long:"<< s.characterReplacement("AABABBA",1)<<endl;

    getchar();
    return 0;
}