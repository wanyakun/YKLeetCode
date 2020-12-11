//
//  Tencent0002.h
//  Tencent0002
//
//  Created by wanyakun on 2020/12/11.
//
/**
 给定一个8*8的棋盘，上面有若干个车（Rook），写一个函数检查这些车有没有互相攻击的情况，如果横列或者竖列同样也有1，即为互相攻击，输入一个参数是由0和1租车的二维数组
 */
#ifndef Tencent0002_h
#define Tencent0002_h

#include <stdio.h>
#include <stdbool.h>

bool checkConflict(int** arr, int arrSize, int* arrColSize);

#endif /* Tencent0002_h */
