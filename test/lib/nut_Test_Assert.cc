// T. M. Kelley (c) 2011 LANS LLC

#include "gtest/gtest.h"
#include <iostream>
#include <string>

#ifndef REQUIRE_ON
#define REQUIRE_ON
#include "Assert.hh"
#undef REQUIRE_ON
#else
#include "Assert.hh"
#endif

TEST(nut_assertions, Require_ON)
{
  std::string err("test 1");
  try {
    nut::Require(false, err.c_str());
    EXPECT_TRUE(false);
  } catch(std::exception & exc) {
    if(exc.what() != err) {
      std::cerr << "test_1: Caught assertion as expected"
                << " wrong what: " << exc.what() << std::endl;
      EXPECT_TRUE(false);
    }
  }
  try {
    nut::Require(true, err.c_str());
  } catch(std::exception & exc) {
    EXPECT_TRUE(false);
    std::cerr << "test_1: Threw assertion--not expected" << std::endl;
  }

  return;
}  // test_1

TEST(nut_assertions, Equal_ON)
{
  std::string err("a != b");
  try {
    double a = 1.0, b = 2.0;
    nut::Equal(a, b, "a", "b");
    EXPECT_TRUE(false);
  } catch(std::exception & exc) {
    if(exc.what() != err) {
      std::cerr << "test_2: Caught assertion as expected"
                << " wrong what: " << exc.what() << std::endl;
      EXPECT_TRUE(false);
    }
  }
  try {
    double a = 1.0, b = 1.0;
    nut::Equal(a, b, "a", "b");
  } catch(std::exception & exc) {
    EXPECT_TRUE(false);
    std::cerr << "test_2:" << __LINE__ << " Caught assertion--not expected"
              << std::endl;
  }

  return;
}  // test_2

TEST(nut_assertions, InOpenRange_double_ON)
{
  std::string err("a (2) was not in range (1,2)");
  try {
    double a = 2.0, min = 1.0, max = 2.0;
    nut::InOpenRange(a, min, max, "a");
    EXPECT_TRUE(false);
    std::cerr << "test_3:" << __LINE__ << " Didn't throw assertion as expected"
              << std::endl;
  } catch(std::exception & exc) {
    if(exc.what() != err) {
      std::cerr << "test_3:" << __LINE__ << " Caught assertion as expected"
                << " wrong what: " << exc.what() << std::endl;
      EXPECT_TRUE(false);
    }
  }
  try {
    double a = 2.0, min = 1.0, max = 2.000000000001;
    nut::InOpenRange(a, min, max, "a");
  } catch(std::exception & exc) {
    EXPECT_TRUE(false);
    std::cerr << "test_3:" << __LINE__ << " Caught assertion--not expected"
              << std::endl;
  }

  return;
}  // test_3

TEST(nut_assertions, GreaterThan_double_ON)
{
  std::string err("a (2) <= 3");
  try {
    double a = 2.0, min = 3.0;
    nut::GreaterThan(a, min, "a");
    EXPECT_TRUE(false);
    std::cerr << "test_4:" << __LINE__ << " Didn't throw assertion as expected"
              << std::endl;
  } catch(std::exception & exc) {
    if(exc.what() != err) {
      std::cerr << "test_4:" << __LINE__
                << " Caught assertion as expected wrong what: " << exc.what()
                << std::endl;
      EXPECT_TRUE(false);
    }
  }
  try {
    double a = 2.0, min = 1.0;
    nut::GreaterThan(a, min, "a");
  } catch(std::exception & exc) {
    EXPECT_TRUE(false);
    std::cerr << "test_4:" << __LINE__ << " Caught assertion--not expected"
              << std::endl;
  }
  return;
}  // test_4

TEST(nut_assertions, InOpenRange_uint32_t_ON)
{
  std::string err("a (2) was not in range (1,2)");
  try {
    uint32_t a = 2, min = 1, max = 2;
    nut::InOpenRange(a, min, max, "a");
    EXPECT_TRUE(false);
    std::cerr << "test_5:" << __LINE__ << " Didn't throw assertion as expected"
              << std::endl;
  } catch(std::exception & exc) {
    if(exc.what() != err) {
      std::cerr << "test_5:" << __LINE__
                << " Caught assertion as expected wrong what: " << exc.what()
                << std::endl;
      EXPECT_TRUE(false);
    }
  }
  try {
    uint32_t a = 2, min = 1, max = 3;
    nut::InOpenRange(a, min, max, "a");
  } catch(std::exception & exc) {
    EXPECT_TRUE(false);
    std::cerr << "test_5:" << __LINE__ << " Caught assertion--not expected"
              << std::endl;
  }
  return;
}  // test_5

TEST(nut_assertions, GreaterThan_int64_t_ON)
{
  std::string err("a (-2) <= 3");
  try {
    int64_t a = -2, min = 3;
    nut::GreaterThan(a, min, "a");
    EXPECT_TRUE(false);
    std::cerr << "test_6:" << __LINE__ << " Didn't throw assertion as expected"
              << std::endl;
  } catch(std::exception & exc) {
    if(exc.what() != err) {
      std::cerr << "test_6:" << __LINE__
                << " Caught assertion as expected wrong what: " << exc.what()
                << std::endl;
      EXPECT_TRUE(false);
    }
  }
  try {
    int64_t a = 2, min = -1;
    nut::GreaterThan(a, min, "a");
  } catch(std::exception & exc) {
    EXPECT_TRUE(false);
    std::cerr << "test_6:" << __LINE__ << " Caught assertion--not expected"
              << std::endl;
  }
  return;
}  // test_6

// define additional tests here.

// End of file
