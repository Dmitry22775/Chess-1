#ifndef FIELD_H
#define FIELD_H

#include <cstdint>

namespace Color
{
const auto FG_WHITE = "\033[97m";
const auto FG_BLACK = "\033[30m";
const auto FG_DEFAULT = "\033[39m";
const auto BG_LIGHT_BLUE = "\033[104m";
const auto BG_BLUE = "\033[44m";
const auto BG_DARK_BLUE = "\033[106m";
const auto BG_DEFAULT = "\033[49m";
} // namespace Color

enum class FigureType : uint8_t {
    empty,
    king,
    queen,
    rook,
    bishop,
    horse,
    pawn
};

enum class FigureColor : uint8_t { empty, black, white };

using FigureSign = char;

class Figure
{
    FigureType type_;
    FigureColor color_;

  public:
    Figure() = default;
    Figure(FigureType, FigureColor);
    auto get_type() -> FigureType;
    auto get_color() -> FigureColor;
    auto get_sign() -> FigureSign;
};

class ChessField
{
    Figure field_[8][8];

  public:
    ChessField();
    auto draw() -> void;
};

#endif // FIELD_H
