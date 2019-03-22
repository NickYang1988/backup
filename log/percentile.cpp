//percentile

#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

int percs[] = {90, 95, 99};

int compare_greater(const int a, const int b)
{
    return a > b;
}

int compare_less(const int a, const int b)
{
    return a < b;
}

int main()
{
    //read file
    std::ifstream file("time.log", std::ios::in | std::ios::binary);
    std::string line;
    std::vector<int> all_times;
    while (getline(file, line))
    {
        all_times.push_back(atoi(line.c_str()));
    }

    //sort by ASC
    std::sort(all_times.begin(), all_times.end(), std::less<int>());
    int count = all_times.size();
    if (count <= 0)
    {
        std::cout << "not find any time" << std::endl;
        return -1;
    }

    //log
    for (size_t i = 0; i < std::extent<decltype(percs)>::value; i++)
    {
        if (percs[i] <= 0)
        {
            std::cout << "0% never" << std::endl;
        }
        else if (percs[i] >= 100)
        {
            std::cout << "100% of requests return a response in " << all_times[count - 1] << " ms" << std::endl;
        }
        else
        {
            std::cout << percs[i] << "% of requests return a response in " << all_times[int64_t((unsigned long)count * percs[i] / 100)] << " ms" << std::endl;
        }
    }

    return 0;
}
