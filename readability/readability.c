#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letter(string test);
int count_word(string text);
int count_sentence(string text);

int main(void)
{
    string text = get_string("Text: ");

    int l = count_letter(text);
    int w = count_word(text);
    int s = count_sentence(text);

    float L = (l * 100) / (float) w;
    float S = (s * 100) / (float) w;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}


// count_letter
int count_letter(string text)
{
    int x = 0;

    // return string length
    int n = strlen(text);

    // count letter
    for (int i = 0; i < n; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            x += 1;
        }
        else
        {
            x += 0;
        }
    }
    return x;
}

// count_word
int count_word(string text)
{
    int x = 0;

    // return string length
    int n = strlen(text);

    // count word
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 32)
        {
            x += 1;
        }
        else
        {
            x += 0;
        }
    }
    return x + 1;
}

// count_sentence
int count_sentence(string text)
{
    int x = 0;

    // return string length
    int n = strlen(text);

    // count letter
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            x += 1;
        }
        else
        {
            x += 0;
        }
    }
    return x;
}