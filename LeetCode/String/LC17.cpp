//
// Created by Administrator on 2021/2/15.
//
#include<iostream>
#include<vector>
using namespace std;

class LC17 {
public:
    string getValue(char c) {
        switch (c) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
            default:
                return "";
        }
    }

    vector<string> letterCombinations(string digits) {
        string s="";
        return RecursiveMaths(digits, 0, s);
    }

    //输入求解字符串，已完成位置，已完成的字符串
    vector<string> RecursiveMaths(string digits, int index, string ogString)
    {
        vector<string> vectors;
        string value=getValue(digits[index]);//获得要求的数字对应的一串字符串
        string resultString;


        for (int i = 0; i < value.size(); i++) {//把每个字母加入到已拼接的字符串里
            resultString = ogString + value[i];
            if (digits.size() == index + 1)//判断是是不是加入了组后一个字母，是就放到这层的向量内
            {
                vectors.push_back(resultString);
            }
            else {
                //不是就讲index加一，执行下一个字母的拼接。
                vector<string> result = RecursiveMaths(digits, index + 1, resultString);
                //将最终返回的结果接入vector，层层返回
                vectors.insert(vectors.end(), result.begin(), result.end());
            }
        }

        return vectors;
    }

public:
    static void Order() {
        cout << "ordering LC17" << endl;
        LC17 *n = new LC17();
        string s[]={"23","","2","476"};
        cout<<sizeof(s);
        for(int i=0;i<4;i++) {
            cout << s[i] << ":" << endl;
            auto a=n->letterCombinations(s[i]).end();
            for (auto it = n->letterCombinations(s[i]).begin();it != a;it++)
            {
                cout << *it<<" ";
            }
            cout<<endl;
        }
    };
};