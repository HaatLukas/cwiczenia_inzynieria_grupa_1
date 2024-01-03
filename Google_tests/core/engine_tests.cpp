//
// Created by david on 03.01.2024.
//
#include "gtest/gtest.h"
#include "core/engine.h"

namespace game {

    class EngineTests : public testing::Test {
    protected:
        virtual void SetUp() {
            engine = new Engine();
        }

        virtual void TearDown() {
            delete engine;
        }

        Engine *engine;
    };

    TEST_F(EngineTests, isGameStarting) {
        engine->startGame();
        EXPECT_EQ(engine->isActive, true);

        engine->endGame();
        EXPECT_EQ(engine->isActive, false);
    }

} // namespace game