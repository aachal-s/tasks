#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std; 
using namespace std::chrono;

//struct data structure
struct SharedData {
    double counter;
    string timestamp;
};

class Counter {
public:
    void run() {
        const double max_counter = 10000000.0;
        const int loop_frequency = 100; //100Hz

        //create and open file for sharing data
        ofstream outFile("../shared_data.txt");

        while (counter_ <= max_counter) {
            counter_ += 0.1;

            auto timestamp = getCurrentTimestamp();
            cout << "Counter: " << counter_ << ", Timestamp: " << timestamp << endl;

            //sharing counter value and timestamp
            SharedData data = {counter_, timestamp};
            shareData(data, outFile);

            this_thread::sleep_for(milliseconds(1000 / loop_frequency));
        }

        outFile.close();
    }

private:
    double counter_ = 0.0;

    //fetch current timestamp and convert to string
    string getCurrentTimestamp() {
        auto now = system_clock::now();
        auto time = system_clock::to_time_t(now);
        string time_str(ctime(&time));
        time_str.pop_back(); // Remove the newline character
        return time_str;
    }

    //share counter value and timestamp
    void shareData(const SharedData& data, ofstream& outFile) {
        outFile.seekp(0); //move to the start of the file
        outFile << data.counter << endl;
        outFile << data.timestamp << endl;
    }
};

int main() {
    Counter counter;
    counter.run();
    return 0;
}
