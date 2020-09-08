//
//  unit.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef unit_h
#define unit_h
template<class Iterator = std::vector<int>::iterator>
class SortFunc{
public:
    virtual void operator ()(Iterator begin, Iterator end)=0;
};

template<class Iterator=std::vector<int>::iterator>
class SystemSort:public SortFunc<Iterator>
{
public:
    virtual void operator ()(Iterator begin, Iterator end) override {
        std::sort(begin, end);
    }
};

void print(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    while(begin < end){
        std::cout<<*begin<<" ";
        ++begin;
    }
}
#endif /* unit_h */
