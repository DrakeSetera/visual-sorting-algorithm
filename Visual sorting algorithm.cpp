#include <iostream>
#include <unistd.h>

using namespace std;

void display_board(int * array, int & size);
int main() {
    int array[20];
    int size = sizeof(array)/sizeof(int);

    srand(time(NULL));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        array[i] = rand() % 20 + 1;
        cout << array[i] << endl;
    }

    display_board(array, size);

    int holder;
    for (int n1 = 0; n1 < sizeof(array)/sizeof(int); n1++) {
        for (int n2 = n1 + 1; n2 < sizeof(array)/sizeof(int); n2++) {
            if (array[n1] < array[n2]) {
                holder = array[n1];
                array[n1] = array[n2];
                array[n2] = holder;
            }
            sleep(1);
            for(int r = 0; r < sizeof(array)/sizeof(int); r++){
                if (r == n1 || r == n2){
                    cout << "\\/";
                }
                else{
                    cout << "  ";
                }
            }
            cout << "\n";
            display_board(array, size);
        }

    }

    return 0;
}

void display_board(int * array, int & size){
    for (int r = 20; r > 0; r--){
        for (int c = 0; c < size; c++){
            if (array[c] >= r){
                cout << "[]";
            }
            else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n========================================\n\n";
}