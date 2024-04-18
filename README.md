- Done with the turkish algorithm
- Use of singly linked list (memory adress of 'next' and of 'target' in stack A, NULL terminated and with no 'previous')

The step by step process I chose:
1. Check for invalid arguments or numbers already in order (parsing) and I put them in stack A at the same time  
2. Call for functions to manage the case of receiving only 2 and 3 numbers  
3. Find median (a bit subjective in my opinion)
4. Push first two nodes from stack A to B
5. Check if every node pushed to stack B is bigger than the median

      -> If it is, rotate stack B to put it at the end of list
7. Stop pushing to stack B when there are 3 numbers left in stack A
8. Order those 3 numbers
9. Set index or individual cost to be the first element of the stack (considering when it's better to rotate or reverse rotate)
10. Set target in A for each element of stack B (look for the closest bigger number to the stack B number in the stack A)
11. Find cost for both stacks (with the index value I calculate how many moves it takes to put every element AND their target at the top of each stack -> don't forget you can rr and rrr)
12. Choose the best move = element with lowest cost
13. Do the most optimal movements to get the best node in B and its target in A to the top of the stacks
14. Push the best node in B to A
15. Repeat process from step 9 until stack B is empty
16. Set the 'index' again for stack A
17. Find the smallest number
18. Put it at the top of the stack
