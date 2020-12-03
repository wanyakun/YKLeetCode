//
//  NO204.c
//  NO204
//
//  Created by wanyakun on 2020/12/3.
//

#include "NO204.h"
#include <stdbool.h>
#include <string.h>

// 暴力枚举，超出时间限制
 int countPrimes(int n){
     if(n < 2) return 0;
     int res = 0;
     for(int i = 2; i < n; i++) {
         int k = 0;
         // 校验 [2, i-1]中的每个数j，判断j是否为x的因数
         for(int j = 2; j < i; j++) {
             if(i%j != 0) {
                 k++;
             }
         }
         if(k == i -2) {
             res++;
         }
     }
     return res;
 }

// 也超出时间限制
 bool isPrime(int x) {
     for(int i = 2; i*i <= x; i++) {
         if(x%i == 0) return false;
     }
     return true;
 }

 int countPrimes1(int n){
     int res = 0;
     for(int i = 2; i < n; i++) {
         res += isPrime(i);
     }
     return res;
 }

 int countPrimes2(int n) {
     if(n < 2) return 0;
     int isPrime[n];
     memset(isPrime, 0, sizeof(isPrime));
     int res = 0;
     for(int i = 2; i < n; i++) {
         // 如果没被标记，则为质数，res则+1，并对质数的整数倍进行标记
         if(!isPrime[i]) {
             res += 1;
             if((long long)i*i < n) {
                 // 从i*i开始标记（i*i之前的数已经被前面的循环标记了），标记i的整数倍为非质数
                 for(int j = i*i; j < n; j += i) {
                     isPrime[j] = 1;
                 }
             }
         }
     }
     return res;
 }

int countPrimes3(int n) {
    if(n < 2) return 0;
    // 统计质数
    int primes[n];
    int primesSize = 0;
    // 标记每一个是否为质数
    int isPrime[n];
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) {
            primes[primesSize++] = i;
        }
        // 只标记已经被统计到的质数的整数倍
        for(int j = 0; j < primesSize && i*primes[j] < n; j++) {
            isPrime[i*primes[j]] = 0;
            // 只标记到最小倍数，防止重复标记
            if(i%primes[j] == 0) {
                break;
            }
        }
    }
    return primesSize;

}
