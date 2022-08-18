// Knapsack problem for a sack with capacity C and
// a set of objects with defined weights, each object
// is unique. Should return if it's possible to fulfill
// the knapsack with the given items

#include <iostream>

using namespace std;

int main() {
    int capacity;
    cin >> capacity;

    int nb_objects;
    cin >> nb_objects;

    int weights[nb_objects];
    for (int i = 0; i < nb_objects; i++) {
        int weight; 
        cin >> weight; 
        weights[i] = weight;
    }

    bool states[capacity + 1][nb_objects + 1];
    for (int row = 0; row <= capacity; row++) {
        for (int col = 0; col <= nb_objects; col++) {
            if (row == 0) states[row][col] = true;
            else if (col == 0) states[row][col] = false;
            else states[row][col] = false;
        }
    }

    for (int row = 1; row <= capacity; row++) {
        for (int col = 1; col <= nb_objects; col++) {

            //If we can fulfill a knapsack of the current capacity using
            //a set containing less objects than the current, we can using
            //the current object set as well.
            if (states[row][col - 1] == true) states[row][col] = true;

            //If we can fulfill a knapsack of current - current_weight capacity
            //using a set with a set not containing the current object, we can
            //ass this object and fulfill a knapsack of the current capacity
            else if (row - weights[col - 1] >= 0 && 
                states[row - weights[col - 1]][col - 1] == true) states[row][col] = true;

            else states[row][col] = false;
        }
    }




    if (states[capacity][nb_objects]) 
        cout << "It is possible to fulfill the given knapsack with the given objects" << endl;
    else 
        cout << "It is not possible to fulfill the given knapsack with the given objects" << endl;


    return 0;
}

