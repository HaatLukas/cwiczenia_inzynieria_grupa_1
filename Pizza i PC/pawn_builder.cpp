#include "player.h"

namespace game {

    struct PawnBuilder {
        Player *owner;
        int color;
        bool selected;
        bool isQueen;

        explicit PawnBuilder(Player *owner, int color) : owner(owner), color(color) {}

        PawnBuilder& setSelected(bool val) {
            selected = val;
            return *this;
        }

        PawnBuilder& setQueenStatus(bool val){
            isQueen = val;
            return *this;
        }

        Pawn* build() {
            Pawn pawn(owner, color);
            pawn.setSelected(selected);
            pawn.setQueenStatus(isQueen);
            return &pawn;
        }
    };

    class Pawn {
        PawnBuilder builder;

    public:
        explicit Pawn(PawnBuilder builder) : builder(builder) {}

        [[nodiscard]] int getColor() const {
            return builder.color;
        }

        void setSelected(bool val) {
            builder.setSelected(val);
        }

        void setQueenStatus(bool val){
            builder.setQueenStatus(val);
        }

        [[nodiscard]] Player *getOwner() const {
            return builder.owner;
        }

        [[nodiscard]] bool isSelected() const {
            return builder.selected;
        }

        [[nodiscard]] bool queenStatus() const{
            return builder.isQueen;
        }

    };

} 