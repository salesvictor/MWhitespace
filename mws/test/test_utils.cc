#include "mws/utils.h"

#include <gtest/gtest.h>

using namespace mws::utils;

TEST(IsNumberTest, NoSignal) {
  EXPECT_TRUE(IsNumber("123"));
  EXPECT_TRUE(IsNumber("1"));
  EXPECT_TRUE(IsNumber("12"));
  EXPECT_TRUE(IsNumber("1323"));
  EXPECT_FALSE(IsNumber("123ab"));
  EXPECT_FALSE(IsNumber("123ab321"));
  EXPECT_FALSE(IsNumber("ab123"));
  EXPECT_FALSE(IsNumber("ab123ba"));
}

TEST(IsNumberTest, Signal) {
  EXPECT_TRUE(IsNumber("+123"));
  EXPECT_TRUE(IsNumber("-123"));
  EXPECT_TRUE(IsNumber("+1"));
  EXPECT_TRUE(IsNumber("-1"));
  EXPECT_FALSE(IsNumber("1-"));
  EXPECT_FALSE(IsNumber("1--"));
  EXPECT_FALSE(IsNumber("++12"));
  EXPECT_FALSE(IsNumber("--1323"));
  EXPECT_FALSE(IsNumber("+123ab"));
  EXPECT_FALSE(IsNumber("-123ab321"));
  EXPECT_FALSE(IsNumber("ab123"));
  EXPECT_FALSE(IsNumber("ab123ba+"));
}
