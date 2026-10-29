
#include <stdio.h>
#include <omp.h>

int main()
{
    int a[8] = {70,10,80,20,60,30,50,40};
    int n = 8;

    omp_set_num_threads(4);

    for (int phase = 0; phase < n; phase++)
    {
        if (phase % 2 == 0)
        {
            #pragma omp parallel for
            for (int i = 0; i < n-1; i += 2)
            {
                if (a[i] > a[i+1])
                {
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
        }
        else
        {
            #pragma omp parallel for
            for (int i = 1; i < n-1; i += 2)
            {
                if (a[i] > a[i+1])
                {
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
        }
    }

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
