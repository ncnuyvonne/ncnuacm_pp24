/* barrier */
#include <mpi.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Request req1;
    int x=0;
    if (rank == 0) {
	x=10;
	MPI_Isend(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &req1);
    } else if (rank == 1) {
	MPI_Irecv(&x, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &req1);
    }
    //MPI_Wait(&req1, MPI_STATUS_IGNORE);
    MPI_Barrier(MPI_COMM_WORLD);
    printf("rank %d: x=%d\n",rank,x);

    MPI_Finalize();
    return 0;
}

