'''
用两个栈实现队列

题目描述：
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
'''
class CQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def appendTail(self, value: int) -> None:
        self.stack1.append(value)

#    设置stack1存储进来的元素，stack2用于将stack1元素反转，栈顶输出的就是要删除的
    def deleteHead(self) -> int:
        if self.stack2:
           return self.stack2.pop()
        elif not self.stack2 and self.stack1:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            return self.stack2.pop()
        elif not self.stack2 :
            return -1



# Your CQueue object will be instantiated and called as such:
obj = CQueue()
obj.appendTail(5)
obj.appendTail(2)
param_1 = obj.deleteHead()
print(param_1)
param_2 = obj.deleteHead()
print(param_2)