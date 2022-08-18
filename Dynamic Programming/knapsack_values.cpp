// Knapsack problem for a sack with capacity C and a set of objects with defined
// weights and values, each object is unique. We want to find the maximum attainable
// value for a sack with the given capacity and the given item set. 
#include <iostream>

using namespace std;

typedef struct Object {
    int value;
    int weight;
} Object;

int main() {
    int capacity;
    cin >> capacity;

    int nb_objects;
    cin >> nb_objects;

    Object objs[nb_objects];
    for (int i = 0; i < nb_objects; i++) {
        int weight;
        int value; 
        cin >> weight; 
        cin >> value; 
        objs[i] = Object {value, weight};
    }

    int states[capacity + 1][nb_objects + 1];
    for (int row = 0; row <= capacity; row++) {
        for (int col = 0; col <= nb_objects; col++) {
            states[row][col] = 0;
        }
    }

    for (int row = 1; row <= capacity; row++) {
        for (int col = 1; col <= nb_objects; col++) {
            Object &current =  objs[col - 1];

            //If we can fulfill a knapsack with capacity equal to the current minus
            //the current object weight and with an item set not including the
            //current item, we can fulfill one with the current capacity by adding
            //the current item, and the max value we can obtain is the max between
            //a value obtained by using items from smaller item sets or adding the
            //current object
            if (row - current.weight >= 0) {
                states[row][col] = max(states[row][col - 1], states[row - current.weight][col - 1] + current.value);
            }
            //If we cannot add the current object, the max value we can obtain is the
            //same we had obtained with the immediate previous item set.
            else {
                states[row][col] = states[row][col - 1];
            }
        }
    }

    for (int row = 0; row <= capacity; row++) {
        for (int col = 0; col <= nb_objects; col++) {
            cout << states[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Max value attainable with given item set: " << states[capacity][nb_objects] << endl;


    return 0;
}

