/*
Name: Stanley Lim
7/5/2019
Takes in a .csv file containing names of cities on the first line, separated by commas
and available destinations from that city on the second line, separated by - and commas.
After reading the .csv file, it computes the shortest available path from origin to 
destination, stored as City* data type, and prints out the path to the console.
 */
#include "City.hpp"
#include <string>
#include <vector>
#include <stack>

#ifndef ROUTEMAP_HPP
#define ROUTEMAP_HPP

//routemap is derived from city. routemap class stores City* objects and all
//of the information read from the csv file and computes the route from
//origin to destination
class RouteMap: public City
{
    public:

        RouteMap();
        
        ~RouteMap();

        /*takes the .csv file in and separates all the data. first, separates first line and makes a City*
        object from each word on the first line separated by comma and names the new City* object.
        also separates second line and keeps track of all the adjacent cities available from
        the first line*/
        bool readMap(std::string input_data); 

        /*uses a stack to compute the route from origin to destination, if there is one.
        whenever it visits a city, the city gets pushed on the stack, then marks it visited
        if the top of the stack never reaches the destination, it pops the stack(backtrack),
        then goes to the other cities that arent already visited. it keeps doing this until
        the city on top of the stack is the destination, or if stack is empty. if stack
        is empty, then there is no destination and this returns false. if path is found, 
        printreverse is called, and this returns true
        */
        bool isRoute(City* origin, City* destination);

        //returns the pointer of city at position
        City* getCity(size_t position);

        //returns pointer of the city before the adjacent city. ex. "New York-California" returns new york
        City* getFirstCity(std::string adj);

        //checks if the current city had been visited before. if it was visited, it won't go there again
        bool isVisited(City* current_city);

        //returns pointer of city that had not been visited before.
        City* getUnvisited(City* current_city);

        /*takes in the stack of the path that you can take from origin to destination.
        after that, it creates a temporary stack to print the path in reverse. push everything
        from first stack to temp stack. after everything is on temp stack, prints the top
        of the stack, then pops the top. keep iterating until stack is empty
         */
        void printReverse(std::stack<City*>& stack);

    private:
        //a vector of all the City* objects, with all the protected members that are in City class
        std::vector<City*> cities_;
};

#endif
