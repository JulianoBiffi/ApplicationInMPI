# Application in C++ Using Message Passing Interface (MPI)
This is a simple example of use MPI on c++ architecture, the examples presented here can not be the best way to doing, but a main focus of this is help you to install and create your application c++ using MPI.

Basically MPI will run one or more instance of your application (you can compare with opening your application more than one time, but on this case you can send data between your instances), never forget this archieture are not parrallel archieture.

# Running your application
You will use Microsoft MPI to run your app, first build your application, after open bash (cmd or powershell) and run your .exe using:

<b>mpiexec -n 5 APPLICATION_NAME.exe </b> (Five is the number of thread which i will use, on my example, one thread will be the main and dont doing any process, and four are the workers, but you can put whatever you want if your CPU hold on :D)

# Installation 
For my examples a was use Visual Studio 2019.

Install Microsoft MPI at: <href>https://docs.microsoft.com/en-us/message-passing-interface/microsoft-mpi</href>

After installing Microsoft MPI u will need configure your application

* Right click on selected project -> Properties
  * C/C++ -> General
  * Additional Include Directories
  * Click to down arrow
  * Edit
  * New Line
  * Find where you instaled microsoft MPI and select INCLUDE folder, here is in C:\Program Files (x86)\Microsoft SDKs\MPI\Include
  * Click in OK.


* Now go to Linker -> General
  * Additional Library Directories 
  * Click to down arrow
  * Edit
  * New Line
  * Find where you instaled microsoft MPI and select LIB folder, and select x86 folder, here is in C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x86
  * Click in OK.
  
* Now go to Linker -> Input
  * Additional Dependencies
  * Click to down arrow
  * Edit -> at first white text square write "msmpi.lib" (without space and quotation marks)
  * Ok
  
* Click in Apply.

 All steps are performed in this video from youtuber "WilliamWilliam" (channel URL-> <href>https://www.youtube.com/channel/UCnD7j2rO2LKpXnJj6F4fd5Q</href>)
 
 At video: <href>https://www.youtube.com/watch?v=BA_Mqi3a9HI</href>
 
 Visited at: 08/09/2021.
 
 Thank you William !!
