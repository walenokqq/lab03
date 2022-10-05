#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
using namespace std;


struct Input {
    vector<double> numbers;
    size_t bin_count;
};


void find_minmax(struct Input t, double& min, double& max);
vector <size_t> make_histogram (vector<double> numbers, size_t bin_count);
vector <double> input_numbers(size_t count);
#endif // HISTOGRAM_H_INCLUDED
