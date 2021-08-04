#include <iostream>
#include <cstdio>
#include <vector>
#include "mpi.h";
#include "Home.cpp"

int main(int argc, char* argv[])
{
    /*
        IF YOU HAVE ANY PROBLEM WITH EXECUTION OR IMPLEMENTATION OF THIS ARCHITECTURE,
            PLEASE READ PROJECT DESCRIPTION AT GITHUB (OR OPEN HELPME.txt AT SOLUTION FILES).
    */
	int const CONST_MAIN_THREAD = 0;
	int const CONST_FIRST_WORKER_THREAD = 0;
	int const CONST_SECOND_WORKER_THREAD = 0;
	int const CONST_THIRD_WORKER_THREAD = 0;

    int commsize;
    int myRank;
	MPI_Status statusOfEachThread[4];

    MPI_Init(&argc, &argv);

    //Define number of threads/process has active 
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);

    //Define current rank of my thread (his number)
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    std::vector<Home> listOfRandomHome;
    listOfRandomHome.clear();

    for (size_t i = 0; i < 100000; i++)
    {
        listOfRandomHome.insert(listOfRandomHome.end(), Home().BuildRandom());
    }

    //Will wait for all threads.
    MPI_Barrier(MPI_COMM_WORLD);

    //First test, sum of all area values
	double totalValue = 0; //Armazena o valor total da área total
	double sumOfThisWorker = 0; //Value which each worker will send to main thread.
	if (myRank == CONST_MAIN_THREAD) //The main thread will take and storage the values
	{
		for (int indexRank = 0; indexRank < (commsize - 1); indexRank++) //Percorre todas threads filhas
		{
			MPI_Recv(
				&sumOfThisWorker,
				1,
				MPI_DOUBLE,
				MPI_ANY_SOURCE,
				MPI_ANY_TAG,
				MPI_COMM_WORLD,
				&statusOfEachThread[indexRank]);  //Recebe o valor calculado na thread filha

			totalValue = (totalValue + sumOfThisWorker); //Acrescenta o valor recebido da filha na soma total
		}
	}
	else
	{
		//Number of home which each thread will process
		int numberHomeIWillProcess =
			listOfRandomHome.size() / (commsize - 1);

		int numberIWillStart =
			(myRank - 1) * numberHomeIWillProcess;

		cout << "I'm " << myRank << " worker, and i will process " << numberIWillStart << " to " << numberHomeIWillProcess << endl;

		for (int index = numberIWillStart; index < numberHomeIWillProcess; index++)
		{
			sumOfThisWorker =
				sumOfThisWorker + listOfRandomHome[index].HomeArea();
		}

		MPI_Send(&sumOfThisWorker, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
	}

	MPI_Barrier(MPI_COMM_WORLD);

	if (myRank == CONST_MAIN_THREAD)
	{
		cout << "Total value: " << std::to_string(totalValue) << endl;
	}

	std::getchar();
	//Finalize current application
	MPI_Finalize();
}