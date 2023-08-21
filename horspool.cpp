//horspool

#include <iostream>
#include <string>
#include <vector>


using namespace std;

const int Alph_size = 256;
void generateShiftTable(const string& pattern, vector<int>& shiftTable)
{
    int patternLen = pattern.length();
for (int i=0; i<Alph_size; i++)
{
    shiftTable[i] = patternLen;
}
for (int i = 0; i<patternLen - 1; ++i)
{
    shiftTable[pattern[i]] = patternLen - 1 -i;
 }
}

int horspool(const string& text, const string& pattern)
{
    int textLen = text.length();
    int patternLen = pattern.length();
    vector<int> shiftTable(Alph_size);
    generateShiftTable(pattern, shiftTable);
    int i = patternLen - 1;
    while(i< textLen)
    {
        int k = 0 ;
        while(k< patternLen && pattern[patternLen - 1-k] == text[i - k])
        {
            ++k;
            
        }
        if(k == patternLen)
        {
            return i - patternLen +1;
            
        }
        i += shiftTable[text[i]];
    }
    return -1;
}
int main()
{   
    string text, pattern;
    cout<<"Enter the text:";
     getline(cin, text);
    cout<<"Enter the pattern to search : ";
    getline(cin, pattern);
    int index = horspool(text, pattern);
    if (index!= -1)
    {
        cout<<"Pattern found at index " << index << endl;
    }
    else
    {
        cout<<" Pattern not found in the text" << endl;
    }
    return 0;
}
