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
    /*  size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(cin, number_count);   //‘ункиц€ зaполнени€ массива чисел

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // ќбработка данных
    auto bins=make_histogram(numbers, bin_count);

    // ¬ывод данных
    show_histogram_svg (bins);*/
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD mask_2 = 0x0000ff;
   if ((info & 0x80000000) == 0)
    {
        DWORD version_major = version & mask_2;
        DWORD version_minor = version >> 8;
        DWORD build = platform;
        printf("Windows v%u.%u (build %u)\n", version_major, version_minor, build);
    }


    return 0;
}
