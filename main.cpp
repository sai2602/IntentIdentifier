// Intent_Identifier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LUT.h"

#define NO_INTENT_FOUND 0
#define FIXED_INTENT_FOUND 1

LUT Standard_LUT_Creator(LUT LUT_Database);
void convert_string_tolower(str* input_string);
bool search_for_city(str& input_string);
void string_padding(str* desired_intent);

int main()
{
    LUT my_LUT;
    int map_size;
    str input_string, desired_intent;
    Keys_Values_type intent;
    bool city_flag;
    
    my_LUT = Standard_LUT_Creator(my_LUT);
    map_size = my_LUT.Number_of_Entries();
    std::cout << "Enter string: ";
    std::getline(std::cin, input_string);

    convert_string_tolower(&input_string);
    intent = my_LUT.Search_SubString(input_string);
    city_flag = search_for_city(input_string);

    switch (intent.size()) {
    case NO_INTENT_FOUND:
        desired_intent = "No Pre-Defined Intent";
        break;
    case FIXED_INTENT_FOUND:
        desired_intent = intent[0];
        break;
    default:
        for (str current_intent : intent) {
            if (current_intent == "Weather") {
                desired_intent = current_intent;
            }
            else if (current_intent == "Calendar") {
                if (desired_intent != "Weather") {
                    desired_intent = current_intent;
                }
            }
            else {
                if (desired_intent != "Weather" && desired_intent != "Calendar") {
                    desired_intent = current_intent;
                }
            }
        }
   }

    string_padding(&desired_intent);

    if (!city_flag) {
        std::cout << "Intent: " + desired_intent << std::endl;
    }
    else {
        std::cout << "Intent: " + desired_intent + " City" << std::endl;
    }
}

/*This method creates a key value pair so as to mimic the data and its labels in the standard train/test dataset
* key:value::text data:label
* @params: LUT (instance of the class which has the map in which the key value pair is stored)
* @return: LUT (updated class instance)
*/

LUT Standard_LUT_Creator(LUT LUT_Database) {
    LUT_Database.Add_to_LUT("weather", "Weather");
    LUT_Database.Add_to_LUT("temperature", "Weather");
    LUT_Database.Add_to_LUT("temp", "Weather");
    LUT_Database.Add_to_LUT("rain", "Weather");
    LUT_Database.Add_to_LUT("sun", "Weather");
    LUT_Database.Add_to_LUT("hot", "Weather");
    LUT_Database.Add_to_LUT("cold", "Weather");
    LUT_Database.Add_to_LUT("cloud", "Weather");
    LUT_Database.Add_to_LUT("wind", "Weather");
    LUT_Database.Add_to_LUT("calendar", "Calendar");
    LUT_Database.Add_to_LUT("meeting", "Calendar");
    LUT_Database.Add_to_LUT("schedule", "Calendar");
    LUT_Database.Add_to_LUT("itinerary", "Calendar");
    LUT_Database.Add_to_LUT("am", "Calendar");
    LUT_Database.Add_to_LUT("pm", "Calendar");
    LUT_Database.Add_to_LUT("today", "Calendar");
    LUT_Database.Add_to_LUT("tomorrow", "Calendar");
    LUT_Database.Add_to_LUT("fact", "Facts");
    LUT_Database.Add_to_LUT("interesting", "Facts");
    return LUT_Database;
}

/*This method converts the given input string (entered by the user) to lower case to ease the string matching process
* @params: pointer to the input string got via std::cin
* @return: none
*/
void convert_string_tolower(str* input_string) {
    for (char& each_char : *input_string) {
        each_char = ::tolower(each_char);
    }
}

/*This method checks if a city name (a set of default cities are defined) is present in the string entered by the user
* @params: a reference to the input string
* @return: bool (true if a city name exists, else false)
*/
bool search_for_city(str& input_string) {
    str possible_cities[] = { "london", "new york", "paris", "new delhi", "shangai", "california", "tokyo", "berlin", "munich" };
        for (str each_city : possible_cities) {
            if (input_string.find(each_city) != str::npos) {
                return true;
            }
        }
    return false;
}

/*This method modifies the string to be displayed so that the output is presented to the user in the desired format 
* @params: pointer to string which is to be displayed
* @return: none
*/
void string_padding(str* desired_intent) {
    if (*desired_intent == "Weather") {
        *desired_intent = "Get Weather";
    }
    else if (*desired_intent == "Calendar") {
        *desired_intent = "Check Calendar";
    }
    else if (*desired_intent == "Facts") {
        *desired_intent = "Get Facts";
    }
    else {
        //Do nothing because no intent was found.
    }
}