# Singly Linked List Implementation in C++
**File:** `node.cpp`
## Question
Implement a singly linked list in C++ using classes and pointers. The program should support insertion at the beginning and end, deletion at the beginning and end, and displaying all the nodes.

## Description
This program implements a singly linked list using two classes: `Node` and `List`.

The `Node` class stores the data and a pointer to the next node. The `List` class manages the linked list and provides different operations to insert, delete, and display nodes.

## Classes Used

### 1. Node Class
Each node contains:
- `data` — stores an integer value.
- `next` — stores the address of the next node.
- `Node(int value)` — initializes the node with a value and sets `next` to `NULL`.

### 2. List Class
The list contains:
- `head` — points to the first node.
- `tail` — points to the last node.
- `List()` — initializes both `head` and `tail` to `NULL`.

## Operations Implemented

### 1. push_front(int val)
Inserts a new node at the beginning of the linked list.

- Creates a new node.
- If the list is empty, both `head` and `tail` point to the new node.
- Otherwise, the new node points to the current head, and `head` is updated.

### 2. pop_front()
Deletes the first node of the linked list.

- Checks whether the list is empty.
- Stores the current head in a temporary pointer.
- Moves `head` to the next node.
- Deletes the previous first node.

### 3. push_back(int valu)
Inserts a new node at the end of the linked list.

- Creates a new node.
- If the list is empty, both `head` and `tail` point to the new node.
- Otherwise, the current tail points to the new node, and `tail` is updated.

### 4. pop_back()
Deletes the last node of the linked list.

- Traverses the list to find the node before the tail.
- Disconnects the last node.
- Deletes the previous tail.
- Updates `tail` to the new last node.

### 5. printll()
Displays all the nodes of the linked list.

- Starts from `head`.
- Traverses the list using a temporary pointer.
- Prints each node's data until the pointer becomes `NULL`.
- Prints `Null` at the end.

## Main Function
The program performs the following steps:

1. Creates a `List` object named `l1`.
2. Inserts `1` at the beginning.
3. Inserts `2` at the beginning.
4. Inserts `3` at the beginning.
5. Displays the linked list.
6. Deletes the first node using `pop_front()`.
7. Displays the updated linked list.

## Expected Output

```text
3->2->1->Null
2->1->Null
```

## Concepts Practiced
- Classes and objects
- Pointers
- Singly linked lists
- Dynamic memory allocation using `new`
- Memory deallocation using `delete`
- Insertion and deletion
- Linked list traversal

## Language
C++