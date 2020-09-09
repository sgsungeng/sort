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
/// 时间复杂度 平均 O(nlogn)
/// 额外空间 O(n)
/// 不稳定
template <class Iterator = std::vector<int>::iterator>
class HeapSort: public SortFunc<Iterator>{
    std::vector<int> heap;
    /// 定义索引计算方式
    #define parent(i) ((i-1)/2)
    #define left(i) (2*i+1)
    #define right(i) (2*i + 2)
    void bulidHeap(Iterator begin, Iterator end){
        int size = int(end - begin);
        heap.reserve(size);
        while(begin < end){
            heap.push_back(*begin);
            int i = int(heap.size() - 1);
            int parent = parent(i);
            while(heap[i] > heap[parent]){
                heap[i] ^= heap[parent];
                heap[parent] ^= heap[i];
                heap[i] ^= heap[parent];
                i = parent;
                parent = parent(i);
            }
            ++begin;
        }
    }
    int popMax(){
        assert(!heap.empty());
        int re = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if(heap.empty())return re;
        int i = 0;
        int left = left(i);
        int right;
        while (left < heap.size()) {
            int maxI = heap[left] > heap[i] ? left : i;
            right = right(i);
            if(right < heap.size() &&heap[left] < heap[right] && heap[i] < heap[right]){
                maxI = right;
            }
            if(maxI == i) break;
            heap[maxI] ^= heap[i];
            heap[i] ^= heap[maxI];
            heap[maxI] ^= heap[i];
            i = maxI;
            left = left(i);
        }
        
        
        return re;
    }
public:
    void operator ()(Iterator begin, Iterator end) override {
        bulidHeap(begin, end);
        --end;
        while(end >= begin){
            *end = popMax();
            --end;
        }
    }
};


#endif /* HeapSort_h */
