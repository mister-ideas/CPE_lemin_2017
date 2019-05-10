# Subject
On the standard input, your program must receive an anthill description the following way: first, the num-ber of ants, then the rooms and their position and finally the tunnels (defined by the rooms they connect).

The rooms’ coordinates will always be whole numbers. Please note that it is possible to insert comments by using “#” and commands by using “##”. ##start indicates the next room is the anthill entrance, and ##end indicates the next room is the anthill exit. Any unknown commands will be ignored.

The objective of your program is to find the quickest way to make the ants cross over the anthill. To do so, each single ant need to take the shortest route (and not necessarily the easiest), whithout walking on its peers, and avoiding traffic jams.

At the beginning of the game, all of the ants are in the anthill entrance.T he goal is to lead them to the exit room, in a minimum amount of laps. Each room could contain a single ant at a time (except ##start and ##end, which can contain as many as needed). 

With each lap, you can move each ant only once by following a tunnel (if the receiving room is cleared). 

You must show the result on the standard output, in this order: number_of_ants, rooms, tunnels and thenfor each lap, a series of Pn-r where n is the number of the ant, and r the name of the room it gets into. In the output, you must display a comment indicating the part that will follow.

# Authorized functions
* read
* write
* malloc
* free
* getline

# Building
$ make

# Usage
$ ./lem_in < [file_path]

# Mark
**12,63/20**
