

#ifndef Bst_h
#define Bst_h

//---------------------------------------------------------------------------------

using namespace std;

/**
 * @class bst
 * @brief A homemade BST class that is not from the STL
 *
 * 
 * BST contains a node, which holds the data itself, and two pointers
 * One pointing to the left, and the other to the right
 * BST automatically sorts the data to its left if smaller, and right if larger
 *
 * @author CAI JIANBO
 * @version 01
 * @date 10/11/2020
 */
template <class T>
class Bst {

public:
/**
 * @brief A node is a structure containing the actual data, and two pointers pointing to another node
 */
struct node {
    T data; // Template data
    node *left; // Node pointer, to be pointed to the left node
    node *right; // Node pointer, to be pointed to the right node
};
    
    /**
     * @brief Default constructor for BST
     */
    Bst();
    // Default constructor
    
    /**
     * @brief Default destructor for BST
     */
    ~Bst();
    // Default destructor
    
    /**
     * @brief To insert an item into the BST
     *
     * @param item - the item to be inserted into the BST
     */
    void insert(T item);
    // Method to insert an item into the BST
    
    /**
     * @brief To traverse and display the BST in order (Left, Root, Right)
     */
    void traversalInOrder();
    // Method to traverse the BST, and print out each node in order
    
    /**
     * @brief To traverse and display the BST pre order (Root, Left, Right)
     */
    void traversalPreOrder();
    // Method to traverse the BST, and print out each node pre order
    
    /**
     * @brief To traverse and display the BST post order (Left, Right, Root)
     */
    void traversalPostOrder();
    // Method to traverse the BST, and print out each node pre order

    /**
     * @brief To search the item in the BST
     *
     * @param item - item to be searched in the BST
     */
    node* search(T item);
    // Method to search for the item in the BST
    
    /**
     * @brief To delete the item from the BST
     *
     * @param item - item to be deleted from the BST
     */
    node* remove(T item);
    // Method to deleted the item from the BST
    
private:
    node* root; // The first node to be inserted into the BST
    void deletion(node* node); // Recursive method to delete the node
    node* minValueNode(node* currentNode); // Recursive method to find the node with the min value
    void insert(T item, node* currentNode); // Recursive method to find a place to insert the item from the current node
    void traversalInOrder(node* currentNode); // Recursive method to traverse the BST in order from the current node
    void traversalPreOrder(node* currentNode); // Recursive method to traverse the BST pre order from the current node
    void traversalPostOrder(node* currentNode); // Recursive method to traverse the BST post order from the current node
    node* search(node* currentNode, T item); // Recursive method to search from the item from the current node
    node* remove(node* currentNode, T item); // Recursive method to remove the item from the BST, from the current node
};

template <class T>
Bst<T>::Bst() { // Default constructor
    root = NULL; // Set the root node to null
}

template <class T>
Bst<T>::~Bst() { // Default destructor
    deletion(root); // Using deletion recursive method to delete all nodes
}

template <class T>
void Bst<T>::insert(T item) { // Method to insert item into the BST
    if (root != nullptr) { // If the room is not a nullptr (it is occupied)
        insert(item, root); // Calls out the recurive method to check the node's left/right pointer to insert the item
    } else { // Else if it's null
        root = new node; // Create a new node, set it as the root
        root->data = item; // Set the data of the root to the item
        root->left = nullptr; // Set the left/right pointer of root to null
        root->right = nullptr;
    }
}

