#include<iostream>
#include<string>
#include<vector>
#include<map>

std::vector<int> solution(std::string s) {
    std::map<char, int> MapCache;
    std::vector<int> answer;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (MapCache.find(s[i]) != MapCache.end())
        {
            answer.push_back(i - MapCache[s[i]]);
        }
        else answer.push_back(-1);

        MapCache[s[i]] = i;
    }

    return answer;
}

int main()
{
    for (int n : solution("foobar"))
        std::cout << n << " ";
        std::cout << std::endl;
}