/**
队列的最大值

题目描述：
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1
**/
class MaxQueue {
private:
    queue<int> data;
    deque<int> assist_que;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(!data.empty() and !assist_que.empty())
            return assist_que.front();
        else 
            return -1;

    }
    
    void push_back(int value) {
        data.push(value);
        while(!assist_que.empty() and assist_que.back()<=value){
			assist_que.pop_back();
		}
		assist_que.push_back(value);

    }
    
    int pop_front() {
        if(!data.empty()){
            int top = data.front();
            data.pop();
            if(top== assist_que.front()) assist_que.pop_front();
            return top;
		}
        else return -1;
    }
};