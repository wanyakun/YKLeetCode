//
//  NO887.c
//  NO887
//
//  Created by wanyakun on 2020/11/18.
//

#include "NO887.h"
#include <limits.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int memo[101][10001];
int dp(int K, int N) {
    // base case
    if(K == 1) return N;
    if(N == 0) return 0;
    if(memo[K][N]) return memo[K][N];
    int res = INT_MAX;
    // for(int i = 1; i < N+1; i++) {
    //     //dp(K, N-i)没碎，dp(K-1, i-1))碎了， +1 第i层扔了一次
    //     res = min(res, max(dp(K, N-i), dp(K-1, i-1))+1);
    // }
    // 二分法
    int lo = 1, hi = N;
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        int broken = dp(K-1, mid-1); // 碎
        int not_broken = dp(K, N-mid); //没碎
        if(broken > not_broken) {
            hi = mid - 1;
            res = min(res, broken+1);
        } else {
            lo = mid + 1;
            res = min(res, not_broken+1);
        }
    }
    memo[K][N] = res;
    return res;
}

int superEggDrop(int K, int N){
    return dp(K, N);
}
