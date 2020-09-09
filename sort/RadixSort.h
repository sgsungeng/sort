//
//  RadixSort.h
//  sort
//
//  Created by apple008 on 2020/9/9.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef RadixSort_h
#define RadixSort_h


#include "unit.h"

/// 基数排序，根据数字的位数从低位到高位排序。
/// 时间复杂度 平均 O(n*k)
/// 额外空间 O(n+k)
/// 不稳定
template <class Iterator = std::vector<int>::iterator>
class RadixSort: public SortFunc<Iterator>{
    int getLength(int num){
        int re = 1;
        while(num / 10){
            ++re;
            num /= 10;
        }
        return re;
    }
public:
    void operator ()(Iterator begin, Iterator end) override {
        if(begin == end) return;
        int k = getLength(*(std::max_element(begin, end)));
        
        int size = int(end-begin);
        std::vector<int> tmp;
        tmp.reserve(size);
        std::vector<int> count(10,0);
        int i,j,l;
        int radix = 1;
        for(i = 1; i<=k; ++i){
            for(auto &n:count){
                n = 0;
            }
            for(j = 0; j < size; ++j){
                l = (*(begin + j) / radix) % 10;
                ++count[l];
            }
            for(j = 1; j < 10; ++j){
                count[j] = count[j-1] + count[j];
            }
            for(j = size -1; j >= 0; --j){
                l = (*(begin + j) / radix) % 10;
                tmp[count[l] -1] = *(begin+j);
                --count[l];
            }
            for(j = 0; j<size; ++j){
                *(begin + j) = tmp[j];
            }
            radix *= 10;
        }
    }
};

#endif /* RadixSort_h */
