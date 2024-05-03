# push_swap

Push swap is a 42 project where the aim is to write an algorithm that sorts a 'stack' of integers using a second stack.  There are a set of legal operations that create some limitations.

> sa (swap a): Swap the first 2 elements at the top of stack a.\
Do nothing if there is only one or no elements.\
sb (swap b): Swap the first 2 elements at the top of stack b.\
Do nothing if there is only one or no elements.\
ss : sa and sb at the same time.\
pa (push a): Take the first element at the top of b and put it at the top of a.\
Do nothing if b is empty.\
pb (push b): Take the first element at the top of a and put it at the top of b.\
Do nothing if a is empty.\
ra (rotate a): Shift up all elements of stack a by 1.\
The first element becomes the last one.\
rb (rotate b): Shift up all elements of stack b by 1.\
The first element becomes the last one.\
rr : ra and rb at the same time.\
rra (reverse rotate a): Shift down all elements of stack a by 1.\
The last element becomes the first one.\
rrb (reverse rotate b): Shift down all elements of stack b by 1.\
The last element becomes the first one.\
rrr : rra and rrb at the same time.\

My solution is implemented in four stages.

1. Check if the stack A is already ordered.
2. If stack A < 25 elements push all but 3 (including max element) to B.  Sort 3 elements left in A.
    Else, push elements less than median in A, to B, or rotate A if over median, while stack A larger than len stack A / 2. Repeating until A is empty.
4. Push largest element back to A.
3. While B > 0 insert elements from B to A with the optimal (minimal) number of moves.

The optimal insert assigns a score to each element in B based on the number of moves in both A and B to move the B value on top of the largest value in A smaller than itself.  The operation with the minimum score is then carried out.
