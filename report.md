Final Report – Library Management System
Course: COMPSCI‑2-39452 Student: Damien Carter Date: May 12, 2025
Introduction and Motivation
The Library Management System was chosen as my final project for COMPSCI-2-39452 because it builds upon the knowledge I gained working on an expense tracker project I completed in my previous course. The expense tracker helped me understand the fundamentals of file handling, data structures, and basic user input/output in C++. The library system extends these concepts by incorporating more advanced data structures like binary search trees and queues while maintaining a manageable scope. Additionally, having previously worked in a library which I enjoyed, the project felt personal and relatable, allowing me to blend practical experience with programming concepts.
Design Rationale
The primary data structure selected for the project is a binary search tree (BST), chosen for its efficient O(log n) lookup and insertion operations. This provided an opportunity to practice manual pointer manipulation while implementing a core data structure commonly discussed in technical interviews.
The Library class serves as a high level controller that integrates the key components: books, members, transactions, and the return queue. By isolating these responsibilities into distinct classes, the system adheres to principles of modular design and separation of concerns. The Queue class, implemented as a simple wrapper around std::queue, provides consistency and a unified interface without over-complicating the implementation.
Subsystem
Responsibility
Book
Data encapsulation for book details; no direct file interaction
BST
Template BST implementation for book storage and retrieval
Queue
Manages pending return requests with basic enqueue/dequeue logic
Library
High-level API coordinating all library operations and I/O

C++ Concepts Demonstrated
The project is structured to showcase several core C++ concepts:
Classes & Inheritance: Implementation of data structures (e.g., BST, Queue) and domain entities (Book, Member).
Pointers & Dynamic Memory Management: Explicit allocation and deallocation of nodes within the BST.
File I/O: Use of <fstream> for persisting book data across sessions.
Sorting & Searching Algorithms: Quick-sort implemented for book listing, demonstrating classic sorting logic alongside BST traversal.
Data Structures: Custom BST and queue implementations, paired with STL containers like unordered_map and vector for member and transaction management.
Smart Pointers: Applied in testing to manage Book objects safely without risking memory leaks.
Challenges and Insights
One of the most significant challenges was balancing complexity with clarity. The rubric emphasized demonstrating multiple C++ concepts without over engineering the solution. For instance, implementing a basic BST allowed for manual pointer manipulation while still maintaining readability and straightforward debugging.
Another challenge involved managing file I/O consistently across different operating systems. Windows uses CRLF line endings, while Unix systems use LF. This caused data inconsistencies when testing the program in mixed environments. To resolve this, I standardized the file format and implemented basic error handling to handle potential discrepancies.
Writing comprehensive unit tests was a valuable exercise. It highlighted subtle logic errors in queue processing and BST insertion that were not immediately apparent during manual testing. Crafting edge cases, such as attempting to borrow a book already checked out or processing returns for nonexistent books, reinforced the importance of defensive programming.
Future Work
Given more time and resources, I would consider the following improvements:
Replacing raw pointers with smart pointers (std::unique_ptr) throughout the project, particularly in the BST implementation, to prevent memory leaks and simplify cleanup.
Adding import/export functionality for book data using CSV or JSON formats, enhancing the program’s utility for larger datasets.
Developing a graphical user interface using a framework to provide a more user friendly interaction model.