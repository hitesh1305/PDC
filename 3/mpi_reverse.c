
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    char str[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2)
    {
        if (rank == 0)
            printf("Run with 2 processes\n");
    }
    else if (rank == 0)
    {
        strcpy(str, "hello");

        MPI_Send(str, strlen(str) + 1, MPI_CHAR,
                 1, 0, MPI_COMM_WORLD);

        MPI_Recv(str, 100, MPI_CHAR,
                 1, 1, MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);

        printf("Reversed string: %s\n", str);
    }
    else if (rank == 1)
    {
        MPI_Recv(str, 100, MPI_CHAR,
                 0, 0, MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);

        int n = strlen(str);

        for (int i = 0; i < n / 2; i++)
        {
            char temp = str[i];
            str[i] = str[n - 1 - i];
            str[n - 1 - i] = temp;
        }

        MPI_Send(str, strlen(str) + 1, MPI_CHAR,
                 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
