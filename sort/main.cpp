//
//  main.cpp
//  sort
//  本项目主要是为了总结当前学过的排序算法
//  Created by apple008 on 2020/9/8.
//  Copyright © 2020 sungeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "unit.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "ExchangeSort.h"
#include "InsertSort.h"
#include "ShellSort.h"
#include "QuikSort.h"

using std::function;
using std::vector;
using std::cout;

vector<int> getRandomArray(int minE, int maxE, int size){
    vector<int> re;
    re.reserve(size);
    srand((unsigned int)time(0));
    for(int i = 0; i<size; ++i){
        re.push_back(rand()%(maxE - minE) + minE);
    }
    return re;
}

bool isComplate(function<void(vector<int>::iterator, vector<int>::iterator)> test, function<void(vector<int>::iterator, vector<int>::iterator)> right, int times = 10000, int maxSize = 10000){
    for(int i = 0; i < times; ++i){
        srand((unsigned int)time(0));
        vector<int> v1 = getRandomArray(0, rand() % maxSize, rand() % maxSize);
        vector<int> v2 = v1;
        
        test(v1.begin(), v1.end());
        right(v2.begin(), v2.end());
        for(int j = 0; j < v1.size(); ++j){
            if(v1[j] != v2[j])return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    
    auto re = isComplate(QuikSort<vector<int>::iterator>(),SystemSort<vector<int>::iterator>());
    std::cout<<re<<std::endl;
    return 0;
}
