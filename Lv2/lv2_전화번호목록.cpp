#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool solution(std::vector<std::string> phone_book) {
    
    //string Vector는 algorithm의 sort 정렬에서 사전순으로 정렬된다.
    std::sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        //substr에서 자체적으로 인덱스 예외처리가 되어있음.
        //사전순으로 정렬했을 때 인접한(i + 1) 단어만 접두어인가 확인하여 복잡도를 낮춘다.
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
    }

    return true;
}

int main()
{
    solution({ "12","123","1235","567","88" });
}