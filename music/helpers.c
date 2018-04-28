// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int Denom = atoi(&fraction[2]); //turn the string into an interger
    int Numer = atoi(&fraction[0]); //turn the strings into an interger

    switch (Denom) //use denominator to determine the multiplier
    {
        case 8:
            return Numer; //return the numerator since the denominator is already 8
            break;

        case 4:
            return (Numer * 2); //return the numerator multiplied by 2
            break;

        case 2:
            return (Numer * 4); //return the numerator multiplied by 4
            break;

        default: //provide a default
            return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    //convert to int with atoi()
    //calculate the frequency of the note (considering its octave)
    //A4 = 440HZ
    //Semitone increases frequency multiplying by 2^(1/12)
    //Semitone decrease divide frequency by 2^(1/12)

    int octave;
    int powerFactor = 0;
    if (strlen(note) == 3)
    {
        octave = atoi(&note[2]); //parse the string into OCTAVE
        char accidental = note[1]; //parse string into ACCIDENTAL if necessary

        if (accidental == '#')
        {
            powerFactor += 1; // add for sharps
        }
        else if (accidental == 'b')
        {
            powerFactor -= 1; //subtract for flats
        }
    }
    else
    {
        octave = atoi(&note[1]); //reassign note[1] if there is no accidental
    }


    char letter = note[0]; //parse string into NOTE

    if (letter == 'A')
    {
        powerFactor += 0;
    }
    else if (letter == 'B')
    {
        powerFactor += 2;
    }
    else if (letter == 'C')
    {
        powerFactor -= 9;
    }
    else if (letter == 'D')
    {
        powerFactor -= 7;
    }
    else if (letter == 'E')
    {
        powerFactor -= 5;
    }
    else if (letter == 'F')
    {
        powerFactor -= 4;
    }
    else if (letter == 'G')
    {
        powerFactor -= 2;
    }
    //printf("%i\n",n);
    powerFactor += (octave - 4) * 12;

    float power = powerFactor / 12.;
    //printf("%f\n",power);
    float Hz = round(pow(2, power) * 440);
    //printf("%.0f\n", Hz);
    return Hz; //return the frequency
}
// Determines whether a string represents a rest
bool is_rest(string s) //return true/false
{
    int restCompare = strcmp(s, ""); //compare the string s to an emply string

    if (restCompare == 0) //if the stings are the same restCompare will be 0
    {
        return true; //its a rest
    }
    else
    {
        return false; //its a note
    }
}
