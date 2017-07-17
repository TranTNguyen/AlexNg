#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
int main(){
    int winNum, winAmount = 0, lostAmount = 0, result = 0, rowCount = 0;
    ifstream inFile("Ticket.txt");
    vector<int> temprow(2); // input two pairs of columns into vector
    vector<vector<int>> myArray{}; // input 2d vector
    
    // count the numbers in row
    while (inFile >> temprow[0] >> temprow[1])
    {
        myArray.push_back(temprow);
        rowCount++;
    }
    
    // display the numbers from file on screen
    cout << "Numbers from file: " << endl;
    for (int i = 0; i < rowCount; i++){
        for (int j = 0; j < 2; j++){
            std::cout << myArray[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "Enter the toss-up number: "; // enter the win number
    cin >> winNum;
    
    for(int i = 0; i< rowCount; i++)
    {
        if (myArray[i][0] == winNum)
        {
            winAmount = myArray[i][1] * 70; //  number user choose = win number, winAmount = winAmount * 70 - lostAmount
        }
        else
        {
            lostAmount = lostAmount + myArray[i][1]; //number user choose != win number, the amount will be -lost amounts
        }
    }
    
    result = winAmount - lostAmount;
    cout << "Your result: " << result;
    
    cout << endl << endl;
    system("pause");
    return 0;
}






