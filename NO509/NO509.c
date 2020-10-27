//
//  NO509.c
//  NO509
//
//  Created by wanyakun on 2020/10/27.
//

#include "NO509.h"
#include <stdlib.h>

#pragma mark - 方案一,暴力递归
int fib1(int N){
    if(N == 0) return 0;
    if(N == 1) return 1;
    return fib1(N-1) + fib1(N-2);
}
#pragma mark - 方案二，带备忘录递归
int helper(int* memo, int N) {
    if(N == 0) return 0;
    if(N == 1) return 1;
    if(memo[N] != 0) return memo[N];
    memo[N] = helper(memo, N-1) + helper(memo, N-2);
    return memo[N];
}
int fib2(int N){
    int* memo = calloc(N+1, sizeof(int));
    return helper(memo, N);
}
#pragma mark - 方案三， 带dp数组迭代
int fib3(int N) {
    // base case
    if(N == 0) return 0;
    if(N == 1) return 1;
    //
    int* dp = calloc(N+1, sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
     dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}
#pragma mark - 方案四 dp数组优化
int fib4(int N) {
    // base case
    if(N == 0) return 0;
    if(N == 1) return 1;

    int pre = 0;
    int current = 1;
    for (int i = 2; i <= N; i++) {
        int next = pre + current;
        pre = current;
        current = next;
    }
    return current;
}
