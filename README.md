# move_bot
move a turtle bot from a set of positions till the program is killed
package.xml file is the initial package created after creating the cpp code for turtlebot movement
amcl1.launch file is taken from the standard launch file and the map_file argument is added where it takes the map.yaml from turtlebot3_navigation folder.
One can also create a map.yaml file by running the turtlebot_teleop_key.launch with gmapping in an empty world and save the map using map_server map_saver commands.
movement.7z contains the move_bot package as an compressed file.
The move_bot cpp uses action lib that connects to the server (here amcl.launch acts as the server that communicates between move_base file, move_bot program and the simulators namely rviz and gazebo)
