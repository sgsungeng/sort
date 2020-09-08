//
//  ShellSort.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef ShellSort_h
#define ShellSort_h
/// Shell排序，主要思想是设置跨度，根据跨度会生成子序列，先排好子序列，后面，跨度逐渐减小，最终至1 完全排好
/// 时间复杂度 平均 nlogn 最差 O(n^s) 1 < s < 2;
/// 额外空间 O(1)
/// 不稳定
template <class Iterator = std::vector<int>::iterator>
class ShellSort: public SortFunc<Iterator>{
private:
    int s;
public:
    ShellSort(int s = 5):s(s){assert(s >= 1);}
    void operator ()(Iterator begin, Iterator end) override {
        int s = this->s;
        int length = int(end - begin);
        while(s){
            for(int i = 0; i < s; ++i){
                for(int j = i; j < length; j+= s){
                    int minI = j;
                    for(int k = j + s; k < length; k += s){
                        if(*(begin + k) < *(begin+minI)){
                            minI = k;
                        }
                    }
                    auto tmp = *(begin + j);
                    *(begin + j) = *(begin + minI);
                    *(begin + minI) = tmp;
                }
            }
            s/=2;
        }
    }
};


#endif /* ShellSort_h */
