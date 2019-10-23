#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

const double EPS = 1E-6;
const double rectang_a = 0.1;
const double rectang_b = 0.5;
#include "integral_average_rectangle.h"







int main (int argc, char **argv)

{

	



    MPI_Init (&argc, &argv);

    int rank, commsize;
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double t;
    t = MPI_Wtime();





    average_rectang_posteriori_accuracy(rectang_a, rectang_b, EPS);






    t = MPI_Wtime() - t;
    printf("time: %8f  rank: %d \n", t, rank);



    double t_glob = 0;
    MPI_Reduce(&t, &t_glob, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    if (rank == 0)
        printf("Max time: %8f \n", t_glob);
    MPI_Finalize();
    
    

	


    return 0;
}