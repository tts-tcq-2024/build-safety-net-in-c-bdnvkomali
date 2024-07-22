#include <stdio.h>
#include <ctype.h>
#include <string.h>


 
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
 
void padSoundex(char* soundex) {
    size_t len = strlen(soundex);
    while (len < 4) {
        soundex[len++] = '0';
    }
    soundex[4] = '\0';
}

 
void initializeSoundex(char* soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
void generateSoundex(const char* name, char* soundex) {
    initializeSoundex(soundex, name[0]); // Initialize soundex with the first character of name
    char prevCode = getSoundexCode(name[0]); // Get Soundex code for the first character
 
    size_t i = 1;
    while (name[i] != '\0' && i < 4) {
        prevCode = eliminateZeroAndRepeatedValue(prevCode, soundex, i, name);
        i++;
    }
    padSoundex(soundex);
}
