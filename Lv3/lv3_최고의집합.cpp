#include <string>
#include <vector>


std::vector<int> solution(int n, int s) {
    std::vector<int> answer;

    //�ְ��� ������ �������� �ʴ� ���
    if (n > s) return { -1 };

    int quotient = s / n;       //��
    int remainder = s % n;      //������

    //���� �ִ밡 �Ǳ� ���ؼ��� ������ ������ ���� �۾ƾ� �ϹǷ�
    //������ ���� �۵��� ��� ��������ŭ �� + 1�� ������ �� ���� ū ���� ���� �� ����
    for (int i = 0; i < n; i++)
    {
        //n - remainder�� ��(quotient)�� ��
        if (n - remainder <= i) answer.push_back(quotient + 1);
        else answer.push_back(quotient);
    }

    int avg{ quotient / 1 };

    return answer;
}

int main()
{
    solution(2, 9);
}