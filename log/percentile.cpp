//percentile

#include <stdint.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>

int percs[] = {90, 95, 99};

static int cmp(const int *a, const int *b)
{
    if (*a < *b)
    {
        return -1;
    }

    if (*a > *b)
    {
        return 1;
    }

    return 0;
}

int main()
{
    //read file

    int count = 20;
    int *all_times = new int[count];
    all_times[0] = 1000;
    all_times[1] = 1300;
    all_times[2] = 1230;
    all_times[3] = 1210;
    all_times[4] = 1560;
    all_times[5] = 1410;
    all_times[6] = 1300;
    all_times[7] = 5000;
    all_times[8] = 1330;
    all_times[9] = 1700;
    all_times[10] = 1200;
    all_times[11] = 1300;
    all_times[12] = 1230;
    all_times[13] = 1210;
    all_times[14] = 1560;
    all_times[15] = 1410;
    all_times[16] = 1300;
    all_times[17] = 1500;
    all_times[18] = 12140;
    all_times[19] = 1700;

    qsort(all_times, count, sizeof(int), (int (*)(const void *, const void *))cmp);

    if (count <= 0)
    {
        delete []all_times;
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

    delete []all_times;
    return 0;
}
