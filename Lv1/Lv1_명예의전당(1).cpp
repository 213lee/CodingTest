#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


std::vector<int> solution(int k, std::vector<int> score) {
    std::vector<int> answer;
    std::vector<int> hall;

    //Priority Que Version
    //std::priority_queue<int, std::vector<int>, std::greater<int>> hallQ;

    //for (int i = 0; i < score.size(); i++)
    //{
    //    if (i < k) hallQ.push(score[i]);
    //    else if (score[i] > hallQ.top())
    //    {
    //        hallQ.pop();
    //        hallQ.push(score[i]);
    //    }
    //    answer.push_back(hallQ.top());
    //}


    for (int i = 0; i < score.size(); i++)
    {
        hall.push_back(score[i]);
        std::sort(hall.begin(), hall.end());

        if (hall.size() > k) hall.erase(hall.begin());

        answer.push_back(hall.front());
    }

    return answer;
}

int main()
{
    std::vector<int> q = solution(4, { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 });
    for (int a : q) std::cout << a << " ";
    std::cout << std::endl;
}