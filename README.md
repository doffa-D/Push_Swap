# Push_Swap


This is a project prompt for a programming assignment in C called "Push_swap". The task is to sort an array of integers using two stacks and a set of instructions. The goal is to write a program in C called "push_swap" which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

The project has several objectives including learning basic algorithms, understanding the concept of complexity, and practicing writing in C language. The project also has several instructions, including writing the code in C, following a set of norms, writing a Makefile, and freeing heap-allocated memory space properly.

There are two stacks named 'a' and 'b', with 'a' containing a random amount of negative and/or positive numbers which cannot be duplicated. The goal is to sort in ascending order numbers into stack 'a'. The set of instructions includes sa, sb, ss, pa, pb, ra, rb, rra, and rrb. These instructions are used to swap, push, and rotate elements within the stacks. The project provides an example of how these instructions work to sort a random list of integers.




In the push swap project, the goal is to sort a stack of integers using a limited set of operations. The challenge is to find the smallest number of moves to achieve this.

To solve this problem, one common approach is to use two stacks: stack A, which contains the initial unsorted list, and stack B, which is initially empty. The algorithm operates by moving elements from A to B in a way that eventually results in B being sorted in descending order, and then moving the elements back to A in the correct order.

One key aspect of a good push swap algorithm is to identify the "best move" to make at each step. There are many possible moves to choose from, and some moves may be more efficient than others, depending on the current state of the stacks. For example, if the top element of stack A is already in the correct position relative to the other elements, then it may not be necessary to move it to stack B and back.

To find the best move, an algorithm may evaluate the potential outcomes of each move and choose the one that results in the smallest number of moves needed to sort the list. This may involve simulating the effect of the move on the stacks, and evaluating the new state of the stacks after the move.

Another important concept in push swap algorithms is the "range" of the current unsorted portion of the list. At each step, the algorithm needs to determine which elements in A need to be moved to B in order to sort them, and which elements can be left in A. One approach is to define a range that identifies the smallest and largest unsorted elements in A, and move those elements to B while leaving the other elements in place. The range is updated as the algorithm progresses, so that the remaining unsorted elements are always within the range. This can help to reduce the number of unnecessary moves and make the algorithm more efficient.
