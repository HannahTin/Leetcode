/**
690. 员工的重要性
给定一个保存员工信息的数据结构，它包含了员工 唯一的 id ，重要度 和 直系下属的 id 。

比如，员工 1 是员工 2 的领导，员工 2 是员工 3 的领导。他们相应的重要度为 15 , 10 , 5 。那么员工 1 的数据结构是 [1, 15, [2]] ，员工 2的 数据结构是 [2, 10, [3]] ，员工 3 的数据结构是 [3, 5, []] 。注意虽然员工 3 也是员工 1 的一个下属，但是由于 并不是直系 下属，因此没有体现在员工 1 的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工 id ，返回这个员工和他所有下属的重要度之和。
**/
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
// 深度优先搜索
class Solution {
public:
    unordered_map<int, Employee *> mp;

    int dfs(int id) {
        Employee *employee = mp[id];
        int total = employee->importance;
        for (int subId : employee->subordinates) {
            total += dfs(subId);
        }
        return total;
    }

    int getImportance(vector<Employee *> employees, int id) {
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(id);
    }
};


// 广度优先搜索，队列中保存的是员工id，所以需要一个哈希表来根据id找到节点。
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> map;
        for(auto& employee:employees){
            map[employee->id] = employee;
        }
        queue<int> que;
        que.push(id);
        int total =0;
        while(!que.empty()){
            int front = que.front();
            que.pop();
            Employee* node = map[front];
            total += node->importance;
            for (int subId : node->subordinates) {
                que.push(subId);
            }
        }
        return total;
        
        
    }
};