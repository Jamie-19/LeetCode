/*

380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. 
Returns true if the item was not present, false otherwise.

bool remove(int val) Removes an item val from the set if present. 
Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the RandomizedSet structure
typedef struct {
    int* arr;       // Array to store elements
    int size;       // Current size of the array
    int capacity;   // Maximum capacity of the array
} RandomizedSet;

// Function to create a new RandomizedSet
RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->size = 0;
    obj->capacity = 1000;  // Initial capacity
    obj->arr = (int*)malloc(obj->capacity * sizeof(int));
    return obj;
}

// Function to insert an element into the set
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    // Check if the array is full, and if so, double its capacity
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (int*)realloc(obj->arr, obj->capacity * sizeof(int));
    }

    // Check if the element already exists in the set
    for (int i = 0; i < obj->size; i++) {
        if (obj->arr[i] == val) {
            return false;  // Element already exists
        }
    }

    // Add the element to the end of the array and increment the size
    obj->arr[obj->size] = val;
    obj->size++;
    return true;
}

// Function to remove an element from the set
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    for (int i = 0; i < obj->size; i++) {
        if (obj->arr[i] == val) {
            // Replace the element with the last element in the array
            obj->arr[i] = obj->arr[obj->size - 1];
            obj->size--;
            return true;  // Element removed
        }
    }
    return false;  // Element not found
}

// Function to get a random element from the set
int randomizedSetGetRandom(RandomizedSet* obj) {
    srand(time(NULL));  // Seed the random number generator (should be called once)
    int random = rand() % obj->size;  // Generate a random index
    return obj->arr[random];  // Return the corresponding element
}

// Function to free the memory used by the set
void randomizedSetFree(RandomizedSet* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    RandomizedSet* obj = randomizedSetCreate();
    int choice, val;

    while (1) {
        printf("Enter 1 to insert, 2 to remove, 3 to get random, or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                bool param_1 = randomizedSetInsert(obj, val);
                if (!param_1) {
                    printf("Element already exists in the set.\n");
                }
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &val);
                bool param_2 = randomizedSetRemove(obj, val);
                if (!param_2) {
                    printf("Element not found in the set.\n");
                }
                break;
            case 3:
                printf("Random element: %d\n", randomizedSetGetRandom(obj));
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    randomizedSetFree(obj);
    return 0;
}

