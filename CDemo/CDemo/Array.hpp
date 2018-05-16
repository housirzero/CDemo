//
//  Array.hpp
//  CDemo
//
//  Created by housir on 2018/5/16.
//  Copyright © 2018年 housir. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>

class Array
{
private:
    int _size;
    int * array;
public:
    Array(int size):_size(size)
    {
        array = new int[_size];
        if(NULL == array)
        {
            // throw exception
        }
    }
    
    ~Array()
    {
        delete array;
        array = NULL;
    }
    
    int size();
    int max();
    int min();
    int mean();
    int mid();
    
    Array& operator =(const Array& obj);
    Array& operator ==(const Array& obj);
    Array& operator !=(const Array& obj);
    Array& operator +(const Array& obj);
    Array& operator -(const Array& obj);
    
    Array& operator +(int value);
    Array& operator -(int value);
    Array& operator *(int value);
    Array& operator /(int value);
    
    int& operator [](int index);
    
    int find_first_of(int target, int start_pos = 0);
};

#endif /* Array_hpp */
