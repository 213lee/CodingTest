#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool solution(std::vector<std::string> phone_book) {
    
    //string Vector�� algorithm�� sort ���Ŀ��� ���������� ���ĵȴ�.
    std::sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        //substr���� ��ü������ �ε��� ����ó���� �Ǿ�����.
        //���������� �������� �� ������(i + 1) �ܾ ���ξ��ΰ� Ȯ���Ͽ� ���⵵�� �����.
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
    }

    return true;
}

int main()
{
    solution({ "12","123","1235","567","88" });
}