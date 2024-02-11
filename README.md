# C++ Interactive Linked List Console Simulator

This is an interactive console-based simulator for understanding and visualizing doubly linked list data structures. The simulator provides a simulation for users to interact with and manipulate linked list nodes, facilitating a deeper understanding of data structure concepts.

## Run using MinGW

To run this  program, you will need to have the MinGW development environment installed on your machine. Once you have you can simply run

```bash
mingw32-make
```
This command will execute the default target in the `makefile`, which is all rule based on the provided `makefile`. This rule compiles all source files and links them into an executable.

![Sample Console](./doc/images/console.png?raw=true)
_Console Simulator_

## Key Components

**LineList/SatirListesi Node Class:** This component represents `Single Linked List`. The core building block of the linked list structure. Each node represents a data element in the list. The constructor initializes the head pointer with a unique approach, creating a head node containing the value -1 to serve as a separator and starting point.

![SatirListesi Node](./doc//images/node.png?raw=true)
_SatirListesi Node_

**AdministratorList/YoneticiListesi Class:** This component represents `Doubly Linked List`. This class manages the SatirListesi nodes, providing functionality for calculating averages of stored data and arranging nodes in ascending order based on these averages. The class enables dynamic sorting and navigation within the linked list structure, enhancing user interaction and understanding of data organization principles.

**Menu Interface:** Upon running the program, users are presented with a menu allowing them to navigate through the AdministratorList nodes, view the content of selected LineListesi objects, and perform various operations.

**Navigation Controls:** Users can move between nodes in the AdministratorList using `z` and `c` keys. The content of the selected LineListesi is displayed downward from the menu, allowing easy visualization.

**Dynamic Display:** The console interface dynamically updates to display 8 AdministratorList nodes at a time. Users can browse the entire list iteratively using `a` and `d` keys. For example, if there are 18 nodes in total, nodes 0-7 will be shown initially. When the user presses the `d` key, nodes 8-15 will appear on the screen, and when the next `d` key is pressed, nodes 16-17 will appear on the screen.

**Node Deletion:** Users can remove selected nodes from the AdministratorList using the `p` key. Additionally, pressing the `k` key deletes a random node from the RowList of the selected node, with the average recalculated and ManagerList updated accordingly.

## List of Commands

Here is a list of terminal commands and their corresponding functionalities in the program:

1. `z` key: Move to the previous node in the AdministratorList.
2. `c` key: Move to the next node in the AdministratorList.
3. `a` key: Browse to the previous set of 8 nodes in the AdministratorList.
4. `d` key: Browse to the next set of 8 nodes in the AdministratorList.
5. `p` key: Delete the selected node from the AdministratorList.
6. `k` key: Delete a random node from the LineList of the selected node in the AdministratorList.

## Documentation

This shows some of how to use the commands and console simulator

![Simulation](/doc/images/simulation.gif)
_Console Simulator_