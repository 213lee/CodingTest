#include <string>
#include <vector>
#include <stack>

////시간 초과
////std::vector<int> solution(std::vector<int> numbers)
////{
////    std::vector<int> answer;
////
////    for (int i = 0; i < numbers.size(); i++)
////    {
////        int j = i;
////        while (++j < numbers.size())
////        {
////            if (numbers[i] < numbers[j])
////            {
////                answer.push_back(numbers[j]);
////                break;
////            }
////
////        }
////        if (j == numbers.size()) answer.push_back(-1);
////    }
////
////    for (int a : answer)
////    {
////        printf("%d ", a);
////
////    }
////
////    printf("\n");
////
////    return answer;
////}
//
std::vector<int> solution(std::vector<int> numbers)
{
    int size = numbers.size();
    std::vector<int> answer(size, -1);      //numbers와 같은 크기의 Vector를 -1로 초기화
    std::stack<int> numStack;               //numbers를 인덱스 순서로 순회하면서 비교를 위해 사용하는 stack

    for (int i = 0; i < size; i++)
    {
        while (!numStack.empty() && numbers[numStack.top()] < numbers[i])
        {
            answer[numStack.top()] = numbers[i];
            numStack.pop();
        }
        numStack.push(i);
    }

    return answer;
}


int main()
{   
    //numbers               answer
    //[2, 3, 3, 5] 	        [3, 5, 5, -1]
    //[9, 1, 5, 3, 6, 2] 	[-1, 5, 6, 6, -1, -1]

    std::vector<int> numbers = { 2,3,3,5 };
    solution(numbers);

}