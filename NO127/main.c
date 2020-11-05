//
//  main.c
//  NO127
//
//  Created by wanyakun on 2020/11/5.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO127.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* beginWord = "hit";
    char* endWord = "cog";
    
    char** wordList = malloc(6*sizeof(char*));
    wordList[0] = "hot";
    wordList[1] = "dot";
    wordList[2] = "dog";
    wordList[3] = "lot";
    wordList[4] = "log";
    wordList[5] = "cog";

    int num = ladderLength(beginWord, endWord, wordList, 6);
    
    printf("%d \n", num);
    
    return 0;
}
