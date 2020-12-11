//
//  Tencent0001.h
//  Tencent0001
//
//  Created by wanyakun on 2020/12/11.
//
/**
 作者：Makki
 链接：https://www.nowcoder.com/discuss/488619?type=all&order=time&pos=&page=1&channel=-1&source_id=search_all_nctrack
 来源：牛客网

 小Q在进行射击气球的游戏，如果小Q在连续T枪中打爆了所有颜色的气球，将得到一只QQ公仔作为奖励。（每种颜色的气球至少被打爆一只）。这个游戏中有m种不同颜色的气球，编号1到m。小Q一共有n发子弹，然后连续开了n枪。小Q想知道在这n枪中，打爆所有颜色的气球最少用了连续几枪？
 输入描述：
 第一行两个空格间隔的整数数n，m。n<=1000000 m<=2000
 第二行一共n个空格间隔的整数，分别表示每一枪打中的气球的颜色,0表示没打中任何颜色的气球。
 输出描述：
 一个整数表示小Q打爆所有颜色气球用的最少枪数。如果小Q无法在这n枪打爆所有颜色的气球，则输出-1
 示例
 输入：
 12 5
 2 5 3 1 3 2 4 1 0 5 4 3
 输出：
 6

 test
 12 5
 2 5 3 1 3 2 4 1 5 0 4 3
 5

 一开始理解错题了。。后来写了个O（N2）的遍历，最后面试官说就这么多吧马上要结束的时候忽然想起来了滑动窗口解，复杂度是O（N） （我不会算，最后问的面试官）
 临死前想起来的QAQ
 他说这个是最优解了，许愿一面能过把
 */
#ifndef Tencent0001_h
#define Tencent0001_h

#include <stdio.h>

int minShoot(int* array, int n, int m);

#endif /* Tencent0001_h */
