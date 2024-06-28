#define NOMINMAX
#include <gtest/gtest.h>
#include "../src/FruitFactory.h"
#include "../src/Fruit.h"
#include "../src/Apple.h"
#include "../src/Orange.h"
#include <memory>

class FruitFactoryTest : public ::testing::Test {
protected:
  FruitFactory factory;
};

// 测试 RefreshFruit 方法返回的对象不是空指针
TEST_F(FruitFactoryTest, RefreshFruitNotNull) {
  auto fruit = factory.RefreshFruit();
  EXPECT_NE(fruit, nullptr);
}

// 测试 RefreshFruit 方法返回的对象是 Apple 或 Orange 的实例
TEST_F(FruitFactoryTest, RefreshFruitIsAppleOrOrange) {
  auto fruit = factory.RefreshFruit();
  auto apple = std::dynamic_pointer_cast<Apple>(fruit);
  auto orange = std::dynamic_pointer_cast<Orange>(fruit);
  EXPECT_TRUE(apple || orange);
}

// 测试生成 Apple 的可能性
TEST_F(FruitFactoryTest, RefreshFruitGenerateApple) {
  bool foundApple = false;
  for (int i = 0; i < 100; ++i) {
    auto fruit = factory.RefreshFruit();
    if (std::dynamic_pointer_cast<Apple>(fruit)) {
      foundApple = true;
      break;
    }
  }
  EXPECT_TRUE(foundApple);
}

// 测试生成 Orange 的可能性
TEST_F(FruitFactoryTest, RefreshFruitGenerateOrange) {
  bool foundOrange = false;
  for (int i = 0; i < 100; ++i) {
    auto fruit = factory.RefreshFruit();
    if (std::dynamic_pointer_cast<Orange>(fruit)) {
      foundOrange = true;
      break;
    }
  }
  EXPECT_TRUE(foundOrange);
}

// 测试生成的 Fruit 对象的位置在合理范围内
TEST_F(FruitFactoryTest, RefreshFruitLocationWithinBounds) {
  for (int i = 0; i < 100; ++i) {
    auto fruit = factory.RefreshFruit();
    auto loc = fruit->GetLocation();
    EXPECT_GE(loc.first, 0);
    EXPECT_LE(loc.first, (Globals::GRAPH_WEIGHT - Globals::BLOCK_SIZE));
    EXPECT_GE(loc.second, 0);
    EXPECT_LE(loc.second, (Globals::GRAPH_HEIGHT - Globals::BLOCK_SIZE));
  }
}

