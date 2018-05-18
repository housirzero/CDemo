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

template <class T>
class Array
{
private:
    int _size;
    T * _array;
    static const int DEFAULT_SIZE = 10;
public:
    // explicit 防止隐式转换（a == b[i]）情况的出现
    explicit Array(int size = DEFAULT_SIZE)
    {
        assert(size > 0);
        _size = size;
        _array = new T[_size];
        if(NULL == _array)
        {
            // throw exception
        }
    }
    
    Array(const Array& obj);
    
    Array(T * array, int size);
    
    ~Array()
    {
        // 这里不必判断_array是否为空，因为delete NULL值也是合法的，底层会判断
        delete [] _array;
        _array = NULL;
    }
    
    // const 在后面，修饰整个函数，不允许此函数对成员变量进行修改
    // 在类内定义的成员函数会被自动当做内联(inline)函数
    int size() const {return _size;};
    T max() const;
    T min() const;
    T mean() const;
    T mid() const;
    
    void sort();
    void reverse();
    
    /**
     Description
            对象赋值
     @param obj
            参数类型为引用，避免对象拷贝，提升效率
            参数为const，避免对对象进行修改
     @return 
            返回类型为对象本身，方便连续赋值：a=b=c
            返回类型为引用，避免对象拷贝，提升效率
     */
    Array& operator =(const Array& obj);
    Array& operator ==(const Array& obj);
    Array& operator !=(const Array& obj);
    Array& operator +(const Array& obj);
    Array& operator -(const Array& obj);
    
    Array& operator +(int value);
    Array& operator -(int value);
    Array& operator *(int value);
    Array& operator /(int value);
    
    T& operator [](int index)
    {
        assert(index >= 0 && index < _size);
        return _array[index];
    }
    
    int find_first_of(T target, int start_pos = 0) const;
};

#endif /* Array_hpp */
