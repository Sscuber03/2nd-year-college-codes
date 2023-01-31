#include <stdio.h>
#include <string.h>
#include <math.h>

int count_digits(long int key)
{
    int count = 0;
    while (key != 0)
    {

        key /= 10;
        ++count;
    }
    return count;
}

int get_Nth_digit(long int num, int pos)
{
    int digit = 0, fraction = 0, length;

    length = count_digits(num);
    fraction = num / (int)pow(10, (length - pos));
    digit = fraction % 10;

    return digit;
}

int get_digits_range(long int num, int start_pos, int count)
{
    int i, digit, number = 0, length = 0;

    length = count_digits(num);

    if ((start_pos + count) - 1 <= length)
    {
        for (i = 0; i < count; i++)
        {
            digit = get_Nth_digit(num, start_pos);
            start_pos++;
            number = number * 10;
            number = number + digit;
        }
    }

    return number;
}

int hashing_midsquare(int key, int size)
{
    int hashvalue = 0;
    int keysquare_len = 0;
    int mid_pos = 0;
    long int keysquare = key * key;

    keysquare_len = count_digits(keysquare);
    mid_pos = keysquare_len / 2;

    hashvalue = get_digits_range(keysquare, (mid_pos + 1), size);
    return hashvalue;
}

int main()
{
    printf("%d\n", hashing_midsquare(1234, 4));
    printf("%d\n", hashing_midsquare(5642, 4));
    return 0;
}