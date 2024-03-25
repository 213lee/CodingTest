#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int GetRank(int n)
{
    return n < 2 ? 6 : 7 - n;
}

std::vector<int> solution(std::vector<int> lottos, std::vector<int> win_nums) {
    std::vector<int> answer;
    int hit = 0;
    int zero = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zero++;
            continue;
        }

        std::vector<int>::iterator iter = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if (iter != win_nums.end())  hit++;
    }
    answer = { GetRank(hit + zero), GetRank(hit) };

    return answer;
}

int main()
{
    //1,2,3,4,5,6
    //7,8,9,10,11,12
    std::vector<int> lottos = {1,2,3,4,5,6};
    std::vector<int> win_nums = {7,8,9,10,11,12};
    std::vector<int> answer = {};


    answer = solution(lottos, win_nums);

    for (int a : answer) std::cout << a << " ";
    std::cout << std::endl;
}