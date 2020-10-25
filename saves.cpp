#include <filesystem>
#include <fstream>

#include "saves.hpp"
#include "chess_field.hpp"
#include "json.hpp"

namespace fs = std::filesystem;

auto get_game(auto identifier) -> ChessField {
    return ChessField();
}

auto save_game(auto&& field) -> void {

}
