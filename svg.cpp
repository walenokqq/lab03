#include <vector>
#include <iostream>
#include "svg.h"
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

string version_info() {
    stringstream buffer;
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
        buffer <<"Windows v" << version_major << "." << version_minor <<"(build" << build << ")"    ;
    }
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH+1;
    GetComputerNameA(computer_name, &size);
    buffer << "Computer name:" << computer_name;
    return buffer.str();
}

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

        string color_ask (istream& stream){
    string color;
    cerr << "Color - ?  :";
    stream>>color;
    return (color);
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
    }   }
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


        size_t i=0;
    for (size_t bin : bins) {
        //auto color = color_ask();
        const double bin_width = (double)(BLOCK_WIDTH * bin*scaling_factor);
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black" , "red");
        top += BIN_HEIGHT;
}
    svg_text(TEXT_LEFT, top+BIN_HEIGHT, version_info());
    svg_end();
}
