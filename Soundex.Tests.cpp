#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, BasicTest) {
    EXPECT_EQ(generateSoundex("Singh"), "S520");
    EXPECT_EQ(generateSoundex("Kumar"), "K560");
    EXPECT_EQ(generateSoundex("Sharma"), "S650");
    EXPECT_EQ(generateSoundex("Patel"), "P340");
    EXPECT_EQ(generateSoundex("Gupta"), "G130");
}
 
TEST(SoundexTest, EdgeCases) {
    EXPECT_EQ(generateSoundex("Chand"), "C530");
    EXPECT_EQ(generateSoundex("Mehra"), "M600");
    EXPECT_EQ(generateSoundex("Pandey"), "P530");
    EXPECT_EQ(generateSoundex(""), "");
}
 
TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(generateSoundex("SINGH"), "S520");
    EXPECT_EQ(generateSoundex("kUmAr"), "K560");
    EXPECT_EQ(generateSoundex("shARmA"), "S650");
}
 
TEST(SoundexTest, SingleCharacterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}
 
TEST(SoundexTest, AllVowels) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
    EXPECT_EQ(generateSoundex("Euio"), "E000");
}
