# ISC Algorithms Final Project
Final project for an Algorithms class.

## Purpose
The purpose of this project is to use a graph database to store simulated data about people’s modern interactions through social media sites and generate personalized recommendations for new friendships to any user. We also use this graph to test whether the theory of N degrees of separation is true for our data. Here is more information about the 6 degrees of separation theory https://www.youtube.com/watch?v=TcxZSmzPw8k

## Overall Description
![example graph](img/example_graph.jpg?raw=true)

In the graph above, we have what could be an example of connections between 10 users. The green user is friends with A, B, C, D and E. A friendship (vertex) also has a weight. This weight represents the friendship intensity between two friend users. 
The green user interacts more with his friend B than, for example, his friend A… and he interacts more with his friend A than his friend C. As users interact with one another, their vertex weight (friendship intensity) is augmented.
We can easily observe how some loops will form, as in: green node→E→I→H→D→green node, or green node→D→G→C→green node.

And all these loops are exactly what we’ll use to give personalized recommendations to each user. In this first mentioned loop, for example, a recommendation could be made for the green node user to be friends with H. However, there’s only one current friend of green node that is directly friends with H, that is D… the only other way in which green node could get to know H is through his connection with E and then through I’s connection with H. For H to be a good friend recommendation for green node, it would be much better if H was friends with two people directly related to green node.

In our example graph, this is true for the following cases:
- green node→D→G→C→green node (G is a good recommendation)
- green node→B→F→C→green node (F is a good recommendation)

And, to determine which of these recommendations is better, we use the weight of the vertices (friendship intensity) involved in the friendship loop. This way, we can conclude that F is a better friend recommendation for green node than G.

Now, for testing wether the theory of N degrees of separation is true for our data, we use the Floyd Warshall algorithm to check the shortest path between all pairs of users. This way, if the shortest path between any 2 users is longer than N degrees, the theory of N degrees of separation is false for our data.

In main.cpp, the database is preloaded with fake data. This fake data looks as follows
![Grafo](img/grafo.jpg?raw=true)

By compiling and running main.cpp, our program is ready to receive instructions after displaying the message "What do you want to do?"

These are some commands that can be used to interact with our program in various ways:

**Recommend friends to fernanda:**
```
recommend fernanda
```
program lists all recommendations, with their relevance coefficient...
```
fernanda recommendations:
carlos,2.74728
pepe,2.6087
```
**Test for 6 degrees of separation in the current graph:**
```
degrees 6
```
program responds whether the theory is correct or not. If not, it indicates the first pair of people for which it found the theory to be false...
```
separation between andrea and hugo is 7
theory of 6 degrees of separation is FALSE
```
**Add 6 to juan's interaction with carlos:**
```
interact juan carlos 6
```
program's response...
```
updated juan's friendship with carlos
```
**Make vero and pepe friends. Initial interaction from vero to pepe as 3 and from pepe to vero as 4:**
```
friends vero pepe 3 4
```
program's response...
```
vero and pepe are now friends
```
**To end the program, just type "exit" or "end"**
