#include <iostream>
using namespace std;

class Array {
private:
    int size;        // Maximum capacity of the array
    int length;  // Number of elements currently in the array
    int *arr;        // Pointer to dynamically allocated array

public:
    // Constructor: Initialize array with size and default values
    Array(const int size) {
        this->size = size ; // Set size and allocate memory for the array
        arr = new int[size];
        initArray(0);  // Initialize the array with default values
    }

    // Constructor: Initialize array with a specific value
    Array(const int size, int v) : Array(size) {
        initArray(v);  // Initialize the array with the given value
    }

    // Initialize array elements with a specific value
    void initArray(int v) {
        	// Loop through the array and set each element to value v
        for (int i = 0; i < size; i++) {
            arr[i] = v;
        }
    }

    // Return the length of the array (number of elements inserted)
    int getLength() {
        return length;	// Return length
    }

    // Get the element at a given position
    int at(int pos) {

        if (pos >= 0 && pos < length) {	// Check if the position is valid
            return arr[pos];// If valid, return the element at the position
        }
 else {
            throw out_of_range("Index out of bound");
        }
    }

    // Check if the array is empty
    bool isEmpty() {
        return length == 0;
    }

    // Check if the array is full
    bool isFull() {
        return length == size;
    }

    // Print the array elements
    void print() {
        		// If the array is not empty, print all elements
        if (!isEmpty()) {
            for (int i = 0; i < length; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        // Otherwise, print that the array is empty
         else {
            cout << "The array is empty." << endl;
        }
    }

    // Insert an element at the end of the array
    void insert(int v) {
        // Check if the array is full
        if (!isFull()) {
            arr[length] = v; 		// If not full, insert the element at the end
            length++;
        } else {
            cout << "Insertion failed." << endl;  	// Otherwise, print that insertion failed
        }
    }

    // Insert an element at a specific position
    void insertAt(int pos, int v) {
        if (pos >= 0 && pos <length && !isFull()) {   // Check if the position is valid and array is not full
            for (int i = length; i > pos; i--) {
                arr[i] = arr[i - 1];     	// Shift elements to make space at the given position
            }
            arr[pos] = v;  	// Insert the new element
            length++;
        } else {
            cout << "insertion failed" << endl;  // Otherwise, print that insertion failed
        }
    }

    // Replace the element at a specific position
    void replaceAt(int pos, int v) {
        if (pos >= 0 && pos < length) {   		// Check if the position is valid
            arr[pos] = v;                 // Replace the element at the given position
        } else {
            cout << "Replacement failed" << endl; 	// Otherwise, print that replacement failed
        }
    }

    // Remove the last element from the array
    void remove() {
        if (!isEmpty()) {   	// Check if the array is not empty
            length--;  	// Decrease the length to remove the last element
        } else {
            cout << "The array is empty." << endl;			// Otherwise, print that the array is empty
        }
    }

    // Remove an element from a specific position
    void removeAt(int pos) {
        if (pos >= 0 && pos < length) {               	// Check if the position is valid and array is not empty
            for (int i = pos; i < length - 1; i++) {
                arr[i] = arr[i + 1]; 		// Shift elements to fill the gap
            }
            length--; 				// Remove the last element (decrease length)
        } else {
            cout << "Removal failed" << endl; 		// Otherwise, print that removal failed
        }
    }

    // Clear the array by resetting all elements and length
    void clear() {
                            // Reset all elements to 0 and set length to 0
    for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        length = 0;
    }

    // Reverse the array
    void reverseArray() {
        for (int i = 0; i < length / 2; i++) {
            swap(arr[i], arr[length - i - 1]);// Swap elements from both ends of the array until the middle is reached
        }
    }

    // Copy elements from another array into this array
    void copyArray(int data[], int n) {
        		// Check if the array size is sufficient to copy elements
				// Clear the current array and copy the elements from the source array
        if (n <= size) {
            clear();
            for (int i = 0; i < n; i++) {
                arr[i] = data[i];
            }
            length = n;
        }
    }

    // Destructor: Clean up memory when the object is destroyed
    ~Array() {
        delete[] arr;			// Deallocate the memory for the array
    }
};
