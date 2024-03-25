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

    Vector2 dirArr[(int)DIR::END] = { Vector2(1,0), Vector2(-1,0), Vector2(0,-1), Vector2(0,1) };   //�����¿� ������� ������ ��ġ�� ������ Vector2�� ������ Array

    int maxRow = maps.size();
    int maxCol = maps[0].size();
        
    Vector2 goal(maxRow -1, maxCol - 1); //Constructor Vector(y, x)

    Vector2 curr;
    std::queue<Vector2> queue;
    queue.push(curr);   //Default 0,0

    //maxRow�� maxCol���� 2���� vector�� 0���� �ʱ�ȭ�Ͽ� ������ �Ÿ��� ����� vector
    std::vector<std::vector<int>> distance(maxRow, std::vector<int>(maxCol, 0));
    distance[0][0] = 1;

    /*
    * ���Ӹ� �ִܰŸ��� ����ϱ� ���� BFS
    * 
    * 1. root(������) push
    * 
    * 2. queue�� �������� �ݺ�
    * BFS queue���� Pop
    * ���� ����� ��带 �湮 �Ŀ� Push
    * ���ǿ� �����ϴ� �ε����� �Ÿ� �ۼ�
    * ���������̶�� return
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
                distance[newVec.y][newVec.x] = distance[curr.y][curr.x] + 1;    //������ �Ÿ� + 1
                if (newVec == goal) return distance[newVec.y][newVec.x];        //��ǥ�� �������� �� return

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
