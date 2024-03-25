#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <stdio.h>

#define MAX 5
#define MIN -5

struct coord2D
{
    int x;
    int y;

    coord2D(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    void print()
    {
        printf("x : %d, y : %d\n", x, y);
    }

    bool operator==(const coord2D& coord)
    {
        return (x == coord.x) && (y == coord.y);
    }

    coord2D operator+(const coord2D& coord)
    {
        return coord2D(std::max(MIN, std::min(MAX, this->x + coord.x)), std::max(MIN, std::min(MAX, this->y + coord.y)));
    }
};

int solution(std::string dirs) {
    int answer = 0;

    coord2D pre;
    coord2D curr;
    std::vector<coord2D> coordVec;
    std::vector<coord2D>::iterator iter;
    std::map<char, coord2D> dirMap;
    dirMap['U'] = coord2D(0, 1);
    dirMap['D'] = coord2D(0, -1);
    dirMap['R'] = coord2D(1, 0);
    dirMap['L'] = coord2D(-1, 0);


    
    for (int i = 0; i < dirs.size(); i++)
    {
        pre = curr;
        curr = curr + dirMap[dirs[i]];
        iter = std::find(coordVec.begin(), coordVec.end(), curr);
        if (iter != coordVec.begin() && iter != coordVec.end() && coordVec[iter - coordVec.begin() - 1] == pre
            || pre == curr)
        {
            answer--;
            continue;
        }
        
        coordVec.push_back(curr);
    }


    answer += dirs.size();

    for (coord2D c : coordVec) c.print();

    printf("\n\n Answer : %d\n", answer);

    return answer;
}

int main()
{
    //std::string dirs = "ULURRDLLU";
    std::string dirs = "LULLLLLLU";
    solution(dirs);
}