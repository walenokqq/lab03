#include "histogram.h"
#include <vector>
#include<iostream>

using namespace std;


void find_minmax(struct Input t, double& min, double& max) {
    if (t.numbers.size()>0){
    min = t.numbers[0];
    max = t.numbers[0];
    for (double number : t.numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }}

}


