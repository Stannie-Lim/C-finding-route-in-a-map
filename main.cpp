#include "RouteMap.hpp"
#include "City.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>

int main()
{
    RouteMap mymap;
    City mycity;
    mymap.readMap("data.csv");
    // std::cout << mymap.getCity(0)->nameOfCity() <<  "##################" << mymap.getCity(4)->nameOfCity() << mymap.getCity(0)->checkAdjacents()[0] ->nameOfCity();
    mymap.isRoute(mymap.getCity(0), mymap.getCity(5));
    //std::cout << mymap.getUnvisited(mymap.getCity(0))->nameOfCity();
    //mymap.getCity(1)->changeVisited();
    //std::cout << '\n' <<mymap.getUnvisited(mymap.getCity(0))->nameOfCity();
}
