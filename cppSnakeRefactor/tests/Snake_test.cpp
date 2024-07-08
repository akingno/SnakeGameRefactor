//
// Created by jacob on 2024/6/28.
//


#include <gtest/gtest.h>
#define private public
#include "../src/Snake.h"




class SnakeTest : public ::testing::Test{

protected:

  Snake snake;
};

/*
 *
 * 蛇构造非空
 *
 * */
TEST_F(SnakeTest,SnakeNotNull){
  auto snake2 = make_shared<Snake>();
  EXPECT_NE(snake2,nullptr);
}

TEST_F(SnakeTest,SnakeTurnUpCorrectly){
  snake.Up();
  EXPECT_EQ(snake.GetDirection(),std::make_pair(0,-1));
}
TEST_F(SnakeTest,SnakeTurnDownCorrectly){
  snake.Down();
  EXPECT_EQ(snake.GetDirection(),std::make_pair(0,1));
}

/*TEST_F(SnakeTest,SnakeTurnBackCorrectly){
  snake.Right();
  snake.Left();
  EXPECT_EQ(snake.GetDirection(),std::make_pair(1,0));
}*/

TEST_F(SnakeTest,SnakeTurnFrontCorrectly){
  snake.Right();
  EXPECT_EQ(snake.GetDirection(),std::make_pair(1,0));
}

TEST_F(SnakeTest, CheckEatItself){
  // 设置蛇的身体重叠部分
  snake.vec_body = {{2, 2}, {2, 3}, {2, 4}, {2, 2}};
  EXPECT_TRUE(snake.CheckEatItself());

  // 设置蛇的身体不重叠
  snake.vec_body = {{2, 2}, {2, 3}, {2, 4}, {2, 5}};
  EXPECT_FALSE(snake.CheckEatItself());
}

TEST_F(SnakeTest, CheckEatMine){
  std::pair<int, int> mine_location = {3, 3};

  // 设置蛇的头位置与地雷位置相同
  snake.vec_body = {{3, 3}, {2, 3}, {1, 3}};
  EXPECT_TRUE(snake.CheckEatMine(mine_location));

  // 设置蛇的头位置与地雷位置不同
  snake.vec_body = {{4, 4}, {3, 3}, {2, 3}};
  EXPECT_FALSE(snake.CheckEatMine(mine_location));
}

TEST_F(SnakeTest, CheckCollideWall){
  // 设置蛇的头超出墙的范围
  snake.vec_body = {{Globals::GRAPH_WEIGHT + 1, 2}};
  EXPECT_TRUE(snake.CheckCollideWall());

  snake.vec_body = {{2, Globals::GRAPH_HEIGHT + 1}};
  EXPECT_TRUE(snake.CheckCollideWall());

  // 设置蛇的头在墙的范围内
  snake.vec_body = {{Globals::GRAPH_WEIGHT - 1, Globals::GRAPH_HEIGHT - 1}};
  EXPECT_FALSE(snake.CheckCollideWall());

  // 设置蛇的头在墙的边界上
  snake.vec_body = {{0, 0}};
  EXPECT_FALSE(snake.CheckCollideWall());
}






#undef private