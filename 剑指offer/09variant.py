# 同样，用两个队列实现栈
class CStack:

    def __init__(self):
        self.queue1 = []
        self.queue2 = []

    def appendTop(self, value: int) -> None:
        self.queue1.append(value)

#    当queue1为空时，设置queue1存储进来的元素，queue2用于将queue1元素清空到只剩一个，queue1输出的就是要删除的
#    反之亦然
#    其中Python中队列可用list实现，进队append，出队pop(0)
    def deleteTop(self) -> int:
        if len(self.queue1)==1:
           return self.queue1.pop(0)
        elif len(self.queue2)==1:
            return self.queue2.pop(0)
        elif not self.queue2 and self.queue1:
            while len(self.queue1)>1:
                self.queue2.append(self.queue1.pop(0))
            return self.queue1.pop(0)
        elif self.queue2 and not self.queue1:
            while len(self.queue2)>1:
                self.queue1.append(self.queue2.pop(0))
            return self.queue2.pop(0)
        elif not self.queue2 :
            return -1
obj = CStack()
obj.appendTop(5)
obj.appendTop(2)
param_1 = obj.deleteTop()
print(param_1)
param_2 = obj.deleteTop()
print(param_2)
param_3 = obj.deleteTop()
print(param_3)