// Knapsack problem for a sack with capacity C and
// a set of objects with defined weights, each object
// can be used an unlimited number of times. Should
// return if it's possible to fulfill the knapsack
// with the given items

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

    bool states[capacity + 1];
    states[0] = true; //Always possible to fulfill a zero capacity sack


    for (int i = 1; i <= capacity; i++) {
        states[i] = false; //We initialize the current state as false
        for (int j = 0; j < nb_objects; j++) {
            int previous_capacity = i - weights[j];

            // If it is possible to fulfill a smaller sack removing the current weight
            // It is possible to fulfill the current sack by adding the current weight
            if (previous_capacity >= 0 && states[previous_capacity] == true) {
                states[i] = true;
                break;
            }
        }
    }



    if (states[capacity]) 
        cout << "It is possible to fulfill the given knapsack with the given objects" << endl;
    else 
        cout << "It is not possible to fulfill the given knapsack with the given objects" << endl;


    return 0;
}

