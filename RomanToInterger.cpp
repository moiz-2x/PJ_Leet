#include <iostream>
#include <vector>
#include <iostream>

int convertNum(char c)
{
    int ret;
    switch (c)
        {
        case 'I':
            ret = 1;
            break;
        case 'V':
            ret = 5;
            break;
        case 'X':
            ret = 10;
            break;
        case 'L':
            ret = 50;
            break;
        case 'C':
            ret = 100;
            break;
        case 'D':
            ret = 500;
            break;
        case 'M':
            ret = 1000;
            break;
        default:
            break;
        }
    return ret;
}

int romanToInt(std::string s) 
{
    int ret = 0, i = 0, num;
    while (i < s.length())
    {
        num = convertNum(s[i]);
        if(i == (s.length()-1))
            ret += num;
        else 
        {
            if (convertNum(s[i+1]) > num)
                ret -= num;
            else
                ret += num;
        }
        i++;
    }
    return ret;
}

int main()
{
    int num = romanToInt("CMXCVIII");
    std::cout << num;
    return 0;
}