//
//  main.c
//  palindrome-permutation
//  Check if a given string is a permutation of a palidrome by toggling the bits that represent characters on the string.
//
//

#include <stdio.h>
#include <stdbool.h>

bool isEnglishLetter(char character)
{
    return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

void filterSrting(char *originalString)
{
    bool isEnglishLetter(char);
    char *cleanString;

    cleanString = originalString;

    while(*originalString && *originalString != '\n') {
        if (isEnglishLetter(*originalString)) {
            *(cleanString++) = *originalString;
        }

        originalString++;
    }

    *cleanString = '\0';
}

bool checkThatOnlyOneBitIsSet(int bitVector)
{
    return (bitVector & (bitVector - 1)) == 0;
}

int createBitVector(char *phrase)
{
    int mask, bitVector = 0;

    while(*phrase) {
        mask = 1 << *phrase; // ex: 1 << 3 = 0100;

        if ((bitVector & mask) == 0) { // ex. 0000 & 0100 = 0000. TRUE means that the bit represents a new character for bitVector
            bitVector |= mask; // TRUE case: set the bit from the mask
        } else {
            bitVector &= ~mask; // it's a toggle for the bitVector's bit using the mask.
        }

        phrase++;
    }

    return bitVector;
}

// a palindrome needs to have odd number of similar characters or only one character without a pair.
// we form an integer bit vector where each bit is a character's number ('a' is bit 97)
// and we toggle a character's bit every time when we see the character in the string.
bool isPermutationOfPalindrome(char *string)
{
    void filterSrting(char *);
    bool chackThatOnlyOneBitIsSet(int);
    int createBitVector(char *);
    int bitVector;

    filterSrting(string);
    bitVector = createBitVector(string);

    // bitVector equals 0 means that we have the even number of similar characters and the string is "balanced"
    // if bitVector has more than one bit set, means that we have at least 2 odd characters that don't have their pairs on the string
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
