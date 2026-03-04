The 4 Binary Tree Recursion Patterns
When you see a tree question, ask:
What type of answer is the function supposed to return?
That tells you the pattern.
Pattern 1 — Accumulation (Count / Sum)
Recognize It When The Question Says
count
sum
total
number of
print all
Examples from your assignment:
count_nodes
sum_keys
numLeafNodes
print_below
Recursion Pattern
solve(node):

    if node == NULL
        return 0

    left  = solve(node->Left)
    right = solve(node->Right)

    return combine(left, right, node)
Combine Step
Usually:
left + right
plus something for the node.
Examples:
Problem	Combine
count nodes	1 + left + right
sum keys	value + left + right
leaf nodes	left + right
Pattern 2 — Maximum / Minimum
Recognize It When The Question Says
max
min
largest
smallest
best
longest
Examples in your assignment:
max_key
height
path_cost
Recursion Pattern
solve(node):

    if node == NULL
        return base_value

    left  = solve(node->Left)
    right = solve(node->Right)

    return combine(node_value, left, right)
Combine Step
Use:
max(...)
Examples:
Problem	Combine
height	1 + max(left, right)
max_key	max(node, left, right)
path_cost	node_value + max(left, right)
Pattern 3 — Boolean Comparison
Recognize It When The Question Says
identical
same
equal
match
check
Examples in your assignment:
structure identical
structure + value identical
Recursion Pattern
compare(T1, T2):

    if both NULL
        return true

    if one NULL
        return false

    return compare(left subtrees)
           AND
           compare(right subtrees)
For value comparison add:
T1->value == T2->value
Pattern 4 — Traversal / Visiting
Recognize It When The Question Says
print
visit
output
traverse
Example from your assignment:
print_below
LevelOrder
Recursion Traversal Pattern
visit(node):

    if node == NULL
        return

    visit(left)

    process(node)

    visit(right)
This produces inorder traversal.
But sometimes processing happens first:
process(node)
visit(left)
visit(right)
That is preorder traversal.
The One Exception — Level Order
Level order is not recursion.
Recognize it when the question says:
level order
breadth first
distance from root
Algorithm:
queue ← root

while queue not empty
    node ← dequeue
    visit node
    enqueue left
    enqueue right
That is BFS.
Quick Recognition Guide
When reading the question, look for these keywords.
Keywords	Pattern
count / sum	Accumulation
max / height / longest	Max pattern
identical / compare	Boolean pattern
print / traverse	Traversal
level order	BFS
Apply This to Your Assignment
Question 1
Function	Pattern
count_nodes	Accumulation
sum_keys	Accumulation
max_key	Max
print_below	Traversal
Question 2
Function	Pattern
height	Max
path_cost	Max
Question 3
Function	Pattern
structure identical	Boolean
identical trees	Boolean
Question 4
Function	Pattern
findMin_K	BST + inorder
numLeafNodes	Accumulation
LevelOrder	BFS
The Ultimate 5-Line Tree Template
If you're unsure, start with this:
solve(node):

    if node == NULL
        return base

    left  = solve(node->Left)
    right = solve(node->Right)

    return combine(node, left, right)
Then adjust the base value and combine step.
That solves most tree recursion problems.
One Last Insight (Very Helpful)
When you see a tree question, mentally ask:
Does the answer depend on
A) every node
B) the best branch
C) comparing two trees
D) visiting nodes
That immediately tells you which pattern to use.

function solve(T):

    if T == NULL
        return base

    left  = solve(T->Left)
    right = solve(T->Right)

    return combine(left, right, T)