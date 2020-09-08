//
//  SelectSort.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef SelectSort_h
#define SelectSort_h
#include "unit.h"
/// 选择排序，在每次迭代中找到最值 直接交换到确定位置
/// 时间复杂度 O(n^2)
/// 空间 O（1）
/// 由于选择的位置可能不稳定，也可以稳定
template <class Iterator = std::vector<int>::iterator>
class SelectSort: public SortFunc<Iterator>{
public:
    void operator ()(Iterator begin, Iterator end) override {
        while(begin > end){
            Iterator maxI = begin;
            for(auto be = begin + 1; be < end; ++be){
                if (*be >= *(maxI)) {
                    maxI = be;
                }
            }
            --end;
            auto tmp = *(end);
            *(end) = *(maxI);
            *(maxI) = tmp;
        }
    }
};

#endif /* SelectSort_h */
