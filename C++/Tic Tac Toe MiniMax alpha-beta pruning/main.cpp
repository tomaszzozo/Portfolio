#include <iostream>
#include <vector>
#include <random>
#include "Point.h"
#include "Utility.h"

#define DEPTH 7 // Game tree maximum depth, suggested 7

using namespace std;

int main()
{
    size_t field_size;
    get_input("Podaj rozmiar pola: ", field_size);

    size_t fields_count = 0;
    while (fields_count < 3)
    {
        get_input("Podaj ilość znaków w rzędzie: ", fields_count);
    }

    vector<vector<char>> symbols;
    fill_vector(symbols, fields_count, ' ');

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 1);

    auto player = (int) dist(mt);
    cout << "Gracz: " << (player == 1 ? 'x' : 'o') << endl << "Komputer: " << (player == 1 ? 'o' : 'x') << endl;
    if (player == 1)
    {
        bot('o', symbols, 4);
    }

    while (true)
    {
        print_map(fields_count, symbols, field_size);
        cout << "#### RUCH GRACZA ####" << endl;

        Point p;
        do
        {
            p = Point::get_point("Podaj x y: ");
        }
        while (p.getX() >= fields_count || p.getY() >= fields_count || symbols.at(p.getY()).at(p.getX()) != ' ');

        symbols.at(p.getY()).at(p.getX()) = player == 1 ? 'x' : 'o';
        print_map(fields_count, symbols, field_size);
        if (win(symbols))
        {
            cout << "Wygrał gracz!" << endl;
            break;
        }
        else if (tie(symbols))
        {
            cout << "Remis!";
            break;
        }

        cout << "#### RUCH BOTA ####" << endl;
        bot(player == 1 ? 'o' : 'x', symbols, DEPTH);
        if (win(symbols))
        {
            print_map(fields_count, symbols, field_size);
            cout << "Wygrał bot!" << endl;
            break;
        }
        else if (tie(symbols))
        {
            print_map(fields_count, symbols, field_size);
            cout << "Remis!";
            break;
        }
    }
}

