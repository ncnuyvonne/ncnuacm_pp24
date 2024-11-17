/* allgather */
#include <mpi.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int x = rank+1;
    int *a;
    MPI_Allgather(&x, 1, MPI_INT, a, 1, MPI_INT, MPI_COMM_WORLD);
    
    printf("rank %d: ",rank);
    for(int i=0;i<size;i++)
    {
       printf("a[%d]=%d, ",i,a[i]);
    }
    printf("\n");
    
    MPI_Finalize();
    return 0;
}

