#include <iostream>
using namespace std;

int main() {
    // Define a 3-dimensional array with size 2x3x4
    int arr[2][3][4];

    // Initialize the array with some values
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                arr[i][j][k] = (i+1)*(j+1)*(k+1);
            }
        }
    }

    // Print out the array
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
