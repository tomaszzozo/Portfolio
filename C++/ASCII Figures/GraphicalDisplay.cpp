#include "GraphicalDisplay.h"
#include <iostream>
#include <cmath>
#include "MyExcpetions.h"

using namespace std;

void GraphicalDisplay::drawTriangle(int a1, int a2, int b1, int b2)
{
    int c1 = 0, c2 = 0;
    if ((a1 == b1 && a2 == b2) || (a1 == c1 && a2 == c2) || (b1 == c1 && b2 == c2))
    {
        throw MyExcpetions();
    }
    calibrate_coordinates(a1, a2, b1, b2, c1, c2);

    const int height = find_max(a2, b2, c2), width = find_max(a1, b1, c1);
    vector<vector<char>> v;
    init_triangle(v, a1, a2, b1, b2, c1, c2, width, height);

    draw_line(v, a1, a2, b1, b2, 't');
    draw_line(v, b1, b2, c1, c2, 't');
    draw_line(v, a1, a2, c1, c2, 't');

    fill_triangle(v);
    print_figure(v);
}

void GraphicalDisplay::drawCircle(int r)
{
    if (r < 0 )
    {
        throw MyExcpetions();
    }

    float dist;
    char tab[2*r+1][2*r+1];
    for (int i = 0; i <= 2 * r; i++)
    {
        for (int j = 0; j <= 2 * r; j++)
        {
            dist = sqrtf((i - r) * (i - r) +
                        (j - r) * (j - r));

            if (dist > r - 0.5 && dist < r + 0.5)
            {
                tab[i][j] = 'c';
            }
            else
            {
                tab[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < 2*r+1; i++)
    {
        bool encountered_char = false;
        bool encountered_space = false;
        for (int j = 0; j < 2*r+1; j++)
        {
            if (i == 0 || i == 2*r)
            {
                cout << tab[i][j];
                continue;
            }
            if (!encountered_char)
            {
                cout << tab[i][j];
                if (tab[i][j] != ' ')
                {
                    encountered_char = true;
                }
            }
            else
            {
                if (!encountered_space)
                {
                    cout << 'c';
                    if (tab[i][j] == ' ')
                    {
                        encountered_space = true;
                    }
                }
                else
                {
                    cout << 'c';
                    if (tab[i][j] == 'c')
                    {
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}

void GraphicalDisplay::drawParallelogram(int a1, int a2, int b1, int b2)
{
    int c1 = 0, c2 = 0;
    if ((a1 == b1 && a2 == b2) || (a1 == c1 && a2 == c2) || (b1 == c1 && b2 == c2))
    {
        throw MyExcpetions();
    }

    calibrate_coordinates(a1, a2, b1, b2, c1, c2);
    int d1 = a1+b1, d2 = a2+b2;

    int width = find_max(a1, b1, c1, d1), height = find_max(a2, b2, c2, d2);

    vector<vector<char>> v;
    init_parallelogram(v, a1, a2, b1, b2, c1, c2, d1, d2, width, height);

    draw_line(v, a1, a2, b1, b2, 'p');
    draw_line(v, a1, a2, c1, c2, 'p');
    draw_line(v, a1, a2, d1, d2, 'p');
    draw_line(v, b1, b2, c1, c2, 'p');
    draw_line(v, b1, b2, d1, d2, 'p');
    draw_line(v, c1, c2, d1, d2, 'p');

    fill_parallelogram(v);
    print_figure(v);
}

int GraphicalDisplay::find_max(const int& x, const int& y, const int& z)
{
    if (x > y)
    {
        return x > z ? x : z;
    }
    return y > z ? y : z;
}

void GraphicalDisplay::draw_line(vector<vector<char>>& v, const int x1, const int y1, const int x2, const int y2,
                                 const char fill)
{
    if (x1 == x2)
    {
        for (int i = (y1 < y2 ? y1+1 : y2+1); i < (y1 > y2 ? y1 : y2); i++)
        {
            v.at(i).at(x1) = fill;
        }
    }
    else if (y1 == y2)
    {
        for (int i = (x1 < x2 ? x1+1 : x2+1); i < (x1 > x2 ? x1 : x2); i++)
        {
            v.at(v.size()-y1-1).at(i) = fill;
        }
    }
    else
    {
        draw_inclined_line(v, x1, y1, x2, y2, fill);
    }
}

void
GraphicalDisplay::init_triangle(vector<std::vector<char>> &v, const int a1, const int a2, const int b1, const int b2,
                                const int c1, const int c2, const int width, const int height)
{
    for (int i = height; i >= 0; i--)
    {
        vector<char> tab;
        for (int j = 0; j <= width; j++)
        {
            if ((i == a2 && j == a1) || (i == b2 && j == b1 ) || (i == c2 && j == c1))
            {
                tab.push_back('t');
            }
            else
            {
                tab.push_back(' ');
            }
        }
        v.push_back(tab);
    }
}

void GraphicalDisplay::print_figure(vector<std::vector<char>> &v)
{
    for (auto & i : v)
    {
        for (auto & c : i)
        {
            cout << c;
        }
        cout << endl;
    }
}

void GraphicalDisplay::calibrate_coordinates(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2)
{
    while (a1 < 0 || b1 < 0)
    {
        a1++;
        b1++;
        c1++;
    }
    while (a2 < 0 || b2 < 0)
    {
        a2++;
        b2++;
        c2++;
    }
}

void GraphicalDisplay::fill_triangle(vector<vector<char>> &v)
{
    for (int x = 0; x < v.at(0).size(); x++)
    {
        if (characters_in_collumn(v, x) != 2)
        {
            continue;
        }
        bool found_character = false;
        for (auto & y : v)
        {
            if (!found_character && y.at(x) != ' ')
            {
                found_character = true;
            }
            else if (found_character)
            {
                if (y.at(x) != ' ')
                {
                    break;
                }
                y.at(x) = 't';
            }
        }
    }

    for (auto & i : v)
    {
        int first_char = find(i, 't', false), last_char = find(i, 't', true);
        for (int j = first_char; j < last_char; j++)
        {
            i.at(j) = 't';
        }
    }
}

void GraphicalDisplay::draw_inclined_line(vector<std::vector<char>> &v, const int x1, const int y1, const int x2,
                                          const int y2, const char fill)
{
    if (abs(x1-x2) <= 1  || abs(y1-y2) <= 1)
    {
        return;
    }
    const int offset_x = x2-x1, offset_y = y2-y1;
    const int x3 = x1 + offset_x/2, y3 = y1 + offset_y/2;
    v.at(v.size()-y3-1).at(x3) = fill;
    draw_inclined_line(v, x1, y1, x3, y3, fill);
    draw_inclined_line(v, x2, y2, x3, y3, fill);
}

unsigned int GraphicalDisplay::characters_in_collumn(vector<std::vector<char>> &v, unsigned int collumn)
{
    unsigned int characters = 0;
    for (auto & i : v)
    {
        if (i.at(collumn) != ' ')
        {
            characters++;
        }
    }
    return characters;
}

void GraphicalDisplay::init_parallelogram(vector<vector<char>>& v, int a1, int a2, int b1,
                                          int b2, int c1, int c2, int d1, int d2,
                                          int width, int height)
{
    for (int i = height; i >= 0; i--)
    {
        vector<char> row;
        for (int j = 0; j <= width; j++)
        {
            if ((i == a2 && j == a1) || (i == b2 && j == b1) || (i == c2 && j == c1) || (i == d2 && j == d1))
            {
                row.push_back('p');
            }
            else
            {
                row.push_back(' ');
            }
        }
        v.push_back(row);
    }
}

int GraphicalDisplay::find_max(const int &x, const int &y, const int &z, const int &q)
{
    if (x > y)
    {
        if (x > z)
        {
            return x > q ? x : q;
        }
        return z > q ? z : q;
    }
    else if (y > z)
    {
        return y > q ? y : q;
    }
    else
    {
        return z > q ? z : q;
    }
}

void GraphicalDisplay::fill_parallelogram(vector<std::vector<char>> &v)
{
    for (auto & i : v)
    {
        int first_char = find(i, 'p', false), last_char = find(i, 'p', true);
        for (int j = first_char; j < last_char; j++)
        {
            i.at(j) = 'p';
        }
    }
}

int GraphicalDisplay::find(vector<char>& v, const char c, bool reverse)
{
    int pos = -1;
    if (reverse)
    {
        for (int i = v.size()-1; i >= 0; i--)
        {
            if (v.at(i) == c)
            {
                return i;
            }
        }
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v.at(i) == c)
            {
                return i;
            }
        }
    }
    return pos;
}
