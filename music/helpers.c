// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int Denom = atoi(fraction[2]);
    int Numer = atoi(fraction[0]);

    switch (Denom)
    {
        case 8:
            return Numer;
            break;

        case 4:
            return (Numer*2);
            break;

        case 2:
            return (Numer*4);
            break;

        default:
            return 0;
    }

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char theNote = note[0];
    char octave;
    char accidental;
    char sharp = "#";
    char flat = "b";
    int powerFactor = ;

    if (strlen(note) == 3)
        {
            octave = note[2];
            accidental = note[1]

            if (strcmp(accidental, sharp) == 0)
            {
                printf("Add for the sharp");
            }
            else if (strcmp(accidental, flat) == 0)
            {
                printf("subtract for the flat");
            }

        }
        else if (strlen(note) == 2)
        {
            octave = note[1];
        }

    switch (atoi(theNote))
    {
        case "A":
            return 440;
            break;
        case "B":
            return
            break;
        case "C":
            return
            break;
        case "D":
            return
            break;
        case "E":
            return
            break;
        case "F":
            return
            break;
        case "G":
            return
            break;
    }

    //parse the string into OCTAVE
    //parse string into NOTE
    //parse string into ACCIDENTAL if necessary
    //convert with atoi()
    //calculate the frequency of the note (considering its octave)
    //A4 = 440HZ
    //Semitone increases frequency multiplying by 2^(1/12)
    //Semitone decrease divide frequency by 2^(1/12)
    //return the frequency
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //string rest = "";
    //int restCompare = strcmp(s, rest);
    int restCompare = strcmp(s, "");

    if (restCompare == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
