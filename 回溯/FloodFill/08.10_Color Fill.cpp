/**
面试题 08.10. 颜色填充
编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。

待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的行坐标为 sr 列坐标为 sc。需要填充的新颜色为 newColor 。

「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。

请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。

 

示例：

输入：
image = [[1,1,1],[1,1,0],[1,0,1]] 
sr = 1, sc = 1, newColor = 2
输出：[[2,2,2],[2,2,0],[2,0,1]]
解释: 
初始坐标点位于图像的正中间，坐标 (sr,sc)=(1,1) 。
初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。
**/
using namespace std;
#include <vector>
class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool inArea(vector<vector<int>>& image,int x,int y){
        return (x >= 0 && x < image.size() && y >= 0 && y < image[0].size());
    }
    void fill(vector<vector<int>>& image,int x,int y, int oriColor,int newColor){
        if(!inArea(image,x,y)) return;
        if(image[x][y]!=oriColor) return;
        if(image[x][y] == -1) return;
        image[x][y] = -1;
        for(vector<int> d:dir){
            fill(image,x+d[0], y+d[1], oriColor, newColor); 
        }
        image[x][y]=newColor;
        

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oriColor = image[sr][sc];
        fill(image,sr,sc,oriColor,newColor);
        return image;
    }
};