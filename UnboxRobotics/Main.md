Assignment : The task is to exchange information between 3 different programs - 2 C++ scripts and 1 python script.


Estimated Time to finish the task : 10-12 hours


Subtasks Breakdown : 

Script A (cpp):-
counter Implementation of 0.1 unit
counter range from 0 to 10000000
counter value should be printed at the end of the loop
fetch and print the latest timestamp at the end of every loop
timestamp should be type casted into a string
loop should run at 100 Hz using sleep function
text file to store the counter value and timestamp
write to the file in each loop iteration
Script A will write the counter and timestamp to the file, and Script B will read from this file.

Script B (cpp):-
fetch the shared values by script A in every loop
store and print the fetched values
print the fetched values at the end of each loop
run the loop at 200 Hz
host an API for exchanging the information with any external client

Script C (python):-
fetch the values by any C++ or Python program in every loop via API call
should appropriately print the fetched values at the end of the main loop
implement an endpoint /get_data_from_B that returns the counter value and timestamp in JSON format
loop should run at 10 Hz using sleep function


Things to be kept under consideration : 

Script A (C++):
Ensuring that the counter and timestamp are written to the file consistently.
Handle any potential file writing errors gracefully.

Script B (C++):
Continuously attempt to read the shared file, even if it temporarily becomes unavailable.
Ensure the REST API service continues to run and handle requests even if the data is temporarily unavailable.

Script C (Python):
Implement retries for the API calls to handle temporary unavailability of Script B.
Ensure the script can recover from temporary errors.