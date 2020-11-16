//
//  vector.h
//  Assignment 2
//
//  Created by Kenta on 9/6/20.
//  Copyright © 2020 Kenta. All rights reserved.
//
//---------------------------------------------------------------------------------

#ifndef vector_h
#define vector_h

//---------------------------------------------------------------------------------

using namespace std;

/**
 * @class vector
 * @brief A homemade vector that is not from the STL
 *
 * vector uses a template class that will hold the data type/structure specified
 * vector is initalised with a default capacity of 10
 * and capacity will increase if more than half of the vector is occupied
 *
 * @author Kenta Toh
 * @version 01
 * @date 06/06/2020
 */
template <class T>
class vector<T> {

public:
    /**
     * @brief Default constructor for vector
     */
    vector();
    // Default constructor
    
    /**
     * @brief Destructor for vector
     */
    ~vector();
    // Destructor for vector
    
    /**
     * @brief Clear the vector
     */
    bool clear();
    // Method to clear the vector
    
    /**
     * @brief Return the current size of the vector
     *
     * @return int - the current size of the vector
     */
    int size() const;
    // Method to return the current size of the vector
    
    /**
     * @brief Return the current capacity of the vector
     *
     * @return int - the current capacity of the vector
     */
    int capacity() const;
    // Method to return the current capacity of the vector
    
    /**
     * @brief Display all the elements inside of the vector
     */
    void print() const;
    // Method to display all the elements inside of the vector
 
    /**
     * @brief Push an item to the back  of the vector
     *
     * @param t - the item to be push to the back
     */
    void push_back(const T& t);
    // Method to push an item to the back of the vector
    
    /**
     * @brief Dynamically resize the capacity of the vector if the size is more than half of the capacity
     *
     * @param newCapacity - double of the old capacity
     */
    void allocate(int newCapacity);
    // Method that will be called by the push_back method if the size exceeds half of the capacity
    
    /**
     * @brief Remove the last item of the vector, and returns it
     *
     * @return T - the item to be removed from the vector
     */
    T pop_back();
    // Method to delete the last item of the vector, and returns the item
    
    /**
     * @brief Return the item at the specify index of the vector
     *
     * @return T - the item at the specify index
     */
    T& at(int index);
    // Method to return the item at the index;
    
    /**
     * @brief Serarch the array if the item exisit
     *
     * @param item - item to search for
     *
     * @return bool - true if item exists in the vectorm else false
     */
    bool search(T item);
    // Method to search if an item exists inside the vector
    
    /**
     * @brief Method to shuffle the vector
     */
    void shuffle();
    // Method to shuffle the vector

private:
    int m_size; // Size of the vector
    int m_capacity; // Capacity of the vector
    T * m_vector; // Container of the vector, storing T data type/structure
};

template <class T>
vector<T>::vector() { // Default constructor
    m_size = 0; // Set the current size to 0
    m_capacity = 10; // Set the capacity to 10
    m_vector = new T [m_capacity]; // Creates a vector of the specify data type/structure of the capacity
}

template <class T>
vector<T>::~vector() { // Destructor
    delete[] m_vector; // Deletes each element from the vector, then deletes the vector
}

template <class T>
bool vector<T>::clear() { // Clear the vector
    if (m_size == 0) { // If the size is 0, means that the vector does not contain any element (essentailly cleared)
        return false; // Return false (Nothing done)
    } else {
        m_size = 0; // Else set the size to 0;
        m_capacity = 10; // Resets the capacity back to 10
        return true; // Return true (vector cleared)
    }
}

template <class T>
int vector<T>::size() const { // Return the size of the vector
    return m_size;
}

template <class T>
int vector<T>::capacity() const { // Return the capacity of the vector
    return m_capacity;
}

template <class T>
void vector<T>::print() const { // Print each element of the vector
    for (int i = 0; i < m_size; i++) { // For loop for index i to access each element, from 0 to the size (last element) of the vector
        cout << m_vector[i] << " "; // Print element of i index
        cout << endl; // Aesthetics purpose
    }
}

template <class T>
void vector<T>::push_back(const T& t) { // Insert an item to the back of the vector
    if (m_size >= m_capacity/2) { // If the current size of the vector is more than half of the capacity
        vector<T>::allocate(m_capacity * 2); // Allocate more slots for the capacity
    }
    m_vector[m_size] = t; // Insert the item to the back of the vector
    m_size++; // Increase the size of the vector
}

template <class T>
void vector<T>::allocate(int newCapacity) { // Allocate slots to the vector to the new capacity
    T * newVector = new T[m_capacity]; // Create a new vector
    T * newVectorP = newVector; // Creates a new vector pointer, pointing to the new vector just created
    T * oldVectorP = m_vector; // Create an old vector pointer, pointing to the old vector
    while (oldVectorP != (m_vector+m_size)) { // While the pointer is not equals to the address of the old vector + number of size
        *(newVectorP) = *(oldVectorP); // Set the value of what's inside the address of the new vector to the value of what's inside the address of the old vector;
        newVectorP++; // Next Set
        oldVectorP++; // Next item to assign
    }
    m_capacity = newCapacity; // Set the capacity of the vector to the new capacity
    delete[] m_vector; // Delete the old vector
    m_vector = newVector; // Set the vector to the new one
}

template <class T>
T vector<T>::pop_back() { // Delete the last element of the vector
    T item = m_vector[m_size-1]; // Last item (size - 1)
    m_size--; // Reduce the size
    return item; // Pop back the last item;
}

template <class T>
T& vector<T>::at(int index) { // Return the element of the specify index
    return m_vector[index];
}

template <class T>
bool vector<T>::search(T item) { // Search the array
    for (int i = 0; i < size(); i++) { // Iterate through the array
        if (m_vector[i] == item) { // If item matches the item at i
            return true; // Return true
        }
    }
    return false; // Else return false
}

template <class T>
void vector<T>::shuffle() { // Shuffling the vector based on Fisher-Yates algorithm
    for (int i = (m_size - 1); i != 0; i--) { // Set i to the size of the vector - 1; while i is not equals to 0, i decrease
        srand(time(NULL)); // Set the time seed to null
        int j = rand() % i; // Create an int j, random from 0 to i;
        
        T temp = m_vector[i]; // Set the temp variable to the item at i
        m_vector[i] = m_vector[j]; // Set the item at i to the item at j
        m_vector[j] = temp; // Set the item at j to the item at temp (initial i)
    }
}

#endif /* vector_h */
