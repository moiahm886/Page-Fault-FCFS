#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int faults = 0;
    int frames = 0;
    std::vector<int>page_ref = { 1,2,3,4,2,4,5,6,2,1,2,3,7,6,3,2,1,2,3,6 };
    std::vector<int>memory;
    int replacement = 0;
    int index = 0;
    std::vector<int>::iterator page;
    std::cout << "Enter number of frames\n";
    std::cin >> frames;
    for (page = page_ref.begin(); page != page_ref.end(); page++)
    {
        std::vector<int>::iterator it = std::find(memory.begin(), memory.end(), *page);
        if (it == memory.end())
        {
            if (memory.size() < frames)
            {
                faults++;
                memory.push_back(*page);
                index++;
            }
            else
            {
                index %= frames;
                replacement = memory[index];
                replace(memory.begin(), memory.end(), replacement, *page);
                faults++;
                index++;
            }
        }
    }
    std::cout << "Total faults: " << faults << std::endl;
    return 0;
}