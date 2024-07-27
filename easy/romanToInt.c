int romanToInt(const char *s)
{
    unsigned table['X' + 1] =
    {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000,
    };

    unsigned retval = 0;

    for (unsigned i = 0; s[i]; ++i)
        retval += (table[s[i]] < table[s[i + 1]]) ? -table[s[i]] : table[s[i]];

    return retval;
}
