//
// Created by Administrator on 2021/2/15.
//
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

class LC71 {
public:
    string simplifyPath(string path) {
        string result = "";
        string conetext = "";
        int start, end;
        int pathsize = path.size();
        for (int i = 0; i < pathsize;) {
            if (path[i] == '/' && i == pathsize - 1) {
                break;
            } else {
                result = result + "/";
            }
            conetext = "";
            end = start = ++i;
            while (i < pathsize && path[i] != '/') {
                i++;
                end++;
            }
            conetext = path.substr(start, end - start);


            if (conetext == "."||conetext == "") {
                result = result.substr(0, result.size() - 1);
            }
            else if (conetext == "..") {
                int indexG = result.size() - 2;
                if(indexG<0)
                    indexG=0;
                for (;result[indexG] != '/';indexG--);
                result = result.substr(0, indexG);

//                cout<<"substr(0,indexG): "<<result<<endl;
            }  else {
                result = result + conetext;
            }

        }

        if(result=="")
            result="/";
        return result;
    }
//    提供一个不用栈的实现方法
//
//            核心思想倒序输入，从path末尾开始读起，先将/和/之间的内容读入context，接着对context进行判断，
//            当是.或空时跳过不做任何事情，
//            当是..时表面后面讲出现的正常目录结果将被跳过，因此这是用一个变量记录一共要在未来跳过几次正常的目录，
//            每当遇到正常目录名先判断需不需要跳过，只有不需要跳过的目录才输出到结果字符串。
//    注意：结果字符串也要按倒序的方法进行合并操作
//
//            作者：GarenL
//            链接：https://leetcode-cn.com/problems/simplify-path/solution/yong-dao-xu-shu-ru-de-fang-fa-zhi-jie-de-9fs1/
//            来源：力扣（LeetCode）
//    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string SUPER_simplifyPath(string path) {//倒序插入
        string result = "";
        string context = "";
        int num;
        int pathsize = path.size();
        int stemtToJump=0;
        for (int i = pathsize-1; i >-1;i--) {
            context = "";
            num=0;
            while (i >-1 && path[i] != '/') {
                i--;
                num++;
            }
            context=path.substr(i+1, num);
            if (context == "." || context == "") {
                continue;
            }
            else if (context == "..") {
                stemtToJump++;
            }  else {
                if(stemtToJump==0)
                    result = "/" + context + result;
                else
                    stemtToJump--;
            }
        }

        if(result=="")
            result="/";
        return result;
    }
//不能用
    string ReInforce_simplifyPath(string path) {
        string result = "";
        string context = "";
        int num;
        int pathsize = path.size();
        int stemtToJump=0;
            context = "";

            istringstream stream(path);
            while(getline(stream,context,'/')) {
            if (context == "." || context == "") {
                continue;
            }
            else if (context == "..") {
                stemtToJump++;
            }  else {
                if(stemtToJump==0)
                    result = "/" + context + result;
                else
                    stemtToJump--;
            }

        }

        if(result=="")
            result="/";
        return result;
    }

public:
    static void Order() {
        cout << "ordering LC71" << endl;
        LC71 *n = new LC71();
        string s[] = {
                "/",
                "/home/../foo/",
                "/a/../../b/../c//.//",
                "/../../..",
                "/a/..",
                "/home/foo/",
                "/home//foo/", "/../",
                "/home/../foo/"};

        for (int i = 0; i < 4; i++) {
            cout << s[i] << ":" << endl;
            cout << n->SUPER_simplifyPath(s[i]) << endl;
        }
    };
};