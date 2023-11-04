#include "gtest/gtest.h"
#include "date.h"
#include "string"
#include "time.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  epochDate = Date(1698347604);
  today = Date();
  first_day_2 = Date(2016, 1, 1);
	last_day_2 = Date(2016, 3, 1);
  leapDate = Date(2016, 2, 29);
  oldDay = Date(900, 1, 1);

  }
 protected:
  Date first_day;           // first day of classes
  Date last_day;            // last day of classes
  Date epochDate;           // Date created with epoch
  Date today;               // Date created with no parameters
  Date first_day_2;
  Date last_day_2;
  Date leapDate;
  Date oldDay;
};

TEST_F(DateTest, EpochConstructor) {
  EXPECT_EQ(epochDate.GetDate(), "2023-10-26");
  EXPECT_EQ(epochDate.GetDate(), "2023-10-26") << "Epoch constructor not set up correctly";
}

TEST_F(DateTest, NoParmDateConstructor) {
  time_t now =time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
  // for more information about date/time format
  strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

  EXPECT_EQ(today.GetDate(), buf) << "Todays date not set up properly";
}

TEST_F(DateTest, OperatorPlus) {
  
  Date minusLeap = leapDate - 2;
  Date plusLeap = minusLeap + 2;
  EXPECT_EQ(leapDate.GetDate(), "2016-02-29");
  EXPECT_EQ(minusLeap.GetDate(), "2016-02-27");
  EXPECT_EQ(plusLeap.GetDate(), "2016-02-29");

}

TEST_F(DateTest, OperatorMinus) {

  Date plusLeap = leapDate + 1;
  Date minusLeap = plusLeap - 2;
  
  EXPECT_EQ(leapDate.GetDate(), "2016-02-29");
  EXPECT_EQ(plusLeap.GetDate(), "2016-03-01");
  EXPECT_EQ(minusLeap.GetDate(), "2016-02-28");
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";

  EXPECT_EQ(first_day_2.GetUsDate(), "01-01-2016") << "First day of class not setup properly";
  EXPECT_EQ(last_day_2.GetUsDate(), "03-01-2016") << "Last day of class not setup properly";
  EXPECT_EQ(first_day_2.DaysBetween(last_day_2), 60) << "Days between is not calculated properly";
}

TEST_F(DateTest, GetDate) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04");
  EXPECT_EQ(last_day.GetDate(), "2018-12-11");
  EXPECT_EQ(first_day_2.GetDate(), "2016-01-01");
  EXPECT_EQ(last_day_2.GetDate(), "2016-03-01");
}

TEST_F(DateTest, GetUsDate) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018");
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018");
  EXPECT_EQ(first_day_2.GetUsDate(), "01-01-2016");
  EXPECT_EQ(last_day_2.GetUsDate(), "03-01-2016");
  EXPECT_EQ(oldDay.GetUsDate(), "01-01-900");
}

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}



TEST_F(DateTest, PrintUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
