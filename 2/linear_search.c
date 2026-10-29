
#include <stdio.h>
#include <omp.h>

int main()
{
    int a[8] = {10,20,30,40,50,60,70,80};
    int key = 70, found = -1;

    omp_set_num_threads(4);

    #pragma omp parallel for
    for (int i = 0; i < 8; i++)
    {
        if (a[i] == key)
        {
            #pragma omp critical
            {
                found = i;
            }
        }
    }

    if (found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not found\n");

    return 0;
}
