#include <string>
#include <vector>
#include <set>
int solution(std::vector<int> elements) {
    std::set<int> sumSet;
    std::vector<int> tmpVec(elements.size());

    for (int i = 0; i < elements.size() - 1; i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            int index = (j + i) % elements.size();
            tmpVec[j] +=elements[index];

            sumSet.insert(tmpVec[j]);
        }
    }
    
    return sumSet.size() + 1;
}


int main()
{
    solution({ 7,9,1,1,4 });
}