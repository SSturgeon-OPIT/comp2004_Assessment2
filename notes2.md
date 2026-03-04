The Universal Binary Tree Recursion Template
Nearly every binary tree problem reduces to this mental structure.
Think of it as the "tree recursion skeleton."
function solve(TreeNode T)

    if T == NULL
        return BASE_VALUE

    left_result  = solve(T->Left)
    right_result = solve(T->Right)

    return COMBINE(T, left_result, right_result)
That's it.
Every problem just changes two things:
BASE_VALUE
COMBINE(...)
How This Template Solves Your Assignment
Let's plug your problems into it.
Q1a — Count Nodes
BASE_VALUE = 0
COMBINE = 1 + left + right
Meaning:
return 1 + left_result + right_result
Why?
Because each node contributes one.
Q1b — Sum Keys
BASE_VALUE = 0
COMBINE = T->Element + left + right
So mentally:
sum = node_value + left_sum + right_sum
Q1c — Max Key
BASE_VALUE = -1
COMBINE = max(node_value, left_max, right_max)
You compare three values.
Q1d — Print Below v
This one still uses the same traversal.
But instead of returning something you:
if T->Element < v
    print
Then continue recursion.
Q2a — Height
Template becomes:
BASE_VALUE = -1
COMBINE = 1 + max(left_height, right_height)
Important idea:
height(NULL) = -1
So a leaf node becomes height 0.
Q2b — Max Path Cost
Same structure.
BASE_VALUE = 0
COMBINE = node_value + max(left_cost, right_cost)
Meaning:
You always choose the more expensive branch.
Q3 — Tree Comparison
Now the template changes slightly because we have two trees.
function compare(T1, T2)

    if both NULL
        return true

    if one NULL
        return false

    return compare(left children)
           AND
           compare(right children)
For value + structure identical you add:
T1->Element == T2->Element
Q4b — Number of Leaf Nodes
Template again.
if node is leaf
    return 1
Otherwise:
return left_leaf_count + right_leaf_count
The Important Insight
Nearly every tree exam question becomes:
BASE CASE
+
LEFT RECURSION
+
RIGHT RECURSION
+
COMBINE RESULTS