template <class T>
void insert(T item) {
    if (root == nullptr) {
        root = new node;
        root->data = item;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        while (root != nullptr) {
            if (item < root->data) {
                root = root->left;
            } else {
                root = root->right;
            
        }
        root = new node;
        root->data = item;
        root->left = nullptr;
        root->right = nullptr;
    }
}


template <class T>
void Bst<T>::insert(T item, node* currentNode) { // Recursive method to check if the current node is available to be inserted
    if (item < currentNode->data) { // if the item is less than the data of the current node
        if (currentNode->left != nullptr) { // And if the current node's left pointer is pointing to another node
            insert(item, currentNode->left); // Recursively insert the item into the node left of the current node
        } else { // Else if it's null
            node* newNode = new node; // Create a new node pointer
            newNode->data = item; // Set the data of the new node to the item
            newNode->left = nullptr; // Set the left/right pointer of the new node to null
            newNode->right = nullptr;
            currentNode->left = newNode; // Set the left pointer of the current node pointing towards the new node
        }
    } else if (item > currentNode->data) { // Else when the item is more than the data of the current node
        if (currentNode->right != nullptr) { // And if the current node's right pointer is pointing to another node
            insert(item, currentNode->right); // Recursively insert the item  into the node right of the current node
        } else { // Else if its null
            node* newNode = new node; // Set the data of the new node to the item
            newNode->data = item; // Set the data of the new node to the item
            newNode->left = nullptr; // Set the left/right pointer of the new node to null
            newNode->right = nullptr;
            currentNode->right = newNode; // Set the left pointer of the current node pointing towards the new node
        }
    } else { // Else if the item has the same value as the current node, it means that it's a duplicate
        cout << "Duplications are not allowed" << endl; // reject
        return;
    }
}

template <class T>
typename Bst<T>::node* Bst<T>::minValueNode(node* currentNode) { // Method to return the smallest node
    if (currentNode->left != nullptr) { // If the left pointer of the current node is not null
        return minValueNode(currentNode->left); // It means that there is a smaller node, therefore recursively call the left node of the current node
    } else { // Else meaning that there is no more node on the left of the current node
        return currentNode; // It is the smallest node, hence return
    }
}

template <class T>
typename Bst<T>::node* Bst<T>::remove(T item) { // Method to remove the item from the BST
    if (root == nullptr) { // If the root of the BST is null
        return root; // Just return null
    }
    if (item < root->data) { // If the item is less than the root
        root->left = remove(root->left, item); // Set the node of the left side of the root to the temp node to be returned recursively
    } else if (item > root->data) { // If the item is more than the root
        root->right = remove(root->right, item); // Set the node of the right side of the root to the temp node to be returned recursively
    } else { // Else the item is equal to the root's data
        if (root->left == nullptr) { // If the node left of the root is null
            node* temp = root->right; // Create a temp node, and set it to the node on the right of the root
            delete(root); // Delete the root node
            return temp; // Return the temp node
        } else if (root->right == nullptr) { // Else if the node right of the room is null
            node* temp = root->left; // Create a temp node, and set it to the node on the left of the root
            delete(root); // Delete the root node
            return temp; // Return the temp node
        }
        node* temp = minValueNode(root->right); // Create a new node temp, and set it to the min value of the right subtree of the BST
        root->data = temp->data; // Set the data of the root to the data of the temp
        root->right = remove(root->right, temp->data); // Set the right pointer of the root to the temp node to be returned recursively
    }
    return root; // Return the root node
}

template <class T>
typename Bst<T>::node* Bst<T>::remove(node* currentNode, T item) { // Recursive method to remove the item, and adjust the BST accordingly to fill up
    if (currentNode == nullptr) { // If the current node is null, return the current node
        return currentNode;
    }
    if (item < currentNode->data) { // If the item is less than the current node
        currentNode->left = remove(currentNode->left, item); // Set the left pointer of the current node to the temp node to be returned recursively
    } else if (item > currentNode->data) { // Else if the item is more than the current node
        currentNode->right = remove(currentNode->right, item); // Set the right pointer of the current node to the temp node to be returned recursively
    } else { // Else the item is equal to the root's data
        if (currentNode->left == nullptr) { // If the node left of the root is null
            node* temp = currentNode->right; // Create a temp node, and set it to the node on the right of the current node
            delete(currentNode); // Delete the current node
            return temp; // Return the temp node
        } else if (currentNode->right == nullptr) { // If the node right of the root is null
            node* temp = currentNode->left; // Create a temp node, and set it to the node on the left of the current node
            delete(currentNode); // Delete the current node
            return temp; // Return the temp node
        }
        node* temp = minValueNode(currentNode->right); // Create a new node temp, and set it to the min value of the right subtree of the BST
        currentNode->data = temp->data; // Set the data of the root to the data of the temp
        currentNode->right = remove(currentNode->right, temp->data); // Set the right pointer of the root to the temp node to be returned recursively
    }
    return currentNode; // Return the current node
}

template<class T>
void Bst<T>::deletion(node* currentNode) { // Method to delete the nodes recursively
    if (currentNode != nullptr) { // If the current node is not null
        deletion(currentNode->left); // Delete the node left of the current node recursively
        deletion(currentNode->right); // Delete the node right of the current node recursively
        currentNode = NULL; // Set the current node to null
    }
}

template <class T>
void Bst<T>::traversalInOrder() { // Traverse the BST in order
    traversalInOrder(root); // Starting from the root of the BST
}

template <class T>
void Bst<T>::traversalInOrder(node* currentNode) { // Traverse the BST in order recursively (Left Root Right)
    if (currentNode != nullptr) { // If the current node is not null
        traversalInOrder(currentNode->left); // Traverse left
        cout << currentNode->data << " "; // Print the current node
        traversalInOrder(currentNode->right); // Then tranverse to the right
    }
}

template <class T>
void Bst<T>::traversalPreOrder() { // Traverse the BST pre order
    traversalPreOrder(root); // Starting from the root of the BST
}

template <class T>
void Bst<T>::traversalPreOrder(node* currentNode) { // Traverse the BST pre order recursively (Root Left Right)
    if (currentNode != nullptr) { // If the current node is not null
        cout << currentNode->data << " "; // Print the current node
        traversalPreOrder(currentNode->left); // Tranverse left
        traversalPreOrder(currentNode->right); // Then tranverse right
    }
}

template <class T>
void Bst<T>::traversalPostOrder() { // Traverse the BST post order
    traversalPostOrder(root); // Starting from the root of the BST
}

template <class T>
void Bst<T>::traversalPostOrder(node* currentNode) { // Traverse the BST post order recursively (Left Right Root)
    if (currentNode != nullptr) { // If the current node is not null
        traversalPostOrder(currentNode->left); // Tranverse left
        traversalPostOrder(currentNode->right);  // Then tranverse right
        cout << currentNode->data << " "; // Print the current node
    }
}

template <class T>
typename Bst<T>::node* Bst<T>::search(T item) { // Method to search for the item if it's inside the BST
    if (root == nullptr || root->data == item) { // If the root is null, or the data of the root is equals to the item
        return root; // Return the root
    }
    if (root->data < item) { // If the item is more than the data of the root
        return search(root->right, item); // Search the right side of the root recursively
    }
    return search(root->left, item); // Else search the left side of the root recursively
}

template <class T>
typename Bst<T>::node* Bst<T>::search(node* currentNode, T item) { // Method to search for the item recursively
    if (currentNode == nullptr || currentNode->data == item) { // // If the root is null, or the data of the root is equals to the item
        return currentNode; // Return the current node
    }
    if (currentNode->data < item) { // If the item is more than the data of the current node
        return search(currentNode->right, item); // Search the right side of the current node recursively
    }
    return search(currentNode->left, item); // Else search the left side of the current node recursively
}

insert (node* root) {
    node* newNode = newNode
}

#endif /* Bst_h */
