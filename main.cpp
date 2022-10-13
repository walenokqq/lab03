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

int main() {
    // ���� ������
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(cin, number_count);   //������� �a�������� ������� �����

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // ��������� ������
    auto bins=make_histogram(numbers, bin_count);

    // ����� ������
    show_histogram_svg (bins);


    return 0;
}
