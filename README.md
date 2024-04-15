# MST Node Railway
 
The project is based on creating a solution for a railway network, where the task is to find the lowest cost connection between the
nodes. Every node constitutes a node and every railway is an undirected
weighted cost between two neighbouring nodes. For instance if we make
the assumption that A is a node the cost of reaching the node of V would
have the same cost as V to A. By a traversal of the tree we must be able to
reach all railways and all the nodes.
Our Problem is simply to find the cheapest way from a Node to another,
the complexity is introduced when we now must find the cheapest way
between all the nodes in our supply. By implementing prim's algorithm we
introduce a methodical way of locating, saving and computing the
cheapest and most effective way. As in with every software consistency is
the largest benefactor, The solution must be able to compute regardless of
the number of nodes or the size of the graph.
There are a few problems that come to mind. First of, which one of the
possible algorithm should be used? Prim uses the approach of selecting a
random node at first and then expanding out only taking paths that are
currently reachable after each new node is added.
Prim's algorithm prioritizes taking the smallest edge first if there are
multiple choices. Kruskal's take a different approach where it takes the
smallest edge no matter if the edge is currently reachable or not. When
using Kruskal's algorithm it is crucial to check for cycles as you are not
”following” any path like with Prims, although Prim also requires you to
check for cycles, but it just doesn’t happen to the same extent.
To find a rhythm and thereby complete the project, systematic approach
has to be conducted:
1. Research possible algorithms and study them thoroughly.
2. Devise a plan of implementation by either visually or theoretically
applying the algorithm, choose an algorithm by following the node
structure in the test files.
3. Implement the solution based on the research and architecture
chosen.
Both of the algorithms provide a solution to this problem and the both
consequently use a greedy approach to solve the problem. The solution
should contain a list of the edges that are to be included in the minimum
spanning tree, in such a way that the cost is at a minimum, no cycles
should exist, no node should be ignored and that the appropriate nodes
are connected. If nodes or edges are found to be isolated, There is either a
problem of the way the implementation was devised, or the structure of
the in-file is somehow problematic.

