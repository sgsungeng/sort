//
//  unit.h
//  sort
//
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#ifndef unit_h
#define unit_h
#include <iostream>
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
#endif /* unit_h */
