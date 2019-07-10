/*
Name: Stanley Lim
Takes in a .csv file containing names of cities on the first line, separated by commas
and available destinations from that city on the second line, separated by - and commas.
After reading the .csv file, it computes the shortest available path from origin to 
destination, stored as City* data type, and prints out the path to the console.
 */
#ifndef CITY_HPP
#define CITY_HPP
#include <string>
#include <vector>

//city class interface. it stores the information of each city object.
//stores: name of the city(string), adjacent cities(vector with City type objects bc each adjacent city is also a City object
//also stores whether the city is visited or not
//and counts the number of adjacent cities
class City
{
    public:

        //constructor
        City();
        
        //parameterized constructor
        City(std::string origin_city);

        //returns yes if it had been already visited, no otherwise
        bool check_if_visited();

        //returns name of the city 
        std::string nameOfCity();

        //returns the adjacent cities as a vector with type City* objects
        std::vector<City*> checkAdjacents();

        //changes whether the city had been previously visited
        void changeVisited();

        //adds cities that are adjacent to the current origin city
        void addAdjacent(City* adj);    

        //returns how many adjacents there are
        int howManyAdj(City* mycity);

    //stores information of each City* object. stores name of city, adjacents, whether visited and how many adjacents
    protected:

        std::string origin_city_;

        std::vector<City*> adjacents_;

        bool isVisited;

        //iterates once every time it reads an adjacent city
        int countadj = 0;

};

#endif  //end City class
