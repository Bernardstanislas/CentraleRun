#include "gtest/gtest.h"
#include "../Run/Sprite.h"

using namespace std;

// mock FieldAction and SpriteAction
class FieldAction;

class SpriteAction
{
public:
    bool execute(Sprite sprite) { return FieldAction(); }
};

TEST(Sprite, Instance) {
    EXPECT_NO_THROW({
        Sprite* sprite = Sprite::Instance();
    });
    SpriteAction spAction;
    EXPECT_NO_THROW({
        sprite->addAction(spAction);
    });
    ASSERT_EQ({
        sprite->getActions(), vector<unique_ptr<SpriteAction>>(*spAction)
    });
    ASSERT_EQ({
        sprite->executeActions(), vector<unique_ptr<FieldAction>>(*spAction)
    });
    EXPECT_NO_THROW({
        sprite->deleteAction(spAction);
    });
    ASSERT_EQ({
        sprite->getActions(), vector<unique_ptr<SpriteAction>>()
    });
}
