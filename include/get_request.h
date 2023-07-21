#include <iostream>
#include <curl/curl.h>
#include <iostream>
#include <string>

using namespace std;

class GetRequest{
    public:
        // Constructor for GetRequest class
            // First INIT curl_easy, if failed print runtime error.
            // Then setopt for a call back function that is a write function
            // Then setopt to write data as a string to variable response
        GetRequest(){
            curl = curl_easy_init();
            if (!curl) {
                throw std::runtime_error("Failed to initialize libcurl");
            }
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        }
        // Destructor clean up easy curl
        ~GetRequest() {
            curl_easy_cleanup(curl);
        }
        // Preforms the GET request 
        string performGet(const string& url) {
            response.clear();
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                throw runtime_error("curl_easy_perform() failed: " + string(curl_easy_strerror(res)));
            }
            return response;
        }
    
    private:
        CURL* curl;
        string response;
        // call back function for when the GET request is performed
            // Calculate the size of the data passed back
            // append the received data to the output string
            // Returns the total size in bytes of the data received
        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
            size_t totalSize = size * nmemb;
            output->append(static_cast<char*>(contents), totalSize);
            return totalSize;
        }
};