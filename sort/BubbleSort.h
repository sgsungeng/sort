//
//  BubbleSort.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h
// 冒泡排序，作为最简单的排序，主要思想是最大值逐渐交换到确定位置
#include "unit.h"

template <class Iterator = std::vector<int>::iterator>
class BubbleSort: public SortFunc<Iterator>{
    void pri();
public:
    void operator ()(Iterator begin, Iterator end) override {
        while(begin > end){
            for(auto be = begin + 1; be < end; ++be){
                if (*be < *(be - 1)) {
                    auto tmp = *be;
                    *be = *(be - 1);
                    *(be -1) = tmp;
                }
            }
            --end;
        }
    }
};


#endif /* BubbleSort_h */
