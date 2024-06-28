//
// Created by jacob on 2024/6/28.
//


#include <gtest/gtest.h>
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

