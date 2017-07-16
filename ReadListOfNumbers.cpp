#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
    vector<double> number;
    ifstream inFile("Ticket.txt");
    if (inFile)
    {
        double value;
        while (inFile >> value) {
            number.push_back(value);
        }
        
    }
    
}
