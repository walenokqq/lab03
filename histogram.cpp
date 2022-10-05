#include "histogram.h"
#include <vector>
#include<iostream>

using namespace std;


void find_minmax(vector<double> numbers, double& min, double& max) {
    if (numbers.size()>0){
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }}

}
vector <size_t> make_histogram (vector<double> numbers, size_t bin_count) {
    double min = numbers[0];
    double max = numbers[0];
    find_minmax (numbers, min, max);
    vector<size_t> bins(bin_count);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

