//
//  main.cpp
//  NO432
//
//  Created by wanyakun on 2021/1/4.
//
/**
 432. 全 O(1) 的数据结构
 请你实现一个数据结构支持以下操作：

 Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
 Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否则使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。
 GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串"" 。
 GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
  

 挑战：

 你能够以 O(1) 的时间复杂度实现所有操作吗？


 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <iterator>

using namespace std;

class AllOne {
    struct Node {
        int val;    // 存储val
        unordered_set<string> container; // 存储keys
        Node(int _val) :val(_val) {};
    };
    unordered_map<string, list<Node>::iterator> map;
    list<Node> List;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(map.count(key)) {
            auto oldNode = map[key];
            auto newNode = next(oldNode, 1);
            // 如果是在尾部或者next 比old的val+1大，则需要在node 和 next之前添加一个新的节点
            if(newNode == List.end() || newNode->val > oldNode->val+1) {
                newNode = List.insert(newNode, Node(oldNode->val + 1));
            }
            newNode->container.insert(key);
            oldNode->container.erase(key);
            // 判断List节点是否为空，是则要删除
            if(oldNode->container.empty()) {
                List.erase(oldNode);
            }
            map[key] = newNode;
        } else {
            // 添加到链表表头
            auto newNode = List.begin();
            if(List.empty() || List.begin()->val > 1) {
                newNode = List.insert(List.begin(), Node(1));
            }
            newNode->container.insert(key);
            // 添加到map
            map[key] = newNode;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(map.count(key)) {
            auto oldNode = map[key];
            if(oldNode->val == 1) {
                // 如果节点的值为1，直接从map中移除
                map.erase(key);
            } else {
                // 否则，如果当前节点为开头，或者pre节点的值小于当前节点-1，则在当前节点前插入节点
                auto newNode = next(oldNode, -1);
                if(oldNode == List.begin() || newNode->val < oldNode->val -1) {
                    newNode = List.insert(oldNode, Node(oldNode->val -1));
                }
                newNode->container.insert(key);
                map[key] = newNode;
            }
            oldNode->container.erase(key);
            if(oldNode->container.empty()) {
                List.erase(oldNode);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(List.empty()) return "";
        return *List.rbegin()->container.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(List.empty()) return "";
        return *List.begin()->container.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
