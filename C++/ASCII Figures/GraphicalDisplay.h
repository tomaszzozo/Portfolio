#pragma once
#include <vector>
#include "Display.h"

class GraphicalDisplay : public Display
{
    static int find_max(const int& x, const int& y, const int& z);
    static void draw_line(std::vector<std::vector<char>>& v, int x1, int x2, int y1, int y2, char fill);
    static void init_triangle(std::vector<std::vector<char>>& v, int a1, int a2, int b1, int b2, int c1, int c2,
                              int width, int height);
    static void print_figure(std::vector<std::vector<char>>& v);
    static void calibrate_coordinates(int& a1, int& a2, int& b1, int& b2, int& c1, int& c2);
    static void fill_triangle(std::vector <std::vector<char>> &v);
    static void draw_inclined_line(std::vector<std::vector<char>>& v, int x1, int y1, int x2, int y2, char fill);
    static unsigned int characters_in_collumn(std::vector<std::vector<char>> &v, unsigned int collumn);
    static void init_parallelogram(std::vector<std::vector<char>>& v, int a1, int a2, int b1, int b2, int c1, int c2,
                                   int d1, int d2, int width, int height);
    static int find_max(const int &x, const int& y, const int& z, const int& q);
    static void fill_parallelogram(std::vector<std::vector<char>>& v);
    static int find(std::vector<char>& v, char c, bool reverse);

public:
    void drawTriangle(int a1, int a2, int b1, int b2) final;
    void drawCircle(int r) final;
    void drawParallelogram(int a1, int a2,int b1,int b2) final;
};
