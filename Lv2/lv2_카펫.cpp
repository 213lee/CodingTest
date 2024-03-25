/*
Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.

carpet.png

Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.

Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
���ѻ���

    ���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
    ����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
    ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.

����� ��
brown 	yellow 	return
10 	    2   	[4, 3]
8 	    1 	    [3, 3]
24 	    24 	    [8, 6]
*/


#include<iostream>
#include<vector>

/*
    1. brownŸ�ϰ� yellow Ÿ���� ������ ���� ��ü Ÿ�� ����(x) * ����(y)
        == (x * y) == (total = brown + yellow)  

    2. �׵θ� 1�ٸ� �����̹Ƿ� ������ x, y �ֿ��� yellow�� ������ (x - 2) * (y - 2) 
        == (x - 2) * (y - 2) = yellow
    
    yellow�� �����ϱ� ���ؼ� ������ x, y�� 3�̻��� �ڿ���
*/
std::vector<int> solution(int brown, int yellow)
{
    int total = brown + yellow;
    int half = total * 0.5f;
 
    for (int y = 3; y <= half; y++)
    {
        if (total % y == 0)
        {
            int x = total / y;
            if (yellow == (x - 2) * (y - 2))
                return { x, y };
        }
    }
}

int main()
{

}

/*
* ù��° ���
* 
    #include <string>
    #include <vector>

    using namespace std;

    vector<int> solution(int brown, int yellow) {
        int height = 3;                                 //ī���� ���� �� �ִ� �ּ� ���� ����
        int width = brown / 2 - height + 2;             //ī���� ���� �� �ִ� �ִ� ���� ����  

        //���ΰ� ���κ��� ���.
        //������ ���̸� ��ĭ�� �ø��� ������ ���̸� ��ĭ�� ���̸鼭
        //brown ���ڿ� yellow ������ ���� ���� ������ ũ���� ī�� ũ��� ��ġ�ϴ��� Ȯ��
        while (width >= height)
        {
            if (brown + yellow == height * width) break;

            width--; height++;
        }

        return { width, height };
    }

    //vector<int> solution(int brown, int yellow) {
    //    int yellowLine = 1;
    //
    //    int width, height;
    //    do
    //    {
    //        width = (brown - yellowLine * 2) / 2;
    //        height = yellowLine + 2;
    //        if (brown + yellow == width * height) break;
    //
    //        yellowLine++;
    //    } while (width > height);
    //
    //    return { width, height };
    //}
*/