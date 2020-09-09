//
//  HeapSort.h
//  sort
//
//  Created by apple008 on 2020/9/9.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

#include "unit.h"

/// 堆排序，主要思想是建立大根堆或者小根堆的数据结构，根据需要建立
/// 时间复杂度 平均 O(n^2) 最差 O(n^2)
/// 额外空间 O(1)
/// 稳定
template <class Iterator = std::vector<int>::iterator>
class HeapSort: public SortFunc<Iterator>{
public:
    void operator ()(Iterator begin, Iterator end) override {
        while(begin < end){
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


#endif /* HeapSort_h */
