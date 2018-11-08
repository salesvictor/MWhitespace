#include <gtest/gtest.h>
#include "assembler.h"

TEST(test_assembler, translate_token) {
  EXPECT_EQ(mws::Assembler::translate_token("RNOSD"), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token("OAKSM"), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token("ASD"), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token("SAD"), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token("ASDZCX"), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token("vsasdfxz"), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token(" "), "INVALID");
  EXPECT_EQ(mws::Assembler::translate_token("\n\t"), "INVALID");
}
