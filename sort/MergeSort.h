//
//  MergeSort.h
//  sort
//
//  Created by apple008 on 2020/9/9.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

#include "unit.h"
#include "SelectSort.h"
/// 归并排序，主要思想是先将子序列排好，然后将排好的子序列列归并到一起
/// 时间复杂度 平均 O(nlogn)
/// 额外空间 O(n)
/// 稳定
template <class Iterator = std::vector<int>::iterator>
class MergeSort: public SortFunc<Iterator>{
private:
    std::vector<int> ve;
    SelectSort<> sr;
    void mergeSort(Iterator begin, Iterator end){
        int size = int(end - begin);
        if(size <= 10) {
            sr(begin,end);
            return;
        }
        int middleIndex = size / 2;
        auto middle = begin + middleIndex;
        this->mergeSort(begin,middle+1);
        this->mergeSort(middle + 1, end);
        int i = 0;
        while (i < size) {
            ve[i] = *(begin + i);
            ++i;
        }
        i = 0;
        int j = middleIndex + 1;
        middle = begin;
        while(i <= middleIndex && j < size){
            if(ve[i] <= ve[j]){
                *(middle++) = ve[i++];
            }else{
                *(middle++) = ve[j++];
            }
            
        }
        while(i <= middleIndex){
            *(middle++) = ve[i++];
        }
        while(j < size){
            *(middle++) = ve[j++];
        }
    }
public:
    
    void operator ()(Iterator begin, Iterator end) override {
        
        ve.resize(end-begin);
        mergeSort(begin, end);
    }
};

#endif /* MergeSort_h */
