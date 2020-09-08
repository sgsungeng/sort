//
//  ExchangeSort.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef ExchangeSort_h
#define ExchangeSort_h

/// 交换排序，在每次迭代中找到最值直接交换到确定位置，这样打乱了相对顺序，因此是不稳定的
/// 时间复杂度 O(n^2)
/// 空间 O（1）
/// 不稳定
template <class Iterator = std::vector<int>::iterator>
class ExchangeSort: public SortFunc<Iterator>{
public:
    void operator ()(Iterator begin, Iterator end) override {
        while(begin < end){
            for(auto be = begin + 1; be < end; ++be){
                if (*be < *(begin)) {
                    auto tmp = *be;
                    *be = *begin;
                    *begin = tmp;
                }
            }
            ++begin;
        }
    }
};



#endif /* ExchangeSort_h */
