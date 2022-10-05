#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

vector <double> input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cerr << "Enter number ";
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in, bool promt) {
    if (promt) {
    Input data;
    cerr << "Enter number count: ";

    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter column count: ";
    size_t bin_count;
    in >> data.bin_count;

    return data;
    }
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

int main() {
   const auto input = read_input(cin, true);

    // Обработка данных
    const auto bins = make_histogram(input);

    // Вывод данных
    show_histogram_svg (bins);


    return 0;
}
