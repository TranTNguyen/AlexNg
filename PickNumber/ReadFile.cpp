#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

vector<vector<int>> readNumberFromFile(const string& filename)
{
    ifstream inFile(filename);
    vector<int> temprow(2); // input two pairs of columns into vector
    vector<vector<int>> myArray{}; // input 2d vector
    
    // count the numbers in row
    while (inFile >> temprow[0] >> temprow[1])
    {
        myArray.push_back(temprow);
    }
    
    return myArray;
}

int computeWinLoss(vector<vector<int>> number,int tossUpNum, int win, int lost)
{
    int result;
    for(int i = 0; i< number.size(); i++)
    {
        if (number[i][0] == tossUpNum)
        {
            win = number[i][1] * 70;
        }
        else
        {
            lost = lost + number[i][1];
        }
    }
    result = win - lost;
    cout << "Your result: " << result;
    
    return tossUpNum;
}


int main(){
    int winNum, winAmount = 0, lostAmount = 0;
    
    vector<vector<int>> myArray = readNumberFromFile("Ticket.txt");
    
    // display the numbers from file on screen
    cout << "Numbers from file: " << endl;
    for (int i = 0; i < myArray.size(); i++){
        for (int j = 0; j < 2; j++){
            std::cout << myArray[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "Enter the toss-up number: "; // enter the win number
    cin >> winNum;
    computeWinLoss(myArray, winNum, winAmount, lostAmount);
    
    cout << endl << endl;
    system("pause");
    return 0;
}






