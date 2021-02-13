//
// Created by Administrator on 2021/2/9.
//
#include<iostream>
#include <map>

using namespace std;
class LC13 {
public:
    int romanToInt(string s) {
//        map<char,int> romeMap;
//        romeMap['I']=1;
//        romeMap['V']=5;
//        romeMap['X']=10;
//        romeMap['L']=50;
//        romeMap['C']=100;
//        romeMap['D']=500;
//        romeMap['M']=1000;
        int nNum,pNum=0;

        int sum=0;
        for(int i=s.length();i>=0;i--)
        {
//            nNum=romeMap[s[i]];
            nNum=getValue(s[i]);
            if(nNum<pNum) {
                sum -= nNum;
            }
            else{
                pNum=nNum;
                sum+=nNum;
            }
        }
        return sum;
    }

    int getValue(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10                ;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
public:
    static void Order() {
        cout << "ordering LC13" << endl;
         LC13 *n = new LC13();
         string s[]={"IVIII","IX","IXIV","LVIII"};
         cout<<sizeof(s);
         for(int i=0;i<4;i++) {
             cout << s[i] << ":" << n->romanToInt(s[i]) << endl;
         }
    };
};

