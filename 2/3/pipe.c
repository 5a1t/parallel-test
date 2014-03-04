#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>

#define PIPELINE 1
#define POWER 16

int main(int argc, char **argv)
{
	int myid, numprocs;
	int[2] data = {0};
	data[0] = atoi(argv[0]);
	data[1] = 1;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);

	int i;
	for(i = 0; i <= POWER/numprocs; i++){
	//start ball rolling
	if (myid == 0) {
		data[0] = data[0] * data[0];
		data[1] ++;
		//send data to each processor
		MPI_Send(data, 2, MPI_INT, (myid+1)%numprocs, 0, MPI_COMM_WORLD);
	}
	else{
		MPI_Recv(data, 2, MPI_INT, myid-1, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		data[0] = data[0] * data[0];
		MPI_Send(data, 2, MPI_INT, (mid+1)%numprocs, 0, MPI_COMM_WORLD);
	}
	}	

	//Print this out last so it doesn't get mixed with the output from the other procs.
	if(myid == 0){

		printf("The total is %d after %d iterations.\n", data[0], data[1]);
		
	}
	MPI_Finalize();

return 0;
}


