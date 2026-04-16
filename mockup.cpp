//COMSC-210-5068， Lab 29, Yang Liu

// PSEUDOCODE
// Include necessary headers for file handling, data structures, etc.
// Define a function to simulate production line changes over time
    // Parameters: productionMap (map of stations), currentInterval (int)
// Define main function
    //Initialize a map to store workstation information, each associated with an array of lists for waiting, completed, and logs
    //Open an external file to read initial data about parts and populate the map
        //If file does not open, print an error and exit
    //Read data from file and populate map
        //For each line, extract workstation name and part data
        //Insert part into the appropriate list (waiting) in the array for their workstation
    //Close the file

    //Begin a time-based simulation for production changes
        //For 25 time intervals
            //Iterate through each workstation in the map
                //For each workstation, simulate changes
                    //Randomly decide if a part is to be added or removed from the queue
                        //If adding, generate or select a new part name to add to the waiting list
                        //If removing, select a random part from the waiting list to move to completed
                    //Print the changes for this interval.
        //Simulate more complex production line changes
            //Random events impacting the workstation: new parts arriving, backlogs
            //Wait or pause briefly to simulate the passage of time between intervals
// End of main function


#include<iostream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

map<string, array<list<string>, 3>> productionMap;
const string TEST_STATION = "ASSEMBLY_STATION_01";

void simulateProductionChanges(map<string, array<list<string>, 3>>& lineMap, int currentInterval);

int main() {

    productionMap[TEST_STATION][0].push_back("INITIAL_PART_001");

    cout << "--- Initial State ---" << endl;
    cout << "Added dummy part to " << TEST_STATION << endl << endl;

    for (int i = 1; i <= 25; i++) {
        simulateProductionChanges(productionMap, i);
    }

    cout << "\n--- Mockup Complete ---" << endl;

    return 0;
}

void simulateProductionChanges(map<string, array<list<string>, 3>>& lineMap, int currentInterval) {
    srand(time(0));

    for (auto& entry : lineMap) {
        string stationName = entry.first;
        auto& waiting = entry.second[0];
        auto& completed = entry.second[1];
        auto& logs = entry.second[2];

        bool remove = rand() % 2 == 0;

        if (remove && !waiting.empty()) {
            string part = waiting.front();
            waiting.pop_front();
            completed.push_back(part);
            cout << "Interval " << currentInterval << ": Moved " << part << " to completed." << endl;
        } else {
            string newPart = "PART_" + to_string(rand() % 9999);
            waiting.push_back(newPart);
            cout << "Interval " << currentInterval << ": Added new part " << newPart << endl;
        }
    }
}