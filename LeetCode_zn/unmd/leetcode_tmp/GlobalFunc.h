//
// Created by Cookie on 2018/8/13.
//

#ifndef LEETCODE_TMP_GLOBALFUNC_H
#define LEETCODE_TMP_GLOBALFUNC_H

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using std::vector;
using std::string;
using std::stringstream;


namespace general{
    template <typename T>
    bool compareSB(const T val1, const T val2 ){
    // 从小到大排序
        return val1 < val2;
    }

    template <typename T>
    bool compareBS(const T val1, const T val2 ){
        // 从大到小排序
        return val1 > val2;
    }

    template <typename T>
    vector< vector<T>> getVector2D(int nRows, int nCols, T default_val){
        vector<vector<T>> res(nRows, vector<T>(nCols, default_val));
        return res;
    }

//    template <typename T>
//    T[][] getArr2(int nRows, int nCols, T default_val){
//        T[nRows][nCols] res = {{default_val}};
//    }


    template <class T>
    int getArrayLen(T& array)  //使用模板定义一个函数getArrayLen,该函数将返回数组array的长度
    // 获取数组长度的模板
    {
        return (sizeof(array) / sizeof(array[0]));
    }

    string char2string(char c){
        // 将单个 char 转成 string
        stringstream stream;
        stream << c;
        return stream.str();

    }

    char* string2char(string str){
        // 将string 转成一个 char* 返回
        char c[str.size()];
        strcpy(c, str.c_str()); // 如果不拷贝，当str被析构，c 可能指向的是垃圾
        return c;
    }

    /// MESSAGE: reference version
    template <typename T>
    const T& max2(const T & element1, const T & element2){
        return std::max(element1, element2);
    }

    template <typename T>
    const T& max3(const T & element1, const T & element2, const T & element3){
        const T & tmp = std::max(element1, element2);
        return tmp > element3? tmp: element3;

    }

    template <typename T>
    const T& max4(const T & element1, const T & element2, const T & element3, const T & element4){
        const T & tmp = max3(element1, element2, element3);
        return tmp > element4? tmp:element4;
    }

    /// MESSAGE: non-reference version
//    template <typename T>
//    const T max2(const T  element1, const T  element2){
//        return std::max(element1, element2);
//    }
//
//    template <typename T>
//    const T max3(const T  element1, const T  element2, const T  element3){
//        const T  tmp = std::max(element1, element2);
//        return tmp > element3? tmp: element3;
//
//    }
//
//    template <typename T>
//    const T max4(const T  element1, const T  element2, const T  element3, const T  element4){
//        const T  tmp = max3(element1, element2, element3);
//        return tmp > element4? tmp:element4;
//    }

    /// MESSAGE: reference version
    template <typename T>
    const T& min2(const T & element1, const T & element2){
        return std::min(element1, element2);
    }

    template <typename T>
    const T& min3(const T & element1, const T & element2, const T & element3){
        const T & tmp = std::min(element1, element2);
        return tmp < element3? tmp: element3;

    }

    template <typename T>
    const T& min4(const T & element1, const T & element2, const T & element3, const T & element4){
        const T & tmp = min3(element1, element2, element3);
        return tmp < element4? tmp:element4;
    }

    /// MESSAGE: non-reference version
//    template <typename T>
//    const T min2(const T  element1, const T  element2){
//        return std::min(element1, element2);
//    }
//
//    template <typename T>
//    const T min3(const T  element1, const T  element2, const T  element3){
//        const T  tmp = std::min(element1, element2);
//        return tmp < element3? tmp: element3;
//
//    }
//
//    template <typename T>
//    const T min4(const T  element1, const T  element2, const T  element3, const T  element4){
//        const T  tmp = max3(element1, element2, element3);
//        return tmp < element4? tmp:element4;
//    }
    template <class T>
    void reverseSortedArray(vector<T>& num, int index = 0){
        // 翻转有序数组
        int l = index;
        int r = (int)num.size()-1;
        while(l<r)              // 左右两边对着交换次序
        {
            T temp = num[l];
            num[l] = num[r];
            num[r] = temp;
            l++;
            r--;
        }
    }

}

#endif //LEETCODE_TMP_GLOBALFUNC_H
