#include "RouteMap.hpp"
#include "City.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

//prints out all available origin cities and asks user for their origin
//takes in no parameters, returns the destination city that user inputs
std::string ask_for_origin()
{
    std::ifstream names_of_cities("data.csv");
    
    //puts the first line of data.csv into vector called "names" ###################
    std::string temp_data;
    getline(names_of_cities, temp_data);
    std::stringstream all_possible_origins(temp_data);
    std::string input_origin;
    std::vector<std::string> names;
    //##########################################################################################

    //asks what origin is and prints out all available cities
    std::cout << "What is your origin? Choose from ";

    //pushes back all origin cities to vector
    while(getline(all_possible_origins, input_origin, ','))
        names.push_back(input_origin);

    //prints out names of cities
    for(int k = 0; k < names.size(); k++)
    {
        if(k == 0)
            std::cout << names[k];
        else
           std::cout << ", " << names[k];
    }

    std::cout << ".\n";

    //asks user which city the origin is, and makes sure that the city exists
    std::string user_input;
    std::cin >> user_input;
    while(!(std::find(names.begin(), names.end(), user_input) != names.end()))
    {
        std::cout << "Not an available origin. Try again!\n";
        std::cin >> user_input;
    }
    names_of_cities.close();

    //returns origin city that user inputted
    return user_input;
}

//prints out all cities except for the origin city and asks what the destination is
//takes in the origin city as a parameter to make sure it doesnt repeat the origin city in the list of available destinations
//returns a string with the name of the city that the user chose as destination
std::string ask_for_destination(std::string input)
{
    std::ifstream names_of_cities("data.csv");

    //makes a vector of the names of the cities, excluding the origin city
    std::string temp_data;
    getline(names_of_cities, temp_data);
    std::stringstream all_possible_origins(temp_data);
    std::string input_destination;
    std::vector<std::string> names;

    //asks user for input for destination
    std::cout << "What is your destination? Choose from ";

    //pushes back all city names to vector except for origincity
    while(getline(all_possible_origins, input_destination, ','))
    {
        if(input_destination != input)
            names.push_back(input_destination);
    }

    //prints out available destination cities
    for(int k = 0; k < names.size(); k++)
    {
        if(k == 0)
            std::cout << names[k];
        else
            std::cout << ", " << names[k];
    }
    std::cout << ".\n";

    //asks user what their destination is, making sure the input exists
    std::string user_input;
    std::cin >> user_input;
    while(!(std::find(names.begin(), names.end(), user_input) != names.end()))
    {
        std::cout << "Not an available destination. Try again!\n";
        std::cin >> user_input;
    }


    names_of_cities.close();
    return user_input;
}

//finds the path from u_origin to u_destination
void find_path(std::string u_origin, std::string u_destination)
{
    RouteMap mymap;
    mymap.readMap("data.csv");

    //putting all the names of cities into vector again
    std::ifstream names_of_cities("data.csv");
    std::string temp_data;
    getline(names_of_cities, temp_data);
    std::stringstream all_possible_origins(temp_data);
    std::string input_origin;
    std::vector<std::string> names;
    
    //pushing the names to vector called names
    while(getline(all_possible_origins, input_origin, ','))
        names.push_back(input_origin);

    //temp variables to get the ID of the user inputting origin and destination cities
    int origin_id;
    int destination_id;

    //looking for the user inputted city IDs 
    for(int i = 0; i < names.size(); i++)
    {
        if(names[i] == u_origin)
            origin_id = i;
        if(names[i] == u_destination)
            destination_id = i;
    }

    //if there is no route from city a to city b, print that there is no path
    if(!mymap.isRoute(mymap.getCity(origin_id), mymap.getCity(destination_id)))
        std::cout << "There is no available path from " << u_origin << " to " << u_destination << ".\n";
    
    else
        mymap.isRoute(mymap.getCity(origin_id), mymap.getCity(destination_id));
}

int main()
{
    //function to ask user for origin
    std::string user_input_origin = ask_for_origin();

    //function to ask user for destination
    std::string user_input_destination = ask_for_destination(user_input_origin);

    //finds the path from user inputted origin and destination
    find_path(user_input_origin, user_input_destination);
}
