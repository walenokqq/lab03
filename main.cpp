#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>

using namespace std;

vector <double> input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cerr << "Enter number ";
        in >> result[i];
    }
    return result;
}

int main() {
    // ¬вод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(cin, number_count);   //‘ункиц€ зaполнени€ массива чисел

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // ќбработка данных
    auto bins=make_histogram(numbers, bin_count);

    // ¬ывод данных
    show_histogram_svg (bins);



    return 0;
}
