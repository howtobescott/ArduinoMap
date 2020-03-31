#include "draw_route.h"
#include "map_drawing.h"

extern shared_vars shared;

void draw_route() {
  for (int16_t i = 1; i < shared.num_waypoints; ++i) {

    //Convert lat and lon to map coords of next/current waypoint
    xy_pos currentCoordinate;
    currentCoordinate.x = longitude_to_x(shared.map_number, shared.waypoints[i - 1].lon);
    currentCoordinate.y = latitude_to_y(shared.map_number, shared.waypoints[i - 1].lat);

    xy_pos nextCoordinate;
    nextCoordinate.x = longitude_to_x(shared.map_number, shared.waypoints[i].lon);
    nextCoordinate.y = latitude_to_y(shared.map_number, shared.waypoints[i].lat);


    //Drawing....
    shared.tft->drawLine(currentCoordinate.x - shared.map_coords.x,
                         currentCoordinate.y - shared.map_coords.y,
                         nextCoordinate.x - shared.map_coords.x,
                         nextCoordinate.y - shared.map_coords.y,
                         0xFF033E);
  }
}
