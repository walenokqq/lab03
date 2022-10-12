#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <string>

using namespace std;

vector <double> input_numbers(istream& in, size_t count, bool prompt) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
            if (prompt) cerr << "Enter number ";
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in, bool prompt) {

    Input data;
       if (prompt) cerr << "Enter number count: ";

    size_t number_count;
    in >> number_count;

    data.numbers = input_numbers(in, number_count, prompt);

        if (prompt) cerr << "Enter column count: ";
    size_t bin_count;
    in >> data.bin_count;

    return data;
}

vector <size_t> make_histogram (struct Input data) {
    double min ;
    double max;
    find_minmax (data, min, max);
    vector<size_t> bins(data.bin_count);
    for (double number : data.numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * data.bin_count);
        if (bin == data.bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    auto data_size=item_size*item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(reinterpret_cast<char*>(items), data_size);
    return data_size;
}

Input
    download(const string& address) {
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();

       if(curl) {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL,  address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            res = curl_easy_perform(curl);
            if (res)            {
                cerr << curl_easy_strerror(res) << endl;
                exit(1);
            }
        }
                curl_easy_cleanup(curl);
    return read_input(buffer, false);
}


int main(int argc, char* argv[]){
   Input input;
    if (argc > 1) {
        input = download(argv[1]);
    }
     else {
        input = read_input(cin, true);
    }

    // Обработка данных
    const auto bins = make_histogram(input);

    // Вывод данных
    show_histogram_svg (bins);


    return 0;
}
