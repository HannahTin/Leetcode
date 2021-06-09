'''
起初时，蛇在左上角的 (0, 0) 位置，身体长度为 1 个单位。

你将会被给出一个数组形式的食物位置序列 food ，其中 food[i] = (ri, ci) 。当蛇吃到食物时，身子的长度会增加 1 个单位，得分也会 +1 。

食物不会同时出现，会按列表的顺序逐一显示在屏幕上。比方讲，第一个食物被蛇吃掉后，第二个食物才会出现。

当一个食物在屏幕上出现时，保证 不会 出现在被蛇身体占据的格子里。

如果蛇越界（与边界相撞）或者头与 移动后 的身体相撞（即，身长为 4 的蛇无法与自己相撞），游戏结束。

实现 SnakeGame 类：

SnakeGame(int width, int height, int[][] food) 初始化对象，屏幕大小为 height x width ，食物位置序列为 food
int move(String direction) 返回蛇在方向 direction 上移动后的得分。如果游戏结束，返回 -1 。
'''
class SnakeGame:

    def __init__(self, width: int, height: int, food: list):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        """
        self.height = height    #行数
        self.width = width      #列数
        self.food = food
        self.snake = [ [0,0] ]    #起点，初始化
        self.score = 0
        

    def move(self, direction: str) -> int:
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        """
        nxt_head = self.snake[0][:]   
        # tail = self.snake.pop(-1)   #此时先按照蛇往前走了一步，还没吃东西
        tail = self.snake.pop(-1)
        if direction == "U":
            nxt_head[0] -= 1
        elif direction == "D":
            nxt_head[0] += 1
        elif direction == "L":
            nxt_head[1] -= 1
        else:
            nxt_head[1] += 1

        if nxt_head in self.snake:  #头的下一步咬到自己身子了，咬死了
            return -1
        if not (0 <= nxt_head[0] < self.height and 0 <= nxt_head[1] < self.width):
            return -1       #超界了
        
        self.snake = [nxt_head] + self.snake    #新蛇头，头插
        
        if self.food and nxt_head == self.food[0]:
            self.score += 1
            self.food.pop(0)
            self.snake.append(tail) #蛇头吃到东西了，蛇尾不应该删除，再加回来

        return self.score
        


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)