#include<vector>
#include<queue>
#include<stdio.h>

struct Vector2
{
    int x;
    int y;

    Vector2()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2(int y, int x)
    {
        this->x = x;
        this->y = y;
    }

    Vector2 operator+(Vector2 v)
    {
        return Vector2(this->y + v.y, this->x + v.x);
    }

    bool operator==(Vector2 v)
    {
        return (this->x == v.x && this->y == v.y);
    }
};

enum class DIR
{
    START = 0,
    UP = START,
    DOWN,
    LEFT,
    RIGHT,
    END
};

int solution(std::vector<std::vector<int>> maps)
{
    int answer = -1;

    Vector2 dirArr[(int)DIR::END] = { Vector2(1,0), Vector2(-1,0), Vector2(0,-1), Vector2(0,1) };   //상하좌우 순서대로 기존의 위치에 더해질 Vector2를 가지는 Array

    int maxRow = maps.size();
    int maxCol = maps[0].size();
        
    Vector2 goal(maxRow -1, maxCol - 1); //Constructor Vector(y, x)

    Vector2 curr;
    std::queue<Vector2> queue;
    queue.push(curr);   //Default 0,0

    //maxRow행 maxCol열의 2차원 vector를 0으로 초기화하여 지나온 거리를 기록할 vector
    std::vector<std::vector<int>> distance(maxRow, std::vector<int>(maxCol, 0));
    distance[0][0] = 1;

    /*
    * 게임맵 최단거리를 계산하기 위한 BFS
    * 
    * 1. root(시작점) push
    * 
    * 2. queue가 빌때까지 반복
    * BFS queue에서 Pop
    * 가장 가까운 노드를 방문 후에 Push
    * 조건에 만족하는 인덱스에 거리 작성
    * 도착지점이라면 return
    * 
    */
    while (!queue.empty())
    {
        curr = queue.front();
        queue.pop();

        for (int i = (int)DIR::START; i < (int)DIR::END; i++)
        {
            Vector2 newVec = curr + dirArr[i];

            if (newVec.x < 0 || newVec.x > goal.x || newVec.y < 0 || newVec.y > goal.y) continue;       //Index Out of Range Execption

            if (maps[newVec.y][newVec.x] == 1 && distance[newVec.y][newVec.x] == 0)
            {
                distance[newVec.y][newVec.x] = distance[curr.y][curr.x] + 1;    //지나온 거리 + 1
                if (newVec == goal) return distance[newVec.y][newVec.x];        //목표에 도달했을 때 return

                queue.push(newVec);
            }            
        }
    }   

    return answer;

}


int main()
{
    std::vector<std::vector<int>> testCase =
          { { 1, 0, 1, 1, 1 },
            { 1, 0, 1, 0, 1 },
            { 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1 },
            { 0, 0, 0, 0, 1 } };

    printf("%d", solution(testCase));
}
