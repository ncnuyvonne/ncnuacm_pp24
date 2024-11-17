/* scatter.c */
#include <mpi.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int a[4];
    if (rank == 0)
    {
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
    }
    int x=0;
    MPI_Scatter(a, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("rank %d: x=%d\n",rank,x);

    MPI_Finalize();
    return 0;
}

