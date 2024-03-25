#include <string>
#include <vector>

//std::vector<long long> solution(std::vector<long long> numbers) {
//    std::vector<long long> answer;
//
//    for (int i = 0; i < numbers.size(); i++)
//    {
//        if ((numbers[i] % 2) == 0)
//        {
//            answer.push_back(numbers[i] + 1);
//        }
//        else
//        {
//            long long bit = 1;
//            while (true)
//            {
//                if (!(numbers[i] & bit)) break;
//                bit *= 2;
//            }
//            bit /= 2;
//            answer.push_back(numbers[i] + bit);
//        }
//    }
//
//    return answer;
//}

std::vector<long long> solution(std::vector<long long> numbers) {
    std::vector<long long> answer;

    for (long long number : numbers)
    {
        long long bit = 1;
        while ((number & bit)) bit <<= 1;
        int ans = number + bit - (bit >> 1);
        printf("%d\n", ans);
        answer.push_back(number + bit - (bit >> 1));
    }

    return answer;
}

int main()
{
    solution({ 2, 7 });
}