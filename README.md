# OOP_lab5

Lab5, polymorphism

## Exercise 1

### Problemsolving

## Exercise 2

Implementation of the bubblesort algorithm, which iterates through the list and compares adjacent elements and swaps if needed.

### Problemsolving

I used static member functions to be able to call the functions without any object instances. Size_t is used to guarentee that it can hold the largest size possible of any container.

## Exercise 3

Implementation of a template managed doublelinkedlist container. I created an element class and an container class.

Each element object holds data of the template type, aswell as pointers to previous and next. It also holds member functions like getters and setters for each member variable.

Container object manages the doublelinkedlist. It keeps track of head and tail and size of the container. The class has methods for adding and removing elements(front,back, or any specific location), checking size, clearing container and printing.

### Problemsolving

Managing memory was abit of hassle here since there was alot of edge cases. Ie when head and tail shares the same pointers. I had problems with the D-tor of the container class, since I at first had it delete head and tail pointers, which sent the constructor into a recursive stack mess. It was then I instead used the clear() member function to actively delete the entire linked list to assure there was no memory leaks.
