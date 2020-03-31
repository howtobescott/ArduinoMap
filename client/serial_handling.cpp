//Readline buffer function templated from eClass used here.

#include "serial_handling.h"

extern shared_vars shared;
// current number of chars in buffer, not counting null terminator
uint16_t buf_len = 0;
const uint16_t buf_size = 256;
// input buffer
char* buffer = (char *) malloc(buf_size);


bool readline (String& line, int timeout = 1000) {
  int start = millis();
  buf_len = 0;
  buffer[buf_len] = 0;

  while ((millis() - start) < timeout) {
    if (Serial.available()) {
        // read the incoming byte:
        char in_char = Serial.read();

        // if end of line is received, waiting for line is done:
        if (in_char == '\n' || in_char == '\r') {
          // now we process the buffer
          line = String(buffer);
          return true;
        }
        else {
          // add character to buffer, provided that we don't overflow.
          // drop any excess characters.
          if ( buf_len < buf_size-1 ) {
              buffer[buf_len] = in_char;
              buf_len++;
              buffer[buf_len] = 0;
            }
        }
    }
  } 
  return false;
}


uint8_t get_waypoints(const lon_lat_32& start, const lon_lat_32& end) {
  // Currently this does not communicate over the serial port.
  // It just stores a path length of 0. You should make it communicate with
  // the server over Serial using the protocol in the assignment description.

  // for now, nothing is stored
  shared.num_waypoints = 0;

  String line; 

  //Sending initial request to the server.
  Serial.print("R ");
  Serial.print(start.lat);
  Serial.print(" ");
  Serial.print(start.lon);
  Serial.print(" ");
  Serial.print(end.lat);
  Serial.print(" ");
  Serial.println(end.lon);
  Serial.flush();

  //10 second time out for reading N
  if (readline(line, 10000)) {
    //Recieving size of path
    if (line[0] == 'N') {
      shared.num_waypoints = line.substring(2).toInt();
      Serial.println("A");

      //Reading in the waypoints from the server
      for (int16_t i = 0; i < shared.num_waypoints; i++) {

        //Reading way point
        if (readline(line)) {
          if (line[0] = 'W') {
            
            //Getting waypoint and storing it in shared.waypoints array, sending acknowledgement
            line = line.substring(2);
            int spaceIndex = line.indexOf(' ');
            int32_t lat = line.substring(0, spaceIndex).toInt();
            int32_t lon = line.substring(spaceIndex+1).toInt();
            shared.waypoints[i] = lon_lat_32(lon, lat);
            Serial.println("A");
          }
          else {
            return 0;
          }
        }
      }
      return 1;
    }
    else {
      return 0;
    }

  }

  return 0;
}
