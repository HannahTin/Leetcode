using namespace std;
#include <vector>
#include <deque>
#include <string>

class SnakeGame 
{
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int width, height;
    vector<vector<int>> food;
    deque<pair<int,int>> snake;
    int score;

    SnakeGame(int width, int height, vector<vector<int>>& food) 
    {
        this->width = width;
        this->height = height;
        this->food = food;
        this->snake.push_back(pair<int,int>{0, 0});    //起点
        this->score = 0;                  //初始分数为0
    }
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) 
    {
        pair<int,int> nxt_head = snake.front(),    tail = snake.back();
        snake.pop_back();       //先当作蛇头没吃到东西的情况
        if (direction == "R")
            nxt_head.second ++;
        else if (direction == "L")
            nxt_head.second --;
        else if (direction == "U")
            nxt_head.first --;
        else 
            nxt_head.first ++;
        
        for (auto it: snake)
        {
            if (nxt_head == it)
                return -1;  //下一步的位置，在蛇身上，就把自己咬死了
        }
        if ( !(0<= nxt_head.first && nxt_head.first < height && 0<= nxt_head.second && nxt_head.second < width) )
            return -1;      //超界了

        snake.push_front(nxt_head);  //插入新头
        if (!food.empty() && nxt_head.first==food[0][0] && nxt_head.second==food[0][1])
        {
            score ++;
            food.erase(food.begin());
            snake.push_back(tail);      //如果现在蛇头吃到东西了，刚开始的时候，尾巴是不应该删除的。
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */