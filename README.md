# Udacity-OpenStreetMap-Route-Planning-Project

This repo contains the code for the Route Planning project. My own changes were made in the [main.cpp](src/main.cpp) and [route_planner.cpp](src/route_planner.cpp) files in the src-folder. 

<img src="map.png" width="600" height="450" />

## General functionality
The user of this program is asked to input the start and end coordinates of the journey. After this is done, the shortest path between the start and end point is computed by usage of the A*-algorithm. Furthermore the shortest route is displayed inside the map and the distance of it gets computed. <br>

The implementation of the A*-algorithm is done inside the [route_planner.cpp](src/route_planner.cpp) file. The chosen heuristic is given by the euclidean distance to the end point of the route.




## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it
 

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```
Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```




