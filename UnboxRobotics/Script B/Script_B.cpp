#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "httplib.h" 

using namespace std;
using namespace std::chrono;

struct SharedData {
    double counter;
    string timestamp;
};

class DataFetcher {
public:
    //fetch shared data from Script A
    SharedData fetchSharedData() {
        SharedData data;
        data.counter = 0.0; //initialize counter
        data.timestamp = "N/A"; //initialize timestamp

        //open file for reading shared data
        ifstream inFile("../shared_data.txt");
        if (inFile.is_open()) {
            if (inFile >> data.counter) {
                inFile.ignore(); //ignore the newline character
                getline(inFile, data.timestamp);
            } else {
                cerr << "Error reading shared data file." << endl;
            }
            inFile.close();
        } else {
            cerr << "Unable to open shared data file." << endl;
        }

        return data;
    }
};

int main() {
    DataFetcher dataFetcher;
    const int loop_frequency = 200; //200Hz

    //create HTTP server
    httplib::Server server;

    //define API endpoint for fetching shared data
    server.Get("/api/shared_data", [&](const httplib::Request& req, httplib::Response& res) {
        //fetch shared data from Script A
        SharedData sharedData = dataFetcher.fetchSharedData();

        //JSON response
        string response = "{\"counter\": " + to_string(sharedData.counter) + ", \"timestamp\": \"" + sharedData.timestamp + "\"}";
        res.set_content(response, "application/json");
    });

    //server starting on port 8080
    thread server_thread([&server](){
        server.listen("localhost", 8080);
    });

    while (true) {
        SharedData sharedData = dataFetcher.fetchSharedData();
        cout << "Fetched Counter: " << sharedData.counter << ", Timestamp: " << sharedData.timestamp << endl;
        this_thread::sleep_for(milliseconds(1000 / loop_frequency));
    }

    server_thread.join();
    return 0;
}
