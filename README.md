# C-finding-route-in-a-map
 Takes in a .csv file ("data.csv" as default) containing names of cities on the first line, separated by commas and available destinations from that city on the second line, separated by - and commas. After reading the .csv file and asking user for their origin and destination, it computes the shortest available path from origin to destination and prints out the path to the console.
To compile: g++ City.cpp RouteMap.cpp main.cpp -o main.
To run executable: ./main
