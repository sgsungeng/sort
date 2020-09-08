//
//  InsertSort.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef InsertSort_h
#define InsertSort_h
#include "unit.h"
/// 插入排序，主要思想是遍历到的位置均立即去确定其位置。
/// 时间复杂度 平均 O(n^2) 最差 O(n^2)
/// 额外空间 O(1)
/// 稳定
template <class Iterator = std::vector<int>::iterator>
class InsertSort: public SortFunc<Iterator>{
public:
    void operator ()(Iterator begin, Iterator end) override {
        
        Iterator tmp = begin + 1;
        while(tmp < end){
            if(*tmp < *(tmp - 1)){
                auto tmpE = *tmp;
                auto tmp1 = tmp - 1;
                while(tmp1 >= begin && *tmp1 > tmpE){
                    *(tmp1 + 1) = *tmp1;
                    --tmp1;
                }
                *(tmp1 + 1) = tmpE;
            }
            ++tmp;
        }
    }
};


#endif /* InsertSort_h */
