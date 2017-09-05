//
//  main.c
//  palindrome-permutation
//  Check if a given string is a permutation of a palindrome by toggling the bits that represent characters in the string.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// false for a non-ASCII English letter.
bool isEnglishLetter(char character)
{
    return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

// substruct one from bitVector and bit ANDing bitVector needs to return 0 if only one bit is set.
bool checkThatOnlyOneBitIsSet(int bitVector)
{
    return (bitVector & (bitVector - 1)) == 0;
}

// bitVector indicates odd or even count of each phrase's character by toggling the ith bit.
int createBitVector(char *phrase)
{
    bool isEnglishLetter(char letter);
    int mask, bitVector = 0;

    while(*phrase) {
        if (isEnglishLetter(*phrase)) {
            mask = 1 << (tolower(*phrase) - 96); // ex: 1 << 3 = 0100;

            if ((bitVector & mask) == 0) { // ex. 0000 & 0100 = 0000. TRUE means that the bit represents a new character for bitVector
                bitVector |= mask; // TRUE case: set the bit from the mask
            } else {
                bitVector &= ~mask; // it's a toggle for bitVector's bit using the mask.
            }
        }

        phrase++;
    }

    return bitVector;
}

// a palindrome needs to have an even number of similar characters or only one character without a pair.
// we form an integer bit vector where each bit is a character's number ('a' sets a bit 97)
// and we toggle a character's bit whenever we see the character in the string.
bool isPermutationOfPalindrome(char *phrase)
{
    bool chackThatOnlyOneBitIsSet(int);
    int createBitVector(char *);
    int bitVector;

    bitVector = createBitVector(phrase);

    // bitVector equals 0 means that we have the even number of similar characters and the string is "balanced"
    // if bitVector has more than one bit set, means that we have at least two odd characters that don't have their pairs on the string
    return bitVector == 0 || checkThatOnlyOneBitIsSet(bitVector);
}

int main(int argc, const char * argv[]) {
    bool isPalindromePermutation(char *);
    char phraseForCheck[80] = {};

    printf("Please enter your phrase: ");
    fgets(phraseForCheck, 80, stdin);

    printf("The string is %s a permutation of a palindrome\n", isPermutationOfPalindrome(phraseForCheck) ? "" : "not");

    return 0;
}
