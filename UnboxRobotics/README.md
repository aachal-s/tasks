Dependencies:
- c++ compiler
    sudo apt-get update
    sudo apt-get install g++

- httplib.h
    https://github.com/yhirose/cpp-httplib

- python
    sudo apt-get update
    sudo apt-get install python3
    pip install requests

**********************************************************************************************************************************************************

Compile and Run:
- Script A
    cd UnboxRobotics/Script_A
    g++ -o script_a Script_A.cpp
    ./script_a

- Script B
    cd UnboxRobotics/Script_B
    g++ -o script_b Script_B.cpp
    ./script_b

- Script C
    python Script_C.py

**********************************************************************************************************************************************************

Launching:

http://localhost:8080/api/shared_data

-accessing the API_ENDPOINT will trigger interactions between Script A, Script B, and Script C, resulting in the exchange of shared data and its representation on the console.

**********************************************************************************************************************************************************

Information:

Libraries-

iostream: For console input and output.
string: For string operations.
chrono: For time-related operations.
thread: For managing and controlling threads.
fstream: For file input and output operations.
httplib.h: For creating and handling HTTP servers and clients.
time: This module provides various time-related functions.
requests: This module is a third-party library that allows you to send HTTP requests easily.


Meanings/Implementation-

ofstream is a data type in C++ provided by the <fstream> library. It stands for "output file stream" and is used to create files and write data to them.

outFile is the name of the ofstream object being created. This object will be used to write data to the file.

this_thread is a namespace in the C++ Standard Library that provides functions to manage the current thread. It is defined in the <thread> header.

sleep_for is a function in the this_thread namespace that pauses the execution of the current thread for a specified duration.

milliseconds is a type defined in the <chrono> header that represents a duration in milliseconds.
1000 / loop_frequency is an expression that calculates the duration in milliseconds.

cerr is a predefined object in C++ that is part of the standard I/O stream library. It stands for "standard error" and is used to output error messages. The primary purpose of cerr is to provide a mechanism for outputting errors and diagnostic information separately from the standard output (cout).

server_thread.join(); statement in C++ is used to wait for the server_thread to finish its execution before the program continues. This is a crucial part of multithreading in C++ when you want to ensure that the main thread waits for another thread to complete its task.

sleep() to add a delay between iterations to achieve the desired frequency.

**********************************************************************************************************************************************************
