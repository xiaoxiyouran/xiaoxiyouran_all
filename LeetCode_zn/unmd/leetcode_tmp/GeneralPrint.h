//
// Created by Cookie on 2018/8/13.
//

#ifndef LEETCODE_TMP_GENERAL_PRINT_H
#define LEETCODE_TMP_GENERAL_PRINT_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using std::vector;
using std::unordered_map;
using std::multimap;

namespace general{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    void print_List(ListNode* root);


    template <typename T>
    void print_Vec1D(vector<T> vec){
        for( auto it=vec.begin(); it != vec.end(); it++ ){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    void print_Vec2D(vector<vector<T>>& vec){
        for( int i = 0; i < vec.size(); i++ ){
            print_Vec1D(vec[i]);
        }
//        std::cout << std::endl;
    }

    template <typename T, typename U>
    void print_Hashmap(const unordered_map<T, U>& hash){
        typedef typename unordered_map<T, U>::const_iterator iterator;
        for( iterator it = hash.begin(); it != hash.end(); it++ ){
            std::cout << it-> first << ":" << it->second << '\t';
        }
        std::cout << std::endl;
    };

//    template <typename T, typename U>
//    void print_multimap(const multimap<T, U>& multimap){
//        typedef typename multimap<T, U>::const_iterator iterator;
//        for( iterator it = multimap.begin(); it != multimap.end(); it++ ){
//            std::cout << it-> first << ":" << it->second << '\t';
//        }
//        std::cout << std::endl;
//    };


}

#endif //LEETCODE_TMP_GENERAL_PRINT_H
