

#ifndef map_h
#define map_h

//---------------------------------------------------------------------------------

using namespace std;

/**
 * @class Map
 * @brief A homemade MAP class that is not from the STL
 *
 * Map uses two template class, one to hold the key, and the other to hold the data
 * Map class contain a structure pair, which holds the key and the data
 * The pair is inserted into the map
 * Basically the map is a vector of pair
 *
 * @author CAI JIANBO
 * @version 01
 * @date 10/11/2020
 */
template <class key, class data>
/**
 * @brief myPair stucture is a pair that holds the key, and the data. It is initialised with the key and data inside the parameter
 */
struct myPair {
    key first; // key
    data second; // data
    myPair() {}; // Default constructor
    myPair(key keyFirst, data dataSecond) { // Initialised with key and data
        first = keyFirst; // Set key to first
        second = dataSecond; // Set data to second
    }
};


template <class T1, class T2>
class map {
public:
    /**
     * @brief Default constructor for the map
     */
    map();
    // Default constructor
    
    /**
     * @brief default destructor for the map
     */
    ~map();
    // Default destructor
    
    /**
     * @brief To insert a pair into the map
     *
     * @param myPair - a pair containing the key and data of the initialised class
     *
     * @return bool - True if successfully inserted into the array, false if unsuccessful
     */
    bool insert(myPair<T1, T2>);
    // Method to insert pair into the map
    
    /**
     * @brief To remove a pair based on the key from the map
     *
     * @param key - the key of the pair to be removed
     *
     * @return bool - True if successfully removed, false if unsuccessful
     */
    bool erase(T1 key);
    // Method to remove pair from the map
    
    /**
     * @brief To search for a pair if it exist inside the map
     *
     * @param key - the key of the pair to be searched
     *
     * @return bool - True if pair exists inside of the map, false if does not exists
     */
    bool search(T1 key) const;
    // Method to search for the key of the pair in the map
    
    /**
     * @brief To return the number of items from the map
     *
     * @return int - the number of items in the map
     */
    int size();
    // Method to return the number of items in the map
    
    /**
     * @brief To print out all the pairs in the map
     */
    void print() const;
    // Method to print out all the pairs in the map
    
    /**
     *@brief To return the key of the pair at the index
     *
     *@param index - the index of the item
     *
     *@return T1& - the key of the pair at the index
     */
    T1& key(int index);
    // Method to return the key of an item at the index
    
    /**
     * @brief To return the pair at the index
     *
     * @param index - the index of the item
     *
     * @return myPair - the pair at the index
     */
    myPair<T1, T2> at(int index);
    // Method to return the pair at the index
    
private:
    void allocate(int newCapacity); // Private method to auto expand the map capacity (similarly to a vector)
    void deleteElement(myPair<T1,T2>* map, int size, int indexToDelete); // Private method to move down the pair to fill out the "hole"
    int m_capacity; // The capacity of the map
    int m_size; // The size of the map
    myPair<T1, T2>* m_map; // Basically an array of pair, to store the pair
};

template <class T1, class T2>
map<T1, T2>::map() { // Default constructor
    m_size = 0; // Set the size to 0
    m_capacity = 10; // Set the capacity to 10
    m_map = new myPair<T1, T2>[m_capacity]; // Create a new array of pair, and set the max capacity to the capacity
}

template <class T1, class T2>
map<T1, T2>::~map() { // Default destructor
}

template <class T1, class T2>
bool map<T1, T2>::insert(myPair<T1, T2> pair) { // Inserting method
    if (m_size >= m_capacity/2) { // If the size of the map is more than half of the capacity
        allocate(m_capacity * 2); // Auto expand the capacity
    }
    m_map[m_size] = pair; // Set the map at index size to the pair
    m_size++; // +1 to the size
    return true; // Return true (succesfully inserted)
}

template <class T1, class T2>
bool map<T1, T2>::erase(T1 key) { // Erasing method
    for (int i = 0; i < m_size; i++) { // Iterate throught the array
        if (m_map[i].first == key) { // If the pair at the index i of the map is the same as the key
            deleteElement(m_map, m_size, i); // use the delete element function to remove the pair
            m_size--; // to delete the last element of the map (duplicated value from the delete element function)
            return true; // Return true
        }
    }
    return false; // Return false (not deleted)
}

template <class T1, class T2>
void map<T1, T2>::deleteElement(myPair<T1,T2>* map, int size, int indexToDelete) { // delete element function, using the map, size of the map, and the index to delete
    for (int i = indexToDelete; i < size; i++) { // Set i to the index to be deleted, iterate through the last element of the map (size)
        map[i] = map[i+1]; // Set the value of index i to the value of index i+1
    }
}

template <class T1, class T2>
void map<T1, T2>::print() const { // Printing function
    for (int i  = 0; i < m_size; i++) { // Iterate through the entire map
        cout << m_map[i].first << " : " << m_map[i].second << endl; // Print out the key : data
    }
}

template <class T1, class T2>
bool map<T1, T2>::search(T1 key) const { // Search function
    for (int i = 0; i < m_size; i++) { // Iterate through the map
        if (m_map[i].first == key) { // If the key of the pair of i index is equals to the key provided
            return true; // return true
        }
    }
    return false;
}

template <class T1, class T2>
void map<T1, T2>::allocate(int newCapacity) { // Auto sizing map
    myPair<T1, T2> * newMap = new myPair<T1, T2>[m_capacity]; // Create a new map
    myPair<T1, T2> * newMapP = newMap; // Create a new map pointer, pointing to the new map just created
    myPair<T1, T2> * oldMapP = m_map; // Create an old vector pointer, pointing to the old map
     
    while (oldMapP != (m_map+m_size)) { // While the old map pointer is not equals to address of the old map + size
        *(newMapP) = *(oldMapP); // Set the value of what's inside the address of the new map to the value of what's inside the address of the old map
        newMapP++; // Next item
        oldMapP++;
    }
    
    m_capacity = newCapacity; // Set capacity to the new capacity
    delete[] m_map; // Delete the old map
    m_map = newMap; // Create the map to the new map
}

template <class T1, class T2>
int map<T1, T2>::size() { // Method to return the size of the map
    return m_size; // Return the size
}

template <class T1, class T2>
T1& map<T1, T2>::key(int index) { // Method to return the key of an item at the index
    return m_map[index].first; // Return the key at the index of the map
}

template <class T1, class T2>
myPair<T1, T2> map<T1, T2>::at(int index) { // Method to return the pair at the index
    return m_map[index]; // Return the pair at the index of the map
}

#endif /* map_h */
