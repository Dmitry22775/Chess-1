#include <iostream>
#include <map>
#include <string_view>

#include "chess_field.hpp"

Figure::Figure(FigureType type, FigureColor color) : type_(type), color_(color) {}

Figure fig{FigureType(), FigureColor()};

auto Figure::get_type() -> FigureType
{
    return this->type_;
}

auto Figure::get_color() -> FigureColor
{
    return this->color_;
}

auto Figure::get_sign() -> FigureSign
{
    static const std::map<FigureType, FigureSign> figure_sign{
        {FigureType::empty, ' '}, {FigureType::king, 'K'}, {FigureType::queen, 'Q'}, {FigureType::rook, 'R'}, {FigureType::bishop, 'B'}, {FigureType::horse, 'H'}, {FigureType::pawn, 'P'},
    };
    return figure_sign.at(this->type_);
}


ChessField::ChessField()
{
    // Set Pawns
    for (size_t i = 1; i < 7; i += 5) {
        for (size_t j = 0; j < 8; j++) {
            field_[i][j] = {FigureType::pawn, (i == 1 ? FigureColor::black : FigureColor::white)};
        }
    }

    // Set other figures
    static const auto get_color_for = [](auto index) {
        if (index == 0)  // first line of grid
            return FigureColor::black;
        else
            return FigureColor::white;
    };
    for (size_t i = 0; i < 8; i += 7) {
        field_[i][0] = {FigureType::rook, get_color_for(i)};
        field_[i][1] = {FigureType::horse, get_color_for(i)};
        field_[i][2] = {FigureType::bishop, get_color_for(i)};
        field_[i][3] = {FigureType::queen, get_color_for(i)};
        field_[i][4] = {FigureType::king, get_color_for(i)};
        field_[i][5] = {FigureType::bishop, get_color_for(i)};
        field_[i][6] = {FigureType::horse, get_color_for(i)};
        field_[i][7] = {FigureType::rook, get_color_for(i)};
    }
}

void ChessField::draw()
{
    static const auto switch_bg_color = [](auto &clr) {
        if (clr == Color::BG_BLUE)
            clr = Color::BG_LIGHT_BLUE;
        else
            clr = Color::BG_BLUE;
    };
    auto header_letters = "\n          a      b      c      d      e      f      g      h   \n";

    puts(header_letters);
    auto cell_background_color = Color::BG_LIGHT_BLUE;
    for (size_t grid_row = 0; grid_row < 8; grid_row++) {
        for (size_t cell_row = 0; cell_row < 3; cell_row++) {
            for (size_t grid_col = 0; grid_col < 10; grid_col++) {
                for (size_t cell_col = 0; cell_col < 7; cell_col++) {
                    if (grid_col == 0 || grid_col == 9) {
                        if (cell_col == 3) {
                            if (cell_row == 1)
                                std::cout << grid_row + 1;
                            else
                                putchar(' ');
                        } else {
                            putchar(' ');
                        }
                        switch_bg_color(cell_background_color);
                        continue;
                    }

                    if (cell_row == 1 && cell_col == 3)  // cell middle
                    {
                        if (field_[grid_row][grid_col - 1].get_color() == FigureColor::black) {
                            std::cout << cell_background_color << Color::FG_BLACK << field_[grid_row][grid_col - 1].get_sign() << Color::FG_DEFAULT << Color::BG_DEFAULT;
                        } else {
                            std::cout << cell_background_color << Color::FG_WHITE << field_[grid_row][grid_col - 1].get_sign() << Color::FG_DEFAULT << Color::BG_DEFAULT;
                        }
                    } else {
                        std::cout << cell_background_color << ' ' << Color::BG_DEFAULT;
                    }
                }  // cell_col
                switch_bg_color(cell_background_color);
            }  // grid_col
            std::cout << "\n";
        }  // cell_row
        switch_bg_color(cell_background_color);
    }  // grid_row
    puts(header_letters);
}
