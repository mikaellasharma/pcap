#Display Processor Name, Rank and Size using MPI program.

#include "mpi.h"
#include<stdio.h>
int main(int argc, char*argv[])
{
MPI_Init(&argc,&argv);
int rank,size,len;
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
char name[MPI_MAX_PROCESSOR_NAME];
MPI_Get_processor_name(name,&len);
printf(" The processor name is %s, rank = %d , size = %d \n",name,rank,size);
MPI_Finalize();
}
