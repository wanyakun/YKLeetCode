//
//  NO349.c
//  NO349
//
//  Created by wanyakun on 2020/11/2.
//

#include "NO349.h"
#include <stdlib.h>
#include "uthash.h"

int comp(const void* a, const void* b) {
     return *(int *)a - *(int *)b;
 }
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), comp);
    qsort(nums2, nums2Size, sizeof(int), comp);

    int index1=0, index2=0;
    *returnSize = 0;
    int* result = malloc(sizeof(int)*(nums1Size+nums2Size));
    while(index1 < nums1Size && index2 < nums2Size) {
        int num1 = nums1[index1];
        int num2 = nums2[index2];

        if(num1 == num2) {
            if((*returnSize) == 0 ||  num1 != result[(*returnSize)-1]) {
                result[(*returnSize)++] = num1;
            }
            index1++;
            index2++;
        } else if(num1 < num2) {
            index1++;
        } else {
            index2++;
        }
    }
    return result;
}

#pragma mark - 方案二，采用hashtable
typedef struct unordered_set {
    int key;
    UT_hash_handle hh;
} unordered_set;

unordered_set* find(unordered_set** hashtable, int ikey) {
    unordered_set* tmp;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    return tmp;
}

void insert(unordered_set** hashtable, int ikey) {
    unordered_set* tmp = find(hashtable, ikey);
    if (tmp != NULL) {
        return;
    }
    tmp = malloc(sizeof(unordered_set));
    tmp->key = ikey;
    HASH_ADD_INT(*hashtable, key, tmp);
}

int* getIntersection(unordered_set** set1, unordered_set** set2, int* returnSize) {
    if (HASH_COUNT(*set1) > HASH_COUNT(*set2)) {
        return getIntersection(set2, set1, returnSize);
    }
    int* intersection = malloc(sizeof(int)*(HASH_COUNT(*set1) + HASH_COUNT(*set2)));
    unordered_set *s, *tmp;
    HASH_ITER(hh, *set1, s, tmp) {
        if (find(set2, s->key)) {
            intersection[(*returnSize)++] = s->key;
        }
    }
    return intersection;
}

int* intersection1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    unordered_set *set1 = NULL, *set2 = NULL;
    for (int i = 0; i < nums1Size; i++) {
        insert(&set1, nums1[i]);
    }
    for (int i = 0; i < nums2Size; i++) {
        insert(&set2, nums2[i]);
    }
    return getIntersection(&set1, &set2, returnSize);
}
