/* broadcast */
#include <mpi.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int x=0;
    if (rank == 0) x=10;
    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("rank %d: x=%d\n",rank,x);

    MPI_Finalize();
    return 0;
}

