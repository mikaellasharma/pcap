 #MPI program where the master process (process 0) sends different messages to three slaves and the slave processes receives the message and prints it.


#include "mpi.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int rank,s;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD, &s);
char p[10]="WELCOME";
char q[10]="TO";
char r[10]="PCAPLAB";

if(rank==0)
{
MPI_Send(p,strlen(p),MPI_CHAR,1,1,MPI_COMM_WORLD);
memset(p,0,sizeof(p));
MPI_Send(q,strlen(q),MPI_CHAR,2,1,MPI_COMM_WORLD);
memset(q,0,sizeof(q));
MPI_Send(r,strlen(r),MPI_CHAR,3,1,MPI_COMM_WORLD);
memset(r,0,sizeof(r));
fflush(stdout);
}
else if (rank==1) 
{ 
MPI_Recv(p,strlen(p),MPI_CHAR,0,1,MPI_COMM_WORLD, MPI_STATUSES_IGNORE); 
fprintf(stdout,"I have received %s from process 0 in process 1\n",p); 
fflush(stdout); 
} 
else if (rank==2) 
{ 
MPI_Recv(q,strlen(q),MPI_CHAR,0,1,MPI_COMM_WORLD, MPI_STATUSES_IGNORE); 
fprintf(stdout,"I have received %s from process 0 in process 2\n",q); 
fflush(stdout); 
} 
else if (rank==3) 
{ 
MPI_Recv(r,strlen(r),MPI_CHAR,0,1,MPI_COMM_WORLD, MPI_STATUSES_IGNORE); 
fprintf(stdout,"I have received %s from process 0 in process 3\n",r); 
fflush(stdout); 
} 
else
{
	fprintf(stdout,"process %d: received nothing \n",rank); 
}
MPI_Finalize();
return 0;
}
