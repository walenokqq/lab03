#include <vector>
#include <iostream>
#include "svg.h"
#include <string>
using namespace std;


void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='"  <<baseline<<   "'>" <<text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string FILL) {
cout << "<rect x='"<< x <<"' y='"<<y <<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<FILL<<"' />";
}
void show_histogram_text (vector<size_t> bins) {
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins) {
        if (bin < 100) {
            cout << ' ';
        }
        if (bin < 10) {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed) {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }}
void show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;
    size_t max_count=bins[0];
    for (size_t count : bins)
    {
        if ( count >max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > (IMAGE_WIDTH/BLOCK_WIDTH-TEXT_WIDTH/BLOCK_WIDTH);

    double scaling_factor=1;
    if (scaling_needed){
        scaling_factor =(double)(IMAGE_WIDTH - TEXT_WIDTH)/(max_count*BLOCK_WIDTH);
        }
    string colour;                  //������������ �������
    getline(cin,colour);
    size_t i=0;
    for (size_t bin : bins) {


        cerr << "Colour("<<  i+1 <<") - ?  :";
        string colour;
        getline(cin,colour);
        i++;

        const double bin_width = (double)(BLOCK_WIDTH * bin*scaling_factor);
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black" , colour );
        top += BIN_HEIGHT;
}
    svg_end();
}
