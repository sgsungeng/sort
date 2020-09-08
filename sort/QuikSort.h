//
//  QuikSort.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef QuikSort_h
#define QuikSort_h

/// 快速排序，主要思想确定一个值，将小于该值的放左边，大于等于该值的放右边，递归的调用
/// 时间复杂度 平均 O(nlogn) 最差 O(n^2)
/// 额外空间 O(nlogn)
/// 不稳定
template <class Iterator = std::vector<int>::iterator>
class QuikSort: public SortFunc<Iterator>{
private:
    void quikSort(Iterator begin, Iterator end){
        if (begin >= end) {
            return;
        }
        Iterator i = begin;
        Iterator j = end;
        auto key = *i;
        while(i < j){
            while(*j >= key && i < j) --j;
            if(i < j){
                *i = *j;
                *j = key;
            }
            while (*i <= key  && i < j)++i;
            if(i<j){
                *j = *i;
                *i = key;
            }
        }
        quikSort(begin, i);
        quikSort(j+1,end);
        
    }
public:
    void operator ()(Iterator begin, Iterator end) override {
        quikSort(begin,end-1);
    }
};


#endif /* QuikSort_h */
