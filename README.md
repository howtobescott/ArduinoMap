CMPUT 275 Wi2020
Assignment 2 Part 2
Scott CHU ID: 1570527
Simon CHEN ID: 1574384
*------------------------------------------------------------------------------------------------*

Included Files:
/client:
- client.cpp
- consts_and_types.h
- draw_route.cpp
- draw_route.h
- lcd_image.cpp
- lcd_image.h
- map_drawing.h
- map_drawing.cpp
- serial_handling.cpp
- serial_handling.h
- makefile

/server:
- digraph.cpp
- digraph.h
- dijkstra.cpp 
- dijkstra.h
- edmonton-roads-2.0.1.txt
- heap.h
- serialport.cpp
- serialport.h
- server.cpp
- wdigraph.h
- makefile

- README
- tests (folder)

Arduino Wiring Instructions:
Mount the TFT display on the Arduino just like with Assignment 1

Joystick (same as with assignment 1)
VRx <--> A8
VRy <--> A9
SW  <--> Digital Pin 53
GND <--> GND
+5V <--> 5V

Two pushbuttons for zoom. They are initialized in the code with internal pullup
resistors. So for each, one side is connected to GND and the other to a digital
pin.

Zoom Out Button <--> Digital Pin 47
Zoom In Button  <--> Digital Pin 45

Running Instructions:
- Navigate into "client" directory
- run <arduino-port-select> <1> <1>
- run <make upload>
- Navigate into "server" directory
- run <make server>
- run <./server>

Program Description:
A server and client is implemented. The arduino client will allow users to select two points on a map of edmonton using the tft display and joystick controls along side with 2 buttons for zoom in/out. The arduino will send a request to the desktop client which will run a dijkstra algorithm to find the shortest path. The two will then use a finite state machine communication program to exchange the waypoints of the shortest path and allow the arduino to print the shortest path on the map.

