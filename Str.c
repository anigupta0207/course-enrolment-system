int strle(char ch[])
{
    int i = 0, len = 0;
    while (ch[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}

int strc(char ch[], char ch2[])
{
    int len1 = strle(ch);
    int len2 = strle(ch2);
    if (len1 == len2)
    {
        for (int i = 0; i < len1; i++)
        {
            if (ch[i] != ch2[i])
            {
                return 0;
            }
        }
        return 1;
    }
    else
    return 0;
}
