/*
Name: Stanley Lim
Takes in a .csv file containing names of cities on the first line, separated by commas
and available destinations from that city on the second line, separated by - and commas.
After reading the .csv file, it computes the shortest available path from origin to 
destination, stored as City* data type, and prints out the path to the console.
 */
#include "City.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <stack>
#include <vector>

//empty constructor
City::City(){}

/*parameterized constructor to set default values for the City type objects.
isvisited = false because the city has not been visited yet*/
City::City(std::string origin_city)
{
    origin_city_ = origin_city;
    isVisited = false;
}
/*returns checks if the current city is visited or not. if it is visited,
the stack will never visit the city again. if it is not visited, it will
visit it then mark it visited*/
bool City::check_if_visited()
{
    return isVisited;
}
//returns name of the current city that we are in
std::string City::nameOfCity()
{
    return origin_city_;
}
//vector of the cities that are available as destination from current city
std::vector<City*> City::checkAdjacents()
{
    return adjacents_;
}
/* whenever we go to a city that had not been visited, this function is called,
marking it visited*/
void City::changeVisited()
{
    isVisited = true;
}
/* while reading the csv file, available adjacent cities are added to the origin city
also keeps track of how many adjacents there are */
void City::addAdjacent(City* adj)
{
    adjacents_.push_back(adj);
    countadj++;
}

int City::howManyAdj(City* mycity)
{
    return countadj;
}
