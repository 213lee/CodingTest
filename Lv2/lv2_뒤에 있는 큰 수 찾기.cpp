#include <string>
#include <vector>
#include <stack>

////�ð� �ʰ�
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
    std::vector<int> answer(size, -1);      //numbers�� ���� ũ���� Vector�� -1�� �ʱ�ȭ
    std::stack<int> numStack;               //numbers�� �ε��� ������ ��ȸ�ϸ鼭 �񱳸� ���� ����ϴ� stack

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