The algorithm that was chosen to solve this problem is Kruskal's. Kruskal's
algorithm is a greedy algorithm in nature, which should have the tendency
to strive for what it values the most, in this case being the lowest cost
node. Prims has it advantages such as being faster if the number of edges
is greater in relation to the amount of nodes, this is because it wont have
to check all the edges if it already has taken the cheapest one. However
Kruskals can perform quite well if the sorting can be done in linear time or
if the nodes are already sorted. I believe Kruskals is an easier approach
since you don’t have to follow the rule to only expand from already visited
nodes. You are more freely picking nodes as long as they don’t create a
cycle.
Selection sort is simple, rapidly coded and debugged and easy to analyze.
Although there are faster methods to sort, selection sort is sufficent and
because of it’s simplicity it was a viable choice.
Kruskal's algorithm can be explained in a few simple steps.
V1: First, pick out the cheapest node connection. This is achieved by
sorting the nodes and their costs in an ascending order, thus you will have
to cheapest nodes at the top of the list. Selection sort was used to sort the
nodes and their costs in an ascending manner.
V2: Secondly, put these connected nodes into sets, the sets are used to
keep track of which nodes have already been visited as to not make a
cycle.
If the nodes already belong to the same set then that means they will
create a cycle if taken, thus we ignore this node connection.
V3: Third, pick the second next node connection which neither creates a
cycle and where a maximum of 1 out of the 2 nodes should have been
previously visited. If the 2 nodes have already been visited it will create a
cycle. If the second next connection does not fulfill this criteria, we check
the third node connection. If the third node connection fulfills the criteria,
we add it to out set of visited nodes and keep track of costs. And we
continue by following these rules untill all the nodes have been checked.
Consider that both the algorithm of Kruskal and the algorithm of Prim will
produce the same unique MST if all edge weights are unique. If edge
weights are not unique, there may be more than one MST. Nonetheless,
inserting arbitrarily small weights to the borders will require Kruskal and
Prim to create the correct MST for this purpose, for example by having a
numerical label and applying a number of times to the edge of the edge
weight mark. This addition of arbitrarily low weights corresponds to the
ordering of the edges to be investigated in some way. Therefore, edge
searches are ordered to produce both algorithms for a particular graph's
MSTs. The software starts with taking a file as input, this file is then opened
and read word by word ignoring possible blank letters. When reading the
first data that comes in, the software will store that data as “possible
nodes”, it will then continue storing this data until it stumbles upon a node
that has been repeated. When this happens it knows that it should start
storing the data coming after as node to node connection with costs.
However, it is very crucial that the files follow the very specific structure
they have. Changes made to the graph file structures can result in
unexpected behaviour. Data is stored in arrays with specific indexes to
keep track of connections, e.g A - B = 3 will be stored in nodeConnection[1]
nodeConnection2[1] nodeCost[1], where nodeConnectionisthe first node,
nodeConnection2 is the connected node and nodeCost is the cost for that
specific path. Since it’s not possible to use strings as array indexes, we take
indexes from the node list in the file, not the connections. These indexes
can be used to the translate an index to the corresponding string when
writing to file.
```
<int x = std::distance(nodes,
std::find(nodes, nodes + counterNode,
word));>
```
We use the distance in the algorithm library to determine the index of a
node. E.g the letter A may be at index 3, when then use this number 3
instead of the letter A, we then use this number 3 to retrive the letter A for
output.
```
<output << nodes[x]......> ”nodes[x] stores the
strings and ”x” is the variable used to pass
on the index for the node”
```
The software also keeps track of counters to know where the array will end
so as to not cause an overflow or retrieve invalid data. After having filled
the arrays with data, they are sent through a function that uses
selectionsort to organize the costs from low to high. This data is then
passed onto the finally function that checks each connection one by one
from low to high and if they fulfill the previously mentioned criteria in V3,
they will be added to a sets which tells us whether the node has been
visited or not.
```
<unions(x, y);> ”x and y are the connected
nodes being added to the set”
```
Then the software will create an output file called Answer.txt and fill it’s
MST result into.
Analys av implementationen
The Algorithm performed very closely as expected if not exactly as
expected, this is thanks to having planned an implementation beforehand.
Just like priority queue the array is sorted from lowest to highest with
increasing index, the sorting is done with selection sort which has the time
complexity of (E^2).
Selection sort pseudo, e.g if we have list containing the values
”3 - 2 - 5 – 7” and we want to sort the list from left to right in ascending
order. We first look at the first value in the list which is 3 and store it’s
index. We then check the value after 3 which is 2. Since 2 is lower than 3
we store the index of 2, then we check if the value following 2 ( 5 and 7)
are lower than 2. If 2 is still the lowest then we swap the index of 2 and 3.
Which should give us a list that looks like this; ”2 – 3 – 5 – 7”. Since we
have moved the lowest value to the first index [0] we can continue on the
second index [1] which contains the number 3 and look if we find a lower
value further to the right on the list, if we find a lower value we swap their
index as done before, if not we keep the number 3 in the same index and
jump to third index [2] and attempt finding anything that might be lower
than it and swap indexes if we do find anything lower. Repeating this untill
reaching the end of the list will result in a sorted list in an ascending order
from left to right. In worst case we would have to compare every value and
replace it’s index, thus giving us the time compexity O(E^2).
Kruskals algorithm is done inside a while loop, that loops aslong as there
are connections that have not been visited. Since this is a linear loop, it
gives us the time complexity of O(E). However inside the while loop we
have a find function that attempts finding the parent of a node to check if
the node already belongs to the set, in worst case this find function will
have a time compexity of O(V), though its called twice in the if statement,
so it becomes O(2V). The while loop also contains a union function which
adds a node to the set, the time complexity of this is in worst case O(2V) as
it calls the find function previously mentioned, twice.
The while loop of O(E) calls some functions which both have give a total of
O(4V), (find is called 2 times in the If statement and 2 times in the union
function). O(4V) can be said to be the same thing as O(V).
So we have O(E) from the while loop * O(V) from the functions.
If E and V have the same size, as in same amount of edges as nodes, we
can write E*V as O(E^2) or O(V^2) (only in the cases where E and V are the
same value).
Writing the while loop time complexity as O(E^2) and the selection sort
also as O(E^2) gives us a total time complexity of O(2(E^2)) this can be
written as O(E^2).
However if we take a complete graph we can have at most V^2 of edges,
(V^2) = (E).
Taking this into mind would give us in the while loop O(V^2 * V), ”V^2 has
replaced ”E”. This totals O(V^3), although the selection which has the time
complexity O(E^2) swapped with V^2, would give us O((V^2)^2). This
calculation was to show that selection sort will remain the biggest time
complexity, thus only it is needed to determine the final time complexity.
The final time complexity for my kruskal implementation is O(E^2).

