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
#include <assert.h>

class Array
{
private:
    int _size;
    int * array;
    static const int DEFAULT_SIZE = 10;
public:
    // explicit 防止隐式转换（a == b[i]）情况的出现
    explicit Array(int size = DEFAULT_SIZE)
    {
        assert(size > 0);
        _size = size;
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
    
    int size() const {return _size;};
    int max() const;
    int min() const;
    int mean() const;
    int mid() const;
    
    void sort();
    
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
