#include <iostream>
#include "nlohmann/json.hpp"
#include "get_request.h"
using namespace std;
using json = nlohmann::json;
// Class currency for returning the converted values of the currency
class Currency{
    double euros = 1;
    double USD;
    double GBP;
    public:
        // Constructor for Currency class
            // The constructor first INIT GetRequest class then preforms a GET request using curl 
            // from the get_request header file.
            // Then tries to store the values returned from the json file. If fail print error.
        Currency(){
            GetRequest GET;
            string data = GET.performGet("https://api.exchangerate.host/latest");
            json json_data = json::parse(data.c_str());
            try{
                this->USD = json_data["rates"]["USD"];
                this->GBP = json_data["rates"]["GBP"];
            }catch (json::parse_error& e) {
                // JSON parsing error occurred
                cerr << "JSON parsing error: " << e.what() << endl;
            } catch (json::exception& e) {
                // Other JSON-related error occurred
                cerr << "JSON error: " << e.what() << endl;
            }
        }
        // ----------Converting functions----------
        float d_to_e(float dollars){
            return dollars * this->euros;
        }

        float e_to_d(float euros){
            return euros * this->USD;
        }
};