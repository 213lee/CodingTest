#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> pronounceable = { "aya", "ye", "woo", "ma" };

int solution(std::vector<std::string> babbling) {
    int answer = 0;

    for (std::string str : babbling)
    {
        int i = 0;
        std::string prev = "";
        while (!str.empty() &&  i != pronounceable.size())
        {
            for (i = 0; i < pronounceable.size(); i++)
            {
                if (pronounceable[i] == str.substr(0, pronounceable[i].size()) && pronounceable[i] != prev)
                {
                    str.erase(str.begin(), str.begin() + pronounceable[i].size());
                    prev = pronounceable[i];
                    if (str.empty()) answer++;
                    break;
                }       
            }
        }
    }

    return answer;
}

int main()
{
    std::vector<std::string> babblings[2] = { { "aya", "yee", "u", "maa" } ,{ "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" } };
    std::cout << solution(babblings[1]) << std::endl;
}