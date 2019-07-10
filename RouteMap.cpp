/*
Name: Stanley Lim
Takes in a .csv file containing names of cities on the first line, separated by commas
and available destinations from that city on the second line, separated by - and commas.
After reading the .csv file, it computes the shortest available path from origin to 
destination, stored as City* data type, and prints out the path to the console.
 */
#include "RouteMap.hpp"
#include "City.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <stack>
#include <vector>

RouteMap::RouteMap(){};

//destructor. it should delete all the new City* objects but i dont know how to do that :(
RouteMap::~RouteMap()
{
    //City* deletecities = 
}

bool RouteMap::readMap(std::string input_data)
{
    std::ifstream data_file(input_data);    //ifstream variable for the .csv file
    std::string temp_data;                  //temp data for the first line of data
    std::string temp_data_2;                //temp data 2 for the second line of data

    //getting the cities(first line)
    getline(data_file, temp_data);
    
    //getting the adjacent cities(second line)
    getline(data_file, temp_data_2);

    //cities_ is the vector of all the city* objects

    //###############################################################

    //temp variable for the adjacents of the cities when separating the .csv file
    std::string adjacents;    

    //adjacent_cities_ is the vector of all the adjacents
    std::string origins;

    //stringstream to help parse the city line
    std::stringstream origin_cities(temp_data);

    //stringstream to help parse the adjacent line
    std::stringstream adjacent_cities(temp_data_2);

    //allocating memory for the new city objects created from the .csv file
    City* current_city;

    //while there are still cities on the first line, do all this
    while(getline(origin_cities, origins, ','))
    {
        //makes a new city whenever it sees a city in the .csv file, and calls
        //the parameterized constructor when making a new city, naming it the 
        //origins variable, which is the name of the city
        current_city = new City(origins);


        //std::cout << current_city -> nameOfCity() << std::endl;

        //pushes the new city onto the vector of cities
        cities_.push_back(current_city);
    }

    //while there are still adjacent cities in the second line, do this
    while(getline(adjacent_cities, adjacents, ','))
    {
        //gets the city before the dash and puts it into a city* variable
        City* origincity = getFirstCity(adjacents.substr(0, adjacents.find('-')));

        //gets the city after the dash and puts it into a city* variable
        City* secondcity = getFirstCity(adjacents.substr(adjacents.find('-') + 1));

        //adds adjacent city for every origin city
        origincity -> addAdjacent(secondcity);

        //std::cout << origincity -> nameOfCity() << " -> " << origincity -> checkAdjacents()[0] << std::endl;
    }
    return true;
}

//separates city before dash and city after dash
City* RouteMap::getFirstCity(std::string adj)
{
    for(int i=0;i<cities_.size();i++)
    {
        //puts the correct adjacent city to the city vector of the same name.
        //this makes sure that the origin city has the correct adjacent city
        if(cities_[i] -> nameOfCity() == adj)
            return cities_[i];
    }
}

//returns city at position
City* RouteMap::getCity(size_t position)
{
    return cities_[position];
}

/*
tries to find a route from origin to destination
if found, prints it and returns true.
if no found, returns false
 */
bool RouteMap::isRoute(City* origin, City* destination)
{
    //creates a stack that will store the path to destination
    std::stack<City*> path_to_city;

    //pushes origin on top of stack, then marks it visited
    path_to_city.push(origin);
    path_to_city.top() -> changeVisited();//marking it visited

    //std::cout << origin -> nameOfCity();

    //if stack is empty, then there is no route. if top of stack is destination, path is found
    while(!(path_to_city.empty() or path_to_city.top() == destination))
    {
        //std::cout << path_to_city.top() -> nameOfCity() << std::endl;

        //if there is no unvisited city from the origin city, then pop the top of stack(backtrack)
        if(getUnvisited(path_to_city.top()) == nullptr)
        {
            // std::cout << "POP: " << path_to_city.top() -> nameOfCity() << std::endl;
            path_to_city.pop();
        }
        //else, it tries the unvisited cities while changing all of them to visited
        else
        {
            path_to_city.push(getUnvisited(path_to_city.top()));
            path_to_city.top() -> changeVisited();
        }
    }

    //is there is no path, return false
    if(path_to_city.empty())
        return false;

    //if the city on top of stack is destination, return true and prints out the stack in reverse
    else
    {
        printReverse(path_to_city);
        return true;
        std::cout << std::endl;
    }
}

//checks if the city is visited or not
bool RouteMap::isVisited(City* current_city)
{
    std::vector<City*> adj = current_city -> checkAdjacents();
    for(int i=0;i<adj.size();i++)
    {
        if(adj[i] -> check_if_visited())
        {
            return true;
        }  
    }
    return false;
}

//looks for unvisited cities. if there is no unvisited city,returns nullptr
City* RouteMap::getUnvisited(City* current_city)
{
    std::vector<City*> adj = current_city -> checkAdjacents();
    for(int i=0;i<adj.size();i++)
    {
        if(!adj[i] -> check_if_visited())
        {
            return adj[i];
        }  
    }
    return nullptr;
}

/*takes in the stack of the path that you can take from origin to destination.
after that, it creates a temporary stack to print the path in reverse. push everything
from first stack to temp stack. after everything is on temp stack, prints the top
of the stack, then pops the top. keep iterating until stack is empty
*/
void RouteMap::printReverse(std::stack<City*>& stack)
{
    //makes temp stack
    std::stack<City*> temp;

    //pushes everything on stack to tempstack
    while(!stack.empty())
    {
        temp.push(stack.top());
        stack.pop();
    }

    //print out the city on top of temp stack (origin city)
    std::cout << temp.top() -> nameOfCity();
    temp.pop();

    //prints out everything on top of the stack with -> then pop it to get the next city in the path
    while(!temp.empty())
    {
        std::cout << " -> " << temp.top() -> nameOfCity();
        temp.pop();
    }
    std::cout << std::endl;
}
