#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include <gtest/gtest.h>

 
char getSoundexCode(char c) {
    static const char soundexCodes[] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
 
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexCodes[c - 'A'];
    }
    return '0';
}
 
char fetch_firstchar(const std::string& name) {
    if (name.empty()) return '\0';
    return toupper(name[0]);
}
 
void appendSoundex(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}
 
std::string initializeSoundex(const std::string& name, char firstChar) {
    std::string soundex(1, firstChar);
    char secondex = getSoundexCode(name[1]);
    if (secondex != '0') {
        soundex += secondex;
    }
    return soundex;
}
 
std::string processSoundex(const std::string& name, char firstChar) {
   std::string soundex = initializeSoundex(name, firstChar);
    char prevCode = soundex[1];
    for (size_t i = 2; i < name.length() && soundex.length() < 4; ++i) 
    {
        char code = getSoundexCode(name[i]);
        appendSoundex(soundex, code, prevCode);
    }
 
    return soundex;
}
 
std::string paddingSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0');
    return paddedSoundex;
}
 
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
 
    char firstChar = fetch_firstchar(name);
    std::string processedName = processSoundex(name, firstChar);
    std::string paddedSoundex = paddingSoundex(processedName);
 
    return paddedSoundex;
}
 
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

