#include <iostream>
using namespace std;

int main() {
    // Define a 2D array to represent the "Temp" table
    const int rows = 3; // Number of rows
    const int columns = 2; // Number of columns (e.g., Time and Temperature)
    
    // Example "Temp" table with time (hour) and corresponding temperature
    int temp[rows][columns] = {
        {8, 20},  // 8:00 AM, 20 degrees Celsius
        {12, 25}, // 12:00 PM, 25 degrees Celsius
        {18, 22}  // 6:00 PM, 22 degrees Celsius
    };

    // Printing the table header
    cout << "Time\tTemperature (°C)" << endl;
    cout << "----\t---------------" << endl;
    
    // Loop through the "Temp" table and print each row
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if (j == 0) {
                cout << temp[i][j] << ":00\t"; // Print time
            } else {
                cout << temp[i][j] << endl; // Print temperature
            }
        }
    }

    return 0;
}
