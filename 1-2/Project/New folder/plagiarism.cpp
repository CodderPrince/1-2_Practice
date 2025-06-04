/*
Plagiarism Project
Name: Md. An Nahian Prince
ID: 12105007
Reg: 000015540
Language: C++

Concept:
1. One Base File
2. Some others file [This project 5 file]
3. Compare Base File to All files
4. Print separate plagiarism and similar sentences for every file
5. Finally print avearage plagiarism of all the files
*/

#include <bits\stdc++.h>
using namespace std;

int i, j;

// Separate every sentence for base
vector<string> spilitS(const string &text)
{
    vector<string> sentence;
    string currentSentence;
    for (i = 0; i < text.size(); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence.push_back(currentSentence + text[i]);
            currentSentence.clear();
        }
        // special case for 'and' conjunction
        else if (text[i] == 'a' && text[i + 1] == 'n' && text[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text[i] == 'a' && text[i + 1] == 'f' && text[i + 2] == 't' && text[i + 3] == 'e' && text[i + 4] == 'r')
        {
            currentSentence += "after";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text[i] == 'a' && text[i + 1] == 'l' && text[i + 2] == 't' && text[i + 3] == 'h' && text[i + 4] == 'o' && text[i + 5] == 'u' && text[i + 6] == 'g' && text[i + 7] == 'h')
        {
            currentSentence += "although";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text[i] == 'a' && text[i + 1] == 'n' && text[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text[i] == 'a' && text[i + 1] == 's')
        {
            currentSentence += "as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text[i] == 'a' && text[i + 1] == 's' && text[i + 2] == 'i' && text[i + 3] == 'f')
        {
            currentSentence += "as if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 'a' && text[i + 1] == 's' && text[i + 2] == 'l' && text[i + 3] == 'o' && text[i + 4] == 'n' && text[i + 5] == 'g' && text[i + 6] == 'a' && text[i + 7] == 's')
        {
            currentSentence += "as long as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text[i] == 'a' && text[i + 1] == 's' && text[i + 2] == 's' && text[i + 3] == 'o' && text[i + 4] == 'o' && text[i + 5] == 'n' && text[i + 6] == 'a' && text[i + 7] == 's')
        {
            currentSentence += "as soon as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text[i] == 'a' && text[i + 1] == 's' && text[i + 2] == 't' && text[i + 3] == 'h' && text[i + 4] == 'o' && text[i + 5] == 'u' && text[i + 6] == 'g' && text[i + 7] == 'h')
        {
            currentSentence += "as though";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text[i] == 'a' && text[i + 1] == 't')
        {
            currentSentence += "at";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text[i] == 'b' && text[i + 1] == 'e' && text[i + 2] == 'c' && text[i + 3] == 'a' && text[i + 4] == 'u' && text[i + 5] == 's' && text[i + 6] == 'e')
        {
            currentSentence += "because";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'b' && text[i + 1] == 'e' && text[i + 2] == 'f' && text[i + 3] == 'o' && text[i + 4] == 'r' && text[i + 5] == 'e')
        {
            currentSentence += "before";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text[i] == 'b' && text[i + 1] == 'e' && text[i + 2] == 's' && text[i + 3] == 'i' && text[i + 4] == 'd' && text[i + 5] == 'e' && text[i + 6] == 's')
        {
            currentSentence += "besides";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'b' && text[i + 1] == 'u' && text[i + 2] == 't')
        {
            currentSentence += "but";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text[i] == 'e' && text[i + 1] == 'v' && text[i + 2] == 'e' && text[i + 3] == 'n' && text[i + 4] == ' ' && text[i + 5] == 'i' && text[i + 6] == 'f')
        {
            currentSentence += "even if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'e' && text[i + 1] == 'v' && text[i + 2] == 'e' && text[i + 3] == 'n' && text[i + 4] == ' ' && text[i + 5] == 't' && text[i + 6] == 'h' && text[i + 7] == 'o' && text[i + 8] == 'u' && text[i + 9] == 'g' && text[i + 10] == 'h')
        {
            currentSentence += "even though";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }
        else if (text[i] == 'e' && text[i + 1] == 'x' && text[i + 2] == 'c' && text[i + 3] == 'e' && text[i + 4] == 'p' && text[i + 5] == 't')
        {
            currentSentence += "except";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text[i] == 'f' && text[i + 1] == 'o' && text[i + 2] == 'r')
        {
            currentSentence += "for";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text[i] == 'f' && text[i + 1] == 'o' && text[i + 2] == 'r' && text[i + 3] == 'a' && text[i + 4] == 's' && text[i + 5] == 'm' && text[i + 6] == 'u' && text[i + 7] == 'c' && text[i + 8] == 'h' && text[i + 9] == ' ' && text[i + 10] == 'a' && text[i + 11] == 's')
        {
            currentSentence += "forasmuch as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }
        else if (text[i] == 'h' && text[i + 1] == 'o' && text[i + 2] == 'w' && text[i + 3] == 'b' && text[i + 4] == 'e' && text[i + 5] == 'i' && text[i + 6] == 't')
        {
            currentSentence += "howbeit";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'i' && text[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == ' ' && text[i + 3] == 'c' && text[i + 4] == 'a' && text[i + 5] == 's' && text[i + 6] == 'e')
        {
            currentSentence += "in case";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == ' ' && text[i + 3] == 'o' && text[i + 4] == 'r' && text[i + 5] == 'd' && text[i + 6] == 'e' && text[i + 7] == 'r' && text[i + 8] == ' ' && text[i + 9] == 't' && text[i + 10] == 'h' && text[i + 11] == 'a' && text[i + 12] == 't')
        {
            currentSentence += "in order that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text[i] == 'i' && text[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text[i] == 'l' && text[i + 1] == 'e' && text[i + 2] == 's' && text[i + 3] == 't')
        {
            currentSentence += "lest";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 'n' && text[i + 1] == 'o' && text[i + 2] == 'w' && text[i + 3] == ' ' && text[i + 4] == 't' && text[i + 5] == 'h' && text[i + 6] == 'a' && text[i + 7] == 't')
        {
            currentSentence += "now that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text[i] == 'o' && text[i + 1] == 'n' && text[i + 2] == 'c' && text[i + 3] == 'e')
        {
            currentSentence += "once";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 'o' && text[i + 1] == 'n' && text[i + 2] == 'l' && text[i + 3] == 'y' && text[i + 4] == ' ' && text[i + 5] == 'i' && text[i + 6] == 'f')
        {
            currentSentence += "only if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'p' && text[i + 1] == 'r' && text[i + 2] == 'o' && text[i + 3] == 'v' && text[i + 4] == 'i' && text[i + 5] == 'd' && text[i + 6] == 'e' && text[i + 7] == 'd' && text[i + 8] == ' ' && text[i + 9] == 't' && text[i + 10] == 'h' && text[i + 11] == 'a' && text[i + 12] == 't')
        {
            currentSentence += "provided that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text[i] == 's' && text[i + 1] == 'i' && text[i + 2] == 'n' && text[i + 3] == 'c' && text[i + 4] == 'e')
        {
            currentSentence += "since";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text[i] == 's' && text[i + 1] == 'o')
        {
            currentSentence += "so";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text[i] == 's' && text[i + 1] == 'o' && text[i + 2] == ' ' && text[i + 3] == 't' && text[i + 4] == 'h' && text[i + 5] == 'a' && text[i + 6] == 't')
        {
            currentSentence += "so that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 's' && text[i + 1] == 'u' && text[i + 2] == 'p' && text[i + 3] == 'p' && text[i + 4] == 'o' && text[i + 5] == 's' && text[i + 6] == 'i' && text[i + 7] == 'n' && text[i + 8] == 'g')
        {
            currentSentence += "supposing";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }
        else if (text[i] == 't' && text[i + 1] == 'h' && text[i + 2] == 'a' && text[i + 3] == 'n')
        {
            currentSentence += "than";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 't' && text[i + 1] == 'h' && text[i + 2] == 'e' && text[i + 3] == 'n')
        {
            currentSentence += "then";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 't' && text[i + 1] == 'h' && text[i + 2] == 'e' && text[i + 3] == 'r' && text[i + 4] == 'e' && text[i + 5] == ' ' && text[i + 6] == 'f' && text[i + 7] == 'o' && text[i + 8] == 'r' && text[i + 9] == 'e')
        {
            currentSentence += "therefore";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }
        else if (text[i] == 't' && text[i + 1] == 'i' && text[i + 2] == 'l' && text[i + 3] == 'l')
        {
            currentSentence += "till";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 'u' && text[i + 1] == 'n' && text[i + 2] == 'l' && text[i + 3] == 'e' && text[i + 4] == 's' && text[i + 5] == 's')
        {
            currentSentence += "unless";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text[i] == 'u' && text[i + 1] == 'n' && text[i + 2] == 't' && text[i + 3] == 'i' && text[i + 4] == 'l')
        {
            currentSentence += "until";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text[i] == 'w' && text[i + 1] == 'e' && text[i + 2] == 'h' && text[i + 3] == 'e' && text[i + 4] == 'n')
        {
            currentSentence += "when";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text[i] == 'w' && text[i + 1] == 'h' && text[i + 2] == 'e' && text[i + 3] == 'n' && text[i + 4] == 'e' && text[i + 5] == 'v' && text[i + 6] == 'e' && text[i + 7] == 'r')
        {
            currentSentence += "whenever";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text[i] == 'w' && text[i + 1] == 'h' && text[i + 2] == 'e' && text[i + 3] == 'r' && text[i + 4] == 'e')
        {
            currentSentence += "where";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text[i] == 'w' && text[i + 1] == 'h' && text[i + 2] == 'e' && text[i + 3] == 't' && text[i + 4] == 'h' && text[i + 5] == 'e' && text[i + 6] == 'r')
        {
            currentSentence += "whether";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text[i] == 'w' && text[i + 1] == 'h' && text[i + 2] == 'i' && text[i + 3] == 'l' && text[i + 4] == 'e')
        {
            currentSentence += "while";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text[i] == 'w' && text[i + 1] == 'i' && text[i + 2] == 't' && text[i + 3] == 'h')
        {
            currentSentence += "with";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text[i] == 'y' && text[i + 1] == 'e' && text[i + 2] == 't')
        {
            currentSentence += "yet";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }

        else
        {
            currentSentence += tolower(text[i]);
        }
    }
    return sentence;
}

// Separate every sentence for document 1
vector<string> spilitS1(const string &text1)
{
    vector<string> sentence1;
    string currentSentence;
    for (i = 0; i < text1.size(); i++)
    {
        if (text1[i] == '.' || text1[i] == '!' || text1[i] == '?')
        {
            sentence1.push_back(currentSentence + text1[i]);
            currentSentence.clear();
        }
        // special case for 'and' conjunction
        else if (text1[i] == 'a' && text1[i + 1] == 'n' && text1[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 'f' && text1[i + 2] == 't' && text1[i + 3] == 'e' && text1[i + 4] == 'r')
        {
            currentSentence += "after";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 'l' && text1[i + 2] == 't' && text1[i + 3] == 'h' && text1[i + 4] == 'o' && text1[i + 5] == 'u' && text1[i + 6] == 'g' && text1[i + 7] == 'h')
        {
            currentSentence += "although";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 'n' && text1[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 's')
        {
            currentSentence += "as";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 's' && text1[i + 2] == 'i' && text1[i + 3] == 'f')
        {
            currentSentence += "as if";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 's' && text1[i + 2] == 'l' && text1[i + 3] == 'o' && text1[i + 4] == 'n' && text1[i + 5] == 'g' && text1[i + 6] == 'a' && text1[i + 7] == 's')
        {
            currentSentence += "as long as";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 's' && text1[i + 2] == 's' && text1[i + 3] == 'o' && text1[i + 4] == 'o' && text1[i + 5] == 'n' && text1[i + 6] == 'a' && text1[i + 7] == 's')
        {
            currentSentence += "as soon as";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 's' && text1[i + 2] == 't' && text1[i + 3] == 'h' && text1[i + 4] == 'o' && text1[i + 5] == 'u' && text1[i + 6] == 'g' && text1[i + 7] == 'h')
        {
            currentSentence += "as though";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text1[i] == 'a' && text1[i + 1] == 't')
        {
            currentSentence += "at";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text1[i] == 'b' && text1[i + 1] == 'e' && text1[i + 2] == 'c' && text1[i + 3] == 'a' && text1[i + 4] == 'u' && text1[i + 5] == 's' && text1[i + 6] == 'e')
        {
            currentSentence += "because";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'b' && text1[i + 1] == 'e' && text1[i + 2] == 'f' && text1[i + 3] == 'o' && text1[i + 4] == 'r' && text1[i + 5] == 'e')
        {
            currentSentence += "before";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text1[i] == 'b' && text1[i + 1] == 'e' && text1[i + 2] == 's' && text1[i + 3] == 'i' && text1[i + 4] == 'd' && text1[i + 5] == 'e' && text1[i + 6] == 's')
        {
            currentSentence += "besides";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'b' && text1[i + 1] == 'u' && text1[i + 2] == 't')
        {
            currentSentence += "but";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text1[i] == 'e' && text1[i + 1] == 'v' && text1[i + 2] == 'e' && text1[i + 3] == 'n' && text1[i + 4] == ' ' && text1[i + 5] == 'i' && text1[i + 6] == 'f')
        {
            currentSentence += "even if";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'e' && text1[i + 1] == 'v' && text1[i + 2] == 'e' && text1[i + 3] == 'n' && text1[i + 4] == ' ' && text1[i + 5] == 't' && text1[i + 6] == 'h' && text1[i + 7] == 'o' && text1[i + 8] == 'u' && text1[i + 9] == 'g' && text1[i + 10] == 'h')
        {
            currentSentence += "even though";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }
        else if (text1[i] == 'e' && text1[i + 1] == 'x' && text1[i + 2] == 'c' && text1[i + 3] == 'e' && text1[i + 4] == 'p' && text1[i + 5] == 't')
        {
            currentSentence += "except";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text1[i] == 'f' && text1[i + 1] == 'o' && text1[i + 2] == 'r')
        {
            currentSentence += "for";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text1[i] == 'f' && text1[i + 1] == 'o' && text1[i + 2] == 'r' && text1[i + 3] == 'a' && text1[i + 4] == 's' && text1[i + 5] == 'm' && text1[i + 6] == 'u' && text1[i + 7] == 'c' && text1[i + 8] == 'h' && text1[i + 9] == ' ' && text1[i + 10] == 'a' && text1[i + 11] == 's')
        {
            currentSentence += "forasmuch as";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }
        else if (text1[i] == 'h' && text1[i + 1] == 'o' && text1[i + 2] == 'w' && text1[i + 3] == 'b' && text1[i + 4] == 'e' && text1[i + 5] == 'i' && text1[i + 6] == 't')
        {
            currentSentence += "howbeit";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'i' && text1[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text1[i] == 'i' && text1[i + 1] == 'n' && text1[i + 2] == ' ' && text1[i + 3] == 'c' && text1[i + 4] == 'a' && text1[i + 5] == 's' && text1[i + 6] == 'e')
        {
            currentSentence += "in case";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'i' && text1[i + 1] == 'n' && text1[i + 2] == ' ' && text1[i + 3] == 'o' && text1[i + 4] == 'r' && text1[i + 5] == 'd' && text1[i + 6] == 'e' && text1[i + 7] == 'r' && text1[i + 8] == ' ' && text1[i + 9] == 't' && text1[i + 10] == 'h' && text1[i + 11] == 'a' && text1[i + 12] == 't')
        {
            currentSentence += "in order that";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text1[i] == 'i' && text1[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text1[i] == 'l' && text1[i + 1] == 'e' && text1[i + 2] == 's' && text1[i + 3] == 't')
        {
            currentSentence += "lest";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 'n' && text1[i + 1] == 'o' && text1[i + 2] == 'w' && text1[i + 3] == ' ' && text1[i + 4] == 't' && text1[i + 5] == 'h' && text1[i + 6] == 'a' && text1[i + 7] == 't')
        {
            currentSentence += "now that";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text1[i] == 'o' && text1[i + 1] == 'n' && text1[i + 2] == 'c' && text1[i + 3] == 'e')
        {
            currentSentence += "once";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 'o' && text1[i + 1] == 'n' && text1[i + 2] == 'l' && text1[i + 3] == 'y' && text1[i + 4] == ' ' && text1[i + 5] == 'i' && text1[i + 6] == 'f')
        {
            currentSentence += "only if";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'p' && text1[i + 1] == 'r' && text1[i + 2] == 'o' && text1[i + 3] == 'v' && text1[i + 4] == 'i' && text1[i + 5] == 'd' && text1[i + 6] == 'e' && text1[i + 7] == 'd' && text1[i + 8] == ' ' && text1[i + 9] == 't' && text1[i + 10] == 'h' && text1[i + 11] == 'a' && text1[i + 12] == 't')
        {
            currentSentence += "provided that";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text1[i] == 's' && text1[i + 1] == 'i' && text1[i + 2] == 'n' && text1[i + 3] == 'c' && text1[i + 4] == 'e')
        {
            currentSentence += "since";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == 's' && text1[i + 1] == 'o')
        {
            currentSentence += "so";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text1[i] == 's' && text1[i + 1] == 'o' && text1[i + 2] == ' ' && text1[i + 3] == 't' && text1[i + 4] == 'h' && text1[i + 5] == 'a' && text1[i + 6] == 't')
        {
            currentSentence += "so that";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 's' && text1[i + 1] == 'u' && text1[i + 2] == 'p' && text1[i + 3] == 'p' && text1[i + 4] == 'o' && text1[i + 5] == 's' && text1[i + 6] == 'i' && text1[i + 7] == 'n' && text1[i + 8] == 'g')
        {
            currentSentence += "supposing";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }
        else if (text1[i] == 't' && text1[i + 1] == 'h' && text1[i + 2] == 'a' && text1[i + 3] == 'n')
        {
            currentSentence += "than";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 't' && text1[i + 1] == 'h' && text1[i + 2] == 'e' && text1[i + 3] == 'n')
        {
            currentSentence += "then";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 't' && text1[i + 1] == 'h' && text1[i + 2] == 'e' && text1[i + 3] == 'r' && text1[i + 4] == 'e' && text1[i + 5] == ' ' && text1[i + 6] == 'f' && text1[i + 7] == 'o' && text1[i + 8] == 'r' && text1[i + 9] == 'e')
        {
            currentSentence += "therefore";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }
        else if (text1[i] == 't' && text1[i + 1] == 'i' && text1[i + 2] == 'l' && text1[i + 3] == 'l')
        {
            currentSentence += "till";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 'u' && text1[i + 1] == 'n' && text1[i + 2] == 'l' && text1[i + 3] == 'e' && text1[i + 4] == 's' && text1[i + 5] == 's')
        {
            currentSentence += "unless";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text1[i] == 'u' && text1[i + 1] == 'n' && text1[i + 2] == 't' && text1[i + 3] == 'i' && text1[i + 4] == 'l')
        {
            currentSentence += "until";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == 'w' && text1[i + 1] == 'e' && text1[i + 2] == 'h' && text1[i + 3] == 'e' && text1[i + 4] == 'n')
        {
            currentSentence += "when";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == 'w' && text1[i + 1] == 'h' && text1[i + 2] == 'e' && text1[i + 3] == 'n' && text1[i + 4] == 'e' && text1[i + 5] == 'v' && text1[i + 6] == 'e' && text1[i + 7] == 'r')
        {
            currentSentence += "whenever";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text1[i] == 'w' && text1[i + 1] == 'h' && text1[i + 2] == 'e' && text1[i + 3] == 'r' && text1[i + 4] == 'e')
        {
            currentSentence += "where";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == 'w' && text1[i + 1] == 'h' && text1[i + 2] == 'e' && text1[i + 3] == 't' && text1[i + 4] == 'h' && text1[i + 5] == 'e' && text1[i + 6] == 'r')
        {
            currentSentence += "whether";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text1[i] == 'w' && text1[i + 1] == 'h' && text1[i + 2] == 'i' && text1[i + 3] == 'l' && text1[i + 4] == 'e')
        {
            currentSentence += "while";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == 'w' && text1[i + 1] == 'i' && text1[i + 2] == 't' && text1[i + 3] == 'h')
        {
            currentSentence += "with";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text1[i] == 'y' && text1[i + 1] == 'e' && text1[i + 2] == 't')
        {
            currentSentence += "yet";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }

        else
        {
            currentSentence += tolower(text1[i]);
        }
    }
    return sentence1;
}

// Separate every sentence for document 2
vector<string> spilitS2(const string &text2)
{
    vector<string> sentence2;
    string currentSentence;
    for (i = 0; i < text2.size(); i++)
    {
        if (text2[i] == '.' || text2[i] == '!' || text2[i] == '?')
        {
            sentence2.push_back(currentSentence + text2[i]);
            currentSentence.clear();
        }
        else if (text2[i] == 'a' && text2[i + 1] == 'f' && text2[i + 2] == 't' && text2[i + 3] == 'e' && text2[i + 4] == 'r')
        {
            currentSentence += "after";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 'l' && text2[i + 2] == 't' && text2[i + 3] == 'h' && text2[i + 4] == 'o' && text2[i + 5] == 'u' && text2[i + 6] == 'g' && text2[i + 7] == 'h')
        {
            currentSentence += "although";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 'n' && text2[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 's')
        {
            currentSentence += "as";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 's' && text2[i + 2] == 'i' && text2[i + 3] == 'f')
        {
            currentSentence += "as if";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 's' && text2[i + 2] == 'l' && text2[i + 3] == 'o' && text2[i + 4] == 'n' && text2[i + 5] == 'g' && text2[i + 6] == 'a' && text2[i + 7] == 's')
        {
            currentSentence += "as long as";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 's' && text2[i + 2] == 's' && text2[i + 3] == 'o' && text2[i + 4] == 'o' && text2[i + 5] == 'n' && text2[i + 6] == 'a' && text2[i + 7] == 's')
        {
            currentSentence += "as soon as";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 's' && text2[i + 2] == 't' && text2[i + 3] == 'h' && text2[i + 4] == 'o' && text2[i + 5] == 'u' && text2[i + 6] == 'g' && text2[i + 7] == 'h')
        {
            currentSentence += "as though";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text2[i] == 'a' && text2[i + 1] == 't')
        {
            currentSentence += "at";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text2[i] == 'b' && text2[i + 1] == 'e' && text2[i + 2] == 'c' && text2[i + 3] == 'a' && text2[i + 4] == 'u' && text2[i + 5] == 's' && text2[i + 6] == 'e')
        {
            currentSentence += "because";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'b' && text2[i + 1] == 'e' && text2[i + 2] == 'f' && text2[i + 3] == 'o' && text2[i + 4] == 'r' && text2[i + 5] == 'e')
        {
            currentSentence += "before";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text2[i] == 'b' && text2[i + 1] == 'e' && text2[i + 2] == 's' && text2[i + 3] == 'i' && text2[i + 4] == 'd' && text2[i + 5] == 'e' && text2[i + 6] == 's')
        {
            currentSentence += "besides";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'b' && text2[i + 1] == 'u' && text2[i + 2] == 't')
        {
            currentSentence += "but";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text2[i] == 'e' && text2[i + 1] == 'v' && text2[i + 2] == 'e' && text2[i + 3] == 'n' && text2[i + 4] == ' ' && text2[i + 5] == 'i' && text2[i + 6] == 'f')
        {
            currentSentence += "even if";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'e' && text2[i + 1] == 'v' && text2[i + 2] == 'e' && text2[i + 3] == 'n' && text2[i + 4] == ' ' && text2[i + 5] == 't' && text2[i + 6] == 'h' && text2[i + 7] == 'o' && text2[i + 8] == 'u' && text2[i + 9] == 'g' && text2[i + 10] == 'h')
        {
            currentSentence += "even though";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }
        else if (text2[i] == 'e' && text2[i + 1] == 'x' && text2[i + 2] == 'c' && text2[i + 3] == 'e' && text2[i + 4] == 'p' && text2[i + 5] == 't')
        {
            currentSentence += "except";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text2[i] == 'f' && text2[i + 1] == 'o' && text2[i + 2] == 'r')
        {
            currentSentence += "for";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text2[i] == 'f' && text2[i + 1] == 'o' && text2[i + 2] == 'r' && text2[i + 3] == 'a' && text2[i + 4] == 's' && text2[i + 5] == 'm' && text2[i + 6] == 'u' && text2[i + 7] == 'c' && text2[i + 8] == 'h' && text2[i + 9] == ' ' && text2[i + 10] == 'a' && text2[i + 11] == 's')
        {
            currentSentence += "forasmuch as";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }
        else if (text2[i] == 'h' && text2[i + 1] == 'o' && text2[i + 2] == 'w' && text2[i + 3] == 'b' && text2[i + 4] == 'e' && text2[i + 5] == 'i' && text2[i + 6] == 't')
        {
            currentSentence += "howbeit";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'i' && text2[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text2[i] == 'i' && text2[i + 1] == 'n' && text2[i + 2] == ' ' && text2[i + 3] == 'c' && text2[i + 4] == 'a' && text2[i + 5] == 's' && text2[i + 6] == 'e')
        {
            currentSentence += "in case";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'i' && text2[i + 1] == 'n' && text2[i + 2] == ' ' && text2[i + 3] == 'o' && text2[i + 4] == 'r' && text2[i + 5] == 'd' && text2[i + 6] == 'e' && text2[i + 7] == 'r' && text2[i + 8] == ' ' && text2[i + 9] == 't' && text2[i + 10] == 'h' && text2[i + 11] == 'a' && text2[i + 12] == 't')
        {
            currentSentence += "in order that";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text2[i] == 'i' && text2[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text2[i] == 'l' && text2[i + 1] == 'e' && text2[i + 2] == 's' && text2[i + 3] == 't')
        {
            currentSentence += "lest";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 'n' && text2[i + 1] == 'o' && text2[i + 2] == 'w' && text2[i + 3] == ' ' && text2[i + 4] == 't' && text2[i + 5] == 'h' && text2[i + 6] == 'a' && text2[i + 7] == 't')
        {
            currentSentence += "now that";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text2[i] == 'o' && text2[i + 1] == 'n' && text2[i + 2] == 'c' && text2[i + 3] == 'e')
        {
            currentSentence += "once";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 'o' && text2[i + 1] == 'n' && text2[i + 2] == 'l' && text2[i + 3] == 'y' && text2[i + 4] == ' ' && text2[i + 5] == 'i' && text2[i + 6] == 'f')
        {
            currentSentence += "only if";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'p' && text2[i + 1] == 'r' && text2[i + 2] == 'o' && text2[i + 3] == 'v' && text2[i + 4] == 'i' && text2[i + 5] == 'd' && text2[i + 6] == 'e' && text2[i + 7] == 'd' && text2[i + 8] == ' ' && text2[i + 9] == 't' && text2[i + 10] == 'h' && text2[i + 11] == 'a' && text2[i + 12] == 't')
        {
            currentSentence += "provided that";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text2[i] == 's' && text2[i + 1] == 'i' && text2[i + 2] == 'n' && text2[i + 3] == 'c' && text2[i + 4] == 'e')
        {
            currentSentence += "since";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == 's' && text2[i + 1] == 'o')
        {
            currentSentence += "so";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text2[i] == 's' && text2[i + 1] == 'o' && text2[i + 2] == ' ' && text2[i + 3] == 't' && text2[i + 4] == 'h' && text2[i + 5] == 'a' && text2[i + 6] == 't')
        {
            currentSentence += "so that";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 's' && text2[i + 1] == 'u' && text2[i + 2] == 'p' && text2[i + 3] == 'p' && text2[i + 4] == 'o' && text2[i + 5] == 's' && text2[i + 6] == 'i' && text2[i + 7] == 'n' && text2[i + 8] == 'g')
        {
            currentSentence += "supposing";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }
        else if (text2[i] == 't' && text2[i + 1] == 'h' && text2[i + 2] == 'a' && text2[i + 3] == 'n')
        {
            currentSentence += "than";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 't' && text2[i + 1] == 'h' && text2[i + 2] == 'e' && text2[i + 3] == 'n')
        {
            currentSentence += "then";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 't' && text2[i + 1] == 'h' && text2[i + 2] == 'e' && text2[i + 3] == 'r' && text2[i + 4] == 'e' && text2[i + 5] == ' ' && text2[i + 6] == 'f' && text2[i + 7] == 'o' && text2[i + 8] == 'r' && text2[i + 9] == 'e')
        {
            currentSentence += "therefore";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }
        else if (text2[i] == 't' && text2[i + 1] == 'i' && text2[i + 2] == 'l' && text2[i + 3] == 'l')
        {
            currentSentence += "till";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 'u' && text2[i + 1] == 'n' && text2[i + 2] == 'l' && text2[i + 3] == 'e' && text2[i + 4] == 's' && text2[i + 5] == 's')
        {
            currentSentence += "unless";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text2[i] == 'u' && text2[i + 1] == 'n' && text2[i + 2] == 't' && text2[i + 3] == 'i' && text2[i + 4] == 'l')
        {
            currentSentence += "until";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == 'w' && text2[i + 1] == 'e' && text2[i + 2] == 'h' && text2[i + 3] == 'e' && text2[i + 4] == 'n')
        {
            currentSentence += "when";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == 'w' && text2[i + 1] == 'h' && text2[i + 2] == 'e' && text2[i + 3] == 'n' && text2[i + 4] == 'e' && text2[i + 5] == 'v' && text2[i + 6] == 'e' && text2[i + 7] == 'r')
        {
            currentSentence += "whenever";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text2[i] == 'w' && text2[i + 1] == 'h' && text2[i + 2] == 'e' && text2[i + 3] == 'r' && text2[i + 4] == 'e')
        {
            currentSentence += "where";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == 'w' && text2[i + 1] == 'h' && text2[i + 2] == 'e' && text2[i + 3] == 't' && text2[i + 4] == 'h' && text2[i + 5] == 'e' && text2[i + 6] == 'r')
        {
            currentSentence += "whether";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text2[i] == 'w' && text2[i + 1] == 'h' && text2[i + 2] == 'i' && text2[i + 3] == 'l' && text2[i + 4] == 'e')
        {
            currentSentence += "while";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == 'w' && text2[i + 1] == 'i' && text2[i + 2] == 't' && text2[i + 3] == 'h')
        {
            currentSentence += "with";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text2[i] == 'y' && text2[i + 1] == 'e' && text2[i + 2] == 't')
        {
            currentSentence += "yet";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }

        else
        {
            currentSentence += tolower(text2[i]);
        }
    }
    return sentence2;
}

// Separate every sentence for document 3
vector<string> spilitS3(const string &text3)
{
    vector<string> sentence3;
    string currentSentence;
    for (i = 0; i < text3.size(); i++)
    {
        if (text3[i] == '.' || text3[i] == '!' || text3[i] == '?')
        {
            sentence3.push_back(currentSentence + text3[i]);
            currentSentence.clear();
        }
        else if (text3[i] == 'a' && text3[i + 1] == 'f' && text3[i + 2] == 't' && text3[i + 3] == 'e' && text3[i + 4] == 'r')
        {
            currentSentence += "after";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 'l' && text3[i + 2] == 't' && text3[i + 3] == 'h' && text3[i + 4] == 'o' && text3[i + 5] == 'u' && text3[i + 6] == 'g' && text3[i + 7] == 'h')
        {
            currentSentence += "although";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 'n' && text3[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 's')
        {
            currentSentence += "as";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 's' && text3[i + 2] == 'i' && text3[i + 3] == 'f')
        {
            currentSentence += "as if";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 's' && text3[i + 2] == 'l' && text3[i + 3] == 'o' && text3[i + 4] == 'n' && text3[i + 5] == 'g' && text3[i + 6] == 'a' && text3[i + 7] == 's')
        {
            currentSentence += "as long as";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 's' && text3[i + 2] == 's' && text3[i + 3] == 'o' && text3[i + 4] == 'o' && text3[i + 5] == 'n' && text3[i + 6] == 'a' && text3[i + 7] == 's')
        {
            currentSentence += "as soon as";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 's' && text3[i + 2] == 't' && text3[i + 3] == 'h' && text3[i + 4] == 'o' && text3[i + 5] == 'u' && text3[i + 6] == 'g' && text3[i + 7] == 'h')
        {
            currentSentence += "as though";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text3[i] == 'a' && text3[i + 1] == 't')
        {
            currentSentence += "at";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text3[i] == 'b' && text3[i + 1] == 'e' && text3[i + 2] == 'c' && text3[i + 3] == 'a' && text3[i + 4] == 'u' && text3[i + 5] == 's' && text3[i + 6] == 'e')
        {
            currentSentence += "because";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'b' && text3[i + 1] == 'e' && text3[i + 2] == 'f' && text3[i + 3] == 'o' && text3[i + 4] == 'r' && text3[i + 5] == 'e')
        {
            currentSentence += "before";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text3[i] == 'b' && text3[i + 1] == 'e' && text3[i + 2] == 's' && text3[i + 3] == 'i' && text3[i + 4] == 'd' && text3[i + 5] == 'e' && text3[i + 6] == 's')
        {
            currentSentence += "besides";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'b' && text3[i + 1] == 'u' && text3[i + 2] == 't')
        {
            currentSentence += "but";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text3[i] == 'e' && text3[i + 1] == 'v' && text3[i + 2] == 'e' && text3[i + 3] == 'n' && text3[i + 4] == ' ' && text3[i + 5] == 'i' && text3[i + 6] == 'f')
        {
            currentSentence += "even if";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'e' && text3[i + 1] == 'v' && text3[i + 2] == 'e' && text3[i + 3] == 'n' && text3[i + 4] == ' ' && text3[i + 5] == 't' && text3[i + 6] == 'h' && text3[i + 7] == 'o' && text3[i + 8] == 'u' && text3[i + 9] == 'g' && text3[i + 10] == 'h')
        {
            currentSentence += "even though";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }
        else if (text3[i] == 'e' && text3[i + 1] == 'x' && text3[i + 2] == 'c' && text3[i + 3] == 'e' && text3[i + 4] == 'p' && text3[i + 5] == 't')
        {
            currentSentence += "except";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text3[i] == 'f' && text3[i + 1] == 'o' && text3[i + 2] == 'r')
        {
            currentSentence += "for";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text3[i] == 'f' && text3[i + 1] == 'o' && text3[i + 2] == 'r' && text3[i + 3] == 'a' && text3[i + 4] == 's' && text3[i + 5] == 'm' && text3[i + 6] == 'u' && text3[i + 7] == 'c' && text3[i + 8] == 'h' && text3[i + 9] == ' ' && text3[i + 10] == 'a' && text3[i + 11] == 's')
        {
            currentSentence += "forasmuch as";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }
        else if (text3[i] == 'h' && text3[i + 1] == 'o' && text3[i + 2] == 'w' && text3[i + 3] == 'b' && text3[i + 4] == 'e' && text3[i + 5] == 'i' && text3[i + 6] == 't')
        {
            currentSentence += "howbeit";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'i' && text3[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text3[i] == 'i' && text3[i + 1] == 'n' && text3[i + 2] == ' ' && text3[i + 3] == 'c' && text3[i + 4] == 'a' && text3[i + 5] == 's' && text3[i + 6] == 'e')
        {
            currentSentence += "in case";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'i' && text3[i + 1] == 'n' && text3[i + 2] == ' ' && text3[i + 3] == 'o' && text3[i + 4] == 'r' && text3[i + 5] == 'd' && text3[i + 6] == 'e' && text3[i + 7] == 'r' && text3[i + 8] == ' ' && text3[i + 9] == 't' && text3[i + 10] == 'h' && text3[i + 11] == 'a' && text3[i + 12] == 't')
        {
            currentSentence += "in order that";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text3[i] == 'i' && text3[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text3[i] == 'l' && text3[i + 1] == 'e' && text3[i + 2] == 's' && text3[i + 3] == 't')
        {
            currentSentence += "lest";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 'n' && text3[i + 1] == 'o' && text3[i + 2] == 'w' && text3[i + 3] == ' ' && text3[i + 4] == 't' && text3[i + 5] == 'h' && text3[i + 6] == 'a' && text3[i + 7] == 't')
        {
            currentSentence += "now that";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text3[i] == 'o' && text3[i + 1] == 'n' && text3[i + 2] == 'c' && text3[i + 3] == 'e')
        {
            currentSentence += "once";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 'o' && text3[i + 1] == 'n' && text3[i + 2] == 'l' && text3[i + 3] == 'y' && text3[i + 4] == ' ' && text3[i + 5] == 'i' && text3[i + 6] == 'f')
        {
            currentSentence += "only if";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'p' && text3[i + 1] == 'r' && text3[i + 2] == 'o' && text3[i + 3] == 'v' && text3[i + 4] == 'i' && text3[i + 5] == 'd' && text3[i + 6] == 'e' && text3[i + 7] == 'd' && text3[i + 8] == ' ' && text3[i + 9] == 't' && text3[i + 10] == 'h' && text3[i + 11] == 'a' && text3[i + 12] == 't')
        {
            currentSentence += "provided that";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text3[i] == 's' && text3[i + 1] == 'i' && text3[i + 2] == 'n' && text3[i + 3] == 'c' && text3[i + 4] == 'e')
        {
            currentSentence += "since";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == 's' && text3[i + 1] == 'o')
        {
            currentSentence += "so";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text3[i] == 's' && text3[i + 1] == 'o' && text3[i + 2] == ' ' && text3[i + 3] == 't' && text3[i + 4] == 'h' && text3[i + 5] == 'a' && text3[i + 6] == 't')
        {
            currentSentence += "so that";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 's' && text3[i + 1] == 'u' && text3[i + 2] == 'p' && text3[i + 3] == 'p' && text3[i + 4] == 'o' && text3[i + 5] == 's' && text3[i + 6] == 'i' && text3[i + 7] == 'n' && text3[i + 8] == 'g')
        {
            currentSentence += "supposing";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }
        else if (text3[i] == 't' && text3[i + 1] == 'h' && text3[i + 2] == 'a' && text3[i + 3] == 'n')
        {
            currentSentence += "than";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 't' && text3[i + 1] == 'h' && text3[i + 2] == 'e' && text3[i + 3] == 'n')
        {
            currentSentence += "then";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 't' && text3[i + 1] == 'h' && text3[i + 2] == 'e' && text3[i + 3] == 'r' && text3[i + 4] == 'e' && text3[i + 5] == ' ' && text3[i + 6] == 'f' && text3[i + 7] == 'o' && text3[i + 8] == 'r' && text3[i + 9] == 'e')
        {
            currentSentence += "therefore";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }
        else if (text3[i] == 't' && text3[i + 1] == 'i' && text3[i + 2] == 'l' && text3[i + 3] == 'l')
        {
            currentSentence += "till";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 'u' && text3[i + 1] == 'n' && text3[i + 2] == 'l' && text3[i + 3] == 'e' && text3[i + 4] == 's' && text3[i + 5] == 's')
        {
            currentSentence += "unless";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text3[i] == 'u' && text3[i + 1] == 'n' && text3[i + 2] == 't' && text3[i + 3] == 'i' && text3[i + 4] == 'l')
        {
            currentSentence += "until";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == 'w' && text3[i + 1] == 'e' && text3[i + 2] == 'h' && text3[i + 3] == 'e' && text3[i + 4] == 'n')
        {
            currentSentence += "when";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == 'w' && text3[i + 1] == 'h' && text3[i + 2] == 'e' && text3[i + 3] == 'n' && text3[i + 4] == 'e' && text3[i + 5] == 'v' && text3[i + 6] == 'e' && text3[i + 7] == 'r')
        {
            currentSentence += "whenever";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text3[i] == 'w' && text3[i + 1] == 'h' && text3[i + 2] == 'e' && text3[i + 3] == 'r' && text3[i + 4] == 'e')
        {
            currentSentence += "where";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == 'w' && text3[i + 1] == 'h' && text3[i + 2] == 'e' && text3[i + 3] == 't' && text3[i + 4] == 'h' && text3[i + 5] == 'e' && text3[i + 6] == 'r')
        {
            currentSentence += "whether";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text3[i] == 'w' && text3[i + 1] == 'h' && text3[i + 2] == 'i' && text3[i + 3] == 'l' && text3[i + 4] == 'e')
        {
            currentSentence += "while";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == 'w' && text3[i + 1] == 'i' && text3[i + 2] == 't' && text3[i + 3] == 'h')
        {
            currentSentence += "with";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text3[i] == 'y' && text3[i + 1] == 'e' && text3[i + 2] == 't')
        {
            currentSentence += "yet";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }

        else
        {
            currentSentence += tolower(text3[i]);
        }
    }
    return sentence3;
}

// Separate every sentence for document 4
vector<string> spilitS4(const string &text4)
{
    vector<string> sentence4;
    string currentSentence;
    for (i = 0; i < text4.size(); i++)
    {
        if (text4[i] == '.' || text4[i] == '!' || text4[i] == '?')
        {
            sentence4.push_back(currentSentence + text4[i]);
            currentSentence.clear();
        }
        else if (text4[i] == 'a' && text4[i + 1] == 'f' && text4[i + 2] == 't' && text4[i + 3] == 'e' && text4[i + 4] == 'r')
        {
            currentSentence += "after";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 'l' && text4[i + 2] == 't' && text4[i + 3] == 'h' && text4[i + 4] == 'o' && text4[i + 5] == 'u' && text4[i + 6] == 'g' && text4[i + 7] == 'h')
        {
            currentSentence += "although";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 'n' && text4[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 's')
        {
            currentSentence += "as";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 's' && text4[i + 2] == 'i' && text4[i + 3] == 'f')
        {
            currentSentence += "as if";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 's' && text4[i + 2] == 'l' && text4[i + 3] == 'o' && text4[i + 4] == 'n' && text4[i + 5] == 'g' && text4[i + 6] == 'a' && text4[i + 7] == 's')
        {
            currentSentence += "as long as";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 's' && text4[i + 2] == 's' && text4[i + 3] == 'o' && text4[i + 4] == 'o' && text4[i + 5] == 'n' && text4[i + 6] == 'a' && text4[i + 7] == 's')
        {
            currentSentence += "as soon as";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 's' && text4[i + 2] == 't' && text4[i + 3] == 'h' && text4[i + 4] == 'o' && text4[i + 5] == 'u' && text4[i + 6] == 'g' && text4[i + 7] == 'h')
        {
            currentSentence += "as though";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text4[i] == 'a' && text4[i + 1] == 't')
        {
            currentSentence += "at";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text4[i] == 'b' && text4[i + 1] == 'e' && text4[i + 2] == 'c' && text4[i + 3] == 'a' && text4[i + 4] == 'u' && text4[i + 5] == 's' && text4[i + 6] == 'e')
        {
            currentSentence += "because";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'b' && text4[i + 1] == 'e' && text4[i + 2] == 'f' && text4[i + 3] == 'o' && text4[i + 4] == 'r' && text4[i + 5] == 'e')
        {
            currentSentence += "before";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text4[i] == 'b' && text4[i + 1] == 'e' && text4[i + 2] == 's' && text4[i + 3] == 'i' && text4[i + 4] == 'd' && text4[i + 5] == 'e' && text4[i + 6] == 's')
        {
            currentSentence += "besides";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'b' && text4[i + 1] == 'u' && text4[i + 2] == 't')
        {
            currentSentence += "but";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text4[i] == 'e' && text4[i + 1] == 'v' && text4[i + 2] == 'e' && text4[i + 3] == 'n' && text4[i + 4] == ' ' && text4[i + 5] == 'i' && text4[i + 6] == 'f')
        {
            currentSentence += "even if";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'e' && text4[i + 1] == 'v' && text4[i + 2] == 'e' && text4[i + 3] == 'n' && text4[i + 4] == ' ' && text4[i + 5] == 't' && text4[i + 6] == 'h' && text4[i + 7] == 'o' && text4[i + 8] == 'u' && text4[i + 9] == 'g' && text4[i + 10] == 'h')
        {
            currentSentence += "even though";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }
        else if (text4[i] == 'e' && text4[i + 1] == 'x' && text4[i + 2] == 'c' && text4[i + 3] == 'e' && text4[i + 4] == 'p' && text4[i + 5] == 't')
        {
            currentSentence += "except";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text4[i] == 'f' && text4[i + 1] == 'o' && text4[i + 2] == 'r')
        {
            currentSentence += "for";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text4[i] == 'f' && text4[i + 1] == 'o' && text4[i + 2] == 'r' && text4[i + 3] == 'a' && text4[i + 4] == 's' && text4[i + 5] == 'm' && text4[i + 6] == 'u' && text4[i + 7] == 'c' && text4[i + 8] == 'h' && text4[i + 9] == ' ' && text4[i + 10] == 'a' && text4[i + 11] == 's')
        {
            currentSentence += "forasmuch as";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }
        else if (text4[i] == 'h' && text4[i + 1] == 'o' && text4[i + 2] == 'w' && text4[i + 3] == 'b' && text4[i + 4] == 'e' && text4[i + 5] == 'i' && text4[i + 6] == 't')
        {
            currentSentence += "howbeit";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'i' && text4[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text4[i] == 'i' && text4[i + 1] == 'n' && text4[i + 2] == ' ' && text4[i + 3] == 'c' && text4[i + 4] == 'a' && text4[i + 5] == 's' && text4[i + 6] == 'e')
        {
            currentSentence += "in case";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'i' && text4[i + 1] == 'n' && text4[i + 2] == ' ' && text4[i + 3] == 'o' && text4[i + 4] == 'r' && text4[i + 5] == 'd' && text4[i + 6] == 'e' && text4[i + 7] == 'r' && text4[i + 8] == ' ' && text4[i + 9] == 't' && text4[i + 10] == 'h' && text4[i + 11] == 'a' && text4[i + 12] == 't')
        {
            currentSentence += "in order that";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text4[i] == 'i' && text4[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text4[i] == 'l' && text4[i + 1] == 'e' && text4[i + 2] == 's' && text4[i + 3] == 't')
        {
            currentSentence += "lest";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 'n' && text4[i + 1] == 'o' && text4[i + 2] == 'w' && text4[i + 3] == ' ' && text4[i + 4] == 't' && text4[i + 5] == 'h' && text4[i + 6] == 'a' && text4[i + 7] == 't')
        {
            currentSentence += "now that";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text4[i] == 'o' && text4[i + 1] == 'n' && text4[i + 2] == 'c' && text4[i + 3] == 'e')
        {
            currentSentence += "once";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 'o' && text4[i + 1] == 'n' && text4[i + 2] == 'l' && text4[i + 3] == 'y' && text4[i + 4] == ' ' && text4[i + 5] == 'i' && text4[i + 6] == 'f')
        {
            currentSentence += "only if";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'p' && text4[i + 1] == 'r' && text4[i + 2] == 'o' && text4[i + 3] == 'v' && text4[i + 4] == 'i' && text4[i + 5] == 'd' && text4[i + 6] == 'e' && text4[i + 7] == 'd' && text4[i + 8] == ' ' && text4[i + 9] == 't' && text4[i + 10] == 'h' && text4[i + 11] == 'a' && text4[i + 12] == 't')
        {
            currentSentence += "provided that";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text4[i] == 's' && text4[i + 1] == 'i' && text4[i + 2] == 'n' && text4[i + 3] == 'c' && text4[i + 4] == 'e')
        {
            currentSentence += "since";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == 's' && text4[i + 1] == 'o')
        {
            currentSentence += "so";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text4[i] == 's' && text4[i + 1] == 'o' && text4[i + 2] == ' ' && text4[i + 3] == 't' && text4[i + 4] == 'h' && text4[i + 5] == 'a' && text4[i + 6] == 't')
        {
            currentSentence += "so that";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 's' && text4[i + 1] == 'u' && text4[i + 2] == 'p' && text4[i + 3] == 'p' && text4[i + 4] == 'o' && text4[i + 5] == 's' && text4[i + 6] == 'i' && text4[i + 7] == 'n' && text4[i + 8] == 'g')
        {
            currentSentence += "supposing";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }
        else if (text4[i] == 't' && text4[i + 1] == 'h' && text4[i + 2] == 'a' && text4[i + 3] == 'n')
        {
            currentSentence += "than";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 't' && text4[i + 1] == 'h' && text4[i + 2] == 'e' && text4[i + 3] == 'n')
        {
            currentSentence += "then";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 't' && text4[i + 1] == 'h' && text4[i + 2] == 'e' && text4[i + 3] == 'r' && text4[i + 4] == 'e' && text4[i + 5] == ' ' && text4[i + 6] == 'f' && text4[i + 7] == 'o' && text4[i + 8] == 'r' && text4[i + 9] == 'e')
        {
            currentSentence += "therefore";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }
        else if (text4[i] == 't' && text4[i + 1] == 'i' && text4[i + 2] == 'l' && text4[i + 3] == 'l')
        {
            currentSentence += "till";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 'u' && text4[i + 1] == 'n' && text4[i + 2] == 'l' && text4[i + 3] == 'e' && text4[i + 4] == 's' && text4[i + 5] == 's')
        {
            currentSentence += "unless";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text4[i] == 'u' && text4[i + 1] == 'n' && text4[i + 2] == 't' && text4[i + 3] == 'i' && text4[i + 4] == 'l')
        {
            currentSentence += "until";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == 'w' && text4[i + 1] == 'e' && text4[i + 2] == 'h' && text4[i + 3] == 'e' && text4[i + 4] == 'n')
        {
            currentSentence += "when";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == 'w' && text4[i + 1] == 'h' && text4[i + 2] == 'e' && text4[i + 3] == 'n' && text4[i + 4] == 'e' && text4[i + 5] == 'v' && text4[i + 6] == 'e' && text4[i + 7] == 'r')
        {
            currentSentence += "whenever";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text4[i] == 'w' && text4[i + 1] == 'h' && text4[i + 2] == 'e' && text4[i + 3] == 'r' && text4[i + 4] == 'e')
        {
            currentSentence += "where";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == 'w' && text4[i + 1] == 'h' && text4[i + 2] == 'e' && text4[i + 3] == 't' && text4[i + 4] == 'h' && text4[i + 5] == 'e' && text4[i + 6] == 'r')
        {
            currentSentence += "whether";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text4[i] == 'w' && text4[i + 1] == 'h' && text4[i + 2] == 'i' && text4[i + 3] == 'l' && text4[i + 4] == 'e')
        {
            currentSentence += "while";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == 'w' && text4[i + 1] == 'i' && text4[i + 2] == 't' && text4[i + 3] == 'h')
        {
            currentSentence += "with";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text4[i] == 'y' && text4[i + 1] == 'e' && text4[i + 2] == 't')
        {
            currentSentence += "yet";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }

        else
        {
            currentSentence += tolower(text4[i]);
        }
    }
    return sentence4;
}

// Separate every sentence for document 5
vector<string> spilitS5(const string &text5)
{
    vector<string> sentence5;
    string currentSentence;
    for (i = 0; i < text5.size(); i++)
    {
        if (text5[i] == '.' || text5[i] == '!' || text5[i] == '?')
        {
            sentence5.push_back(currentSentence + text5[i]);
            currentSentence.clear();
        }
        else if (text5[i] == 'a' && text5[i + 1] == 'f' && text5[i + 2] == 't' && text5[i + 3] == 'e' && text5[i + 4] == 'r')
        {
            currentSentence += "after";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 'l' && text5[i + 2] == 't' && text5[i + 3] == 'h' && text5[i + 4] == 'o' && text5[i + 5] == 'u' && text5[i + 6] == 'g' && text5[i + 7] == 'h')
        {
            currentSentence += "although";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 'n' && text5[i + 2] == 'd')
        {
            currentSentence += "and";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 's')
        {
            currentSentence += "as";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 's' && text5[i + 2] == 'i' && text5[i + 3] == 'f')
        {
            currentSentence += "as if";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 's' && text5[i + 2] == 'l' && text5[i + 3] == 'o' && text5[i + 4] == 'n' && text5[i + 5] == 'g' && text5[i + 6] == 'a' && text5[i + 7] == 's')
        {
            currentSentence += "as long as";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 's' && text5[i + 2] == 's' && text5[i + 3] == 'o' && text5[i + 4] == 'o' && text5[i + 5] == 'n' && text5[i + 6] == 'a' && text5[i + 7] == 's')
        {
            currentSentence += "as soon as";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 's' && text5[i + 2] == 't' && text5[i + 3] == 'h' && text5[i + 4] == 'o' && text5[i + 5] == 'u' && text5[i + 6] == 'g' && text5[i + 7] == 'h')
        {
            currentSentence += "as though";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text5[i] == 'a' && text5[i + 1] == 't')
        {
            currentSentence += "at";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text5[i] == 'b' && text5[i + 1] == 'e' && text5[i + 2] == 'c' && text5[i + 3] == 'a' && text5[i + 4] == 'u' && text5[i + 5] == 's' && text5[i + 6] == 'e')
        {
            currentSentence += "because";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'b' && text5[i + 1] == 'e' && text5[i + 2] == 'f' && text5[i + 3] == 'o' && text5[i + 4] == 'r' && text5[i + 5] == 'e')
        {
            currentSentence += "before";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text5[i] == 'b' && text5[i + 1] == 'e' && text5[i + 2] == 's' && text5[i + 3] == 'i' && text5[i + 4] == 'd' && text5[i + 5] == 'e' && text5[i + 6] == 's')
        {
            currentSentence += "besides";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'b' && text5[i + 1] == 'u' && text5[i + 2] == 't')
        {
            currentSentence += "but";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text5[i] == 'e' && text5[i + 1] == 'v' && text5[i + 2] == 'e' && text5[i + 3] == 'n' && text5[i + 4] == ' ' && text5[i + 5] == 'i' && text5[i + 6] == 'f')
        {
            currentSentence += "even if";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'e' && text5[i + 1] == 'v' && text5[i + 2] == 'e' && text5[i + 3] == 'n' && text5[i + 4] == ' ' && text5[i + 5] == 't' && text5[i + 6] == 'h' && text5[i + 7] == 'o' && text5[i + 8] == 'u' && text5[i + 9] == 'g' && text5[i + 10] == 'h')
        {
            currentSentence += "even though";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }
        else if (text5[i] == 'e' && text5[i + 1] == 'x' && text5[i + 2] == 'c' && text5[i + 3] == 'e' && text5[i + 4] == 'p' && text5[i + 5] == 't')
        {
            currentSentence += "except";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text5[i] == 'f' && text5[i + 1] == 'o' && text5[i + 2] == 'r')
        {
            currentSentence += "for";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }
        else if (text5[i] == 'f' && text5[i + 1] == 'o' && text5[i + 2] == 'r' && text5[i + 3] == 'a' && text5[i + 4] == 's' && text5[i + 5] == 'm' && text5[i + 6] == 'u' && text5[i + 7] == 'c' && text5[i + 8] == 'h' && text5[i + 9] == ' ' && text5[i + 10] == 'a' && text5[i + 11] == 's')
        {
            currentSentence += "forasmuch as";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }
        else if (text5[i] == 'h' && text5[i + 1] == 'o' && text5[i + 2] == 'w' && text5[i + 3] == 'b' && text5[i + 4] == 'e' && text5[i + 5] == 'i' && text5[i + 6] == 't')
        {
            currentSentence += "howbeit";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'i' && text5[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text5[i] == 'i' && text5[i + 1] == 'n' && text5[i + 2] == ' ' && text5[i + 3] == 'c' && text5[i + 4] == 'a' && text5[i + 5] == 's' && text5[i + 6] == 'e')
        {
            currentSentence += "in case";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'i' && text5[i + 1] == 'n' && text5[i + 2] == ' ' && text5[i + 3] == 'o' && text5[i + 4] == 'r' && text5[i + 5] == 'd' && text5[i + 6] == 'e' && text5[i + 7] == 'r' && text5[i + 8] == ' ' && text5[i + 9] == 't' && text5[i + 10] == 'h' && text5[i + 11] == 'a' && text5[i + 12] == 't')
        {
            currentSentence += "in order that";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text5[i] == 'i' && text5[i + 1] == 'f')
        {
            currentSentence += "if";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text5[i] == 'l' && text5[i + 1] == 'e' && text5[i + 2] == 's' && text5[i + 3] == 't')
        {
            currentSentence += "lest";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 'n' && text5[i + 1] == 'o' && text5[i + 2] == 'w' && text5[i + 3] == ' ' && text5[i + 4] == 't' && text5[i + 5] == 'h' && text5[i + 6] == 'a' && text5[i + 7] == 't')
        {
            currentSentence += "now that";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text5[i] == 'o' && text5[i + 1] == 'n' && text5[i + 2] == 'c' && text5[i + 3] == 'e')
        {
            currentSentence += "once";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 'o' && text5[i + 1] == 'n' && text5[i + 2] == 'l' && text5[i + 3] == 'y' && text5[i + 4] == ' ' && text5[i + 5] == 'i' && text5[i + 6] == 'f')
        {
            currentSentence += "only if";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'p' && text5[i + 1] == 'r' && text5[i + 2] == 'o' && text5[i + 3] == 'v' && text5[i + 4] == 'i' && text5[i + 5] == 'd' && text5[i + 6] == 'e' && text5[i + 7] == 'd' && text5[i + 8] == ' ' && text5[i + 9] == 't' && text5[i + 10] == 'h' && text5[i + 11] == 'a' && text5[i + 12] == 't')
        {
            currentSentence += "provided that";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }
        else if (text5[i] == 's' && text5[i + 1] == 'i' && text5[i + 2] == 'n' && text5[i + 3] == 'c' && text5[i + 4] == 'e')
        {
            currentSentence += "since";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == 's' && text5[i + 1] == 'o')
        {
            currentSentence += "so";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 1;
        }
        else if (text5[i] == 's' && text5[i + 1] == 'o' && text5[i + 2] == ' ' && text5[i + 3] == 't' && text5[i + 4] == 'h' && text5[i + 5] == 'a' && text5[i + 6] == 't')
        {
            currentSentence += "so that";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 's' && text5[i + 1] == 'u' && text5[i + 2] == 'p' && text5[i + 3] == 'p' && text5[i + 4] == 'o' && text5[i + 5] == 's' && text5[i + 6] == 'i' && text5[i + 7] == 'n' && text5[i + 8] == 'g')
        {
            currentSentence += "supposing";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }
        else if (text5[i] == 't' && text5[i + 1] == 'h' && text5[i + 2] == 'a' && text5[i + 3] == 'n')
        {
            currentSentence += "than";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 't' && text5[i + 1] == 'h' && text5[i + 2] == 'e' && text5[i + 3] == 'n')
        {
            currentSentence += "then";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 't' && text5[i + 1] == 'h' && text5[i + 2] == 'e' && text5[i + 3] == 'r' && text5[i + 4] == 'e' && text5[i + 5] == ' ' && text5[i + 6] == 'f' && text5[i + 7] == 'o' && text5[i + 8] == 'r' && text5[i + 9] == 'e')
        {
            currentSentence += "therefore";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }
        else if (text5[i] == 't' && text5[i + 1] == 'i' && text5[i + 2] == 'l' && text5[i + 3] == 'l')
        {
            currentSentence += "till";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 'u' && text5[i + 1] == 'n' && text5[i + 2] == 'l' && text5[i + 3] == 'e' && text5[i + 4] == 's' && text5[i + 5] == 's')
        {
            currentSentence += "unless";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }
        else if (text5[i] == 'u' && text5[i + 1] == 'n' && text5[i + 2] == 't' && text5[i + 3] == 'i' && text5[i + 4] == 'l')
        {
            currentSentence += "until";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == 'w' && text5[i + 1] == 'e' && text5[i + 2] == 'h' && text5[i + 3] == 'e' && text5[i + 4] == 'n')
        {
            currentSentence += "when";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == 'w' && text5[i + 1] == 'h' && text5[i + 2] == 'e' && text5[i + 3] == 'n' && text5[i + 4] == 'e' && text5[i + 5] == 'v' && text5[i + 6] == 'e' && text5[i + 7] == 'r')
        {
            currentSentence += "whenever";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }
        else if (text5[i] == 'w' && text5[i + 1] == 'h' && text5[i + 2] == 'e' && text5[i + 3] == 'r' && text5[i + 4] == 'e')
        {
            currentSentence += "where";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == 'w' && text5[i + 1] == 'h' && text5[i + 2] == 'e' && text5[i + 3] == 't' && text5[i + 4] == 'h' && text5[i + 5] == 'e' && text5[i + 6] == 'r')
        {
            currentSentence += "whether";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }
        else if (text5[i] == 'w' && text5[i + 1] == 'h' && text5[i + 2] == 'i' && text5[i + 3] == 'l' && text5[i + 4] == 'e')
        {
            currentSentence += "while";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == 'w' && text5[i + 1] == 'i' && text5[i + 2] == 't' && text5[i + 3] == 'h')
        {
            currentSentence += "with";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }
        else if (text5[i] == 'y' && text5[i + 1] == 'e' && text5[i + 2] == 't')
        {
            currentSentence += "yet";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 2;
        }

        else
        {
            currentSentence += tolower(text5[i]);
        }
    }
    return sentence5;
}

int main()
{
    string base = "base.txt";
    string file1 = "document1.txt";
    string file2 = "document2.txt";
    string file3 = "document3.txt";
    string file4 = "document4.txt";
    string file5 = "document5.txt";

    /*ifstream is a c++ class that is mainly used to input text from file*/
    ifstream b(base), f1(file1), f2(file2), f3(file3), f4(file4), f5(file5);

    /*check any error occured or not when opening file*/
    if (!b || !f1 || !f2 || !f3 || !f4 || !f5)
    {
        cout << "\nError opening file." << endl;
        return 1;
    }

    /*create string for stores every document file as a sentence line*/
    string text, text1, text2, text3, text4, text5;
    string line, line1, line2, line3, line4, line5;

    // input base file
    while (getline(b, line))
    {
        text += line;
    }
    b.close();

    // input file1
    while (getline(f1, line1))
    {
        text1 += line1;
    }
    f1.close();

    // input file2
    while (getline(f2, line2))
    {
        text2 += line2;
    }
    f2.close();

    // input file3
    while (getline(f3, line3))
    {
        text3 += line3;
    }
    f3.close();

    // input file4
    while (getline(f4, line4))
    {
        text4 += line4;
    }
    f4.close();

    // input file5
    while (getline(f5, line5))
    {
        text5 += line5;
    }
    f5.close();

    /*Base case if base file is empty then close the program*/
    if (text.empty())
    {
        cout << "\nWarning!\nBase file is empty.\n\n\n";
        return 0;
    }

    // Manage if any document is empty then print an warning message
    if (text1.empty())
    {
        cout << "\nDocument 1 is empty!\nPlease input something!\n\n";
    }

    if (text3.empty())
    {
        cout << "\nDocument 3 is empty!\nPlease input something!\n\n";
    }

    if (text4.empty())
    {
        cout << "\nDocument 4 is empty!\nPlease input something!\n\n";
    }

    if (text5.empty())
    {
        cout << "\nDocument 5 is empty!\nPlease input something!\n\n";
    }

    // create all vector string array for corresponding document
    vector<string> sentence = spilitS(text);
    vector<string> sentence1 = spilitS1(text1);
    vector<string> sentence2 = spilitS2(text2);
    vector<string> sentence3 = spilitS3(text3);
    vector<string> sentence4 = spilitS4(text4);
    vector<string> sentence5 = spilitS5(text5);

    // create all vector strings for store similar sentences
    set<string> similar1;
    set<string> similar2;
    set<string> similar3;
    set<string> similar4;
    set<string> similar5;

    // now outer loop == base file total sentences
    int tsl = sentence.size();

    // print base file
    /*cout << "\n**Base file**\n\n";
    for (i = 0; i < sentence.size(); i++)
    {
        cout << sentence[i] << endl;
    }
    cout << endl;
    cout << "\nTotal Sentences in Base File: " << tsl << "\n\n";
    /*

    /*Compare document1 to base file and print the output*/
    int sim1 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence1.size(); j++)
        {
            // Sorting the sentences before comparison
            /*use sort function so that when compare two sentences
            then avoid consequtives words used or not?*/

            if (sentence[i] == sentence1[j])
            {
                similar1.insert(sentence[i]);
                sim1++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 1: " << sim1 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar1.begin(); it != similar1.end(); it++)
    {
        int count = count_if(sentence1.begin(), sentence1.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    // base case
    if (sim1 == 0)
    {
        cout << "\nPlagiarism for document1: 0.0%\n\n";
    }

    double sim1ilarity1 = static_cast<double>(sim1) / tsl * 100;
    /*if similiar sentences is 0 then already printed in above*/
    if (sim1 != 0)
    {
        cout << "\nPlagiarism for document1: " << fixed << setprecision(2) << sim1ilarity1 << "%\n\n";
    }

    /*Compare document2 to base file and print the output*/
    int sim2 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence2.size(); j++)
        {
            // Sorting the sentences before comparison
            /*use sort function so that when compare two sentences
            then avoid consequtives words used or not?*/

            if (sentence[i] == sentence2[j])
            {
                similar2.insert(sentence[i]);
                sim2++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 2: " << sim2 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar2.begin(); it != similar2.end(); it++)
    {
        int count = count_if(sentence2.begin(), sentence2.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    // base case
    if (sim2 == 0)
    {
        cout << "\nPlagiarism for document2: 0.0%\n\n";
    }

    double sim1ilarity2 = static_cast<double>(sim2) / tsl * 100;
    /*if similiar sentences is 0 then already printed in above*/
    if (sim2 != 0)
    {
        cout << "\nPlagiarism for document2: " << fixed << setprecision(2) << sim1ilarity2 << "%\n\n";
    }

    /*Compare document3 to base file and print the output*/
    int sim3 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence3.size(); j++)
        {
            // Sorting the sentences before comparison
            /*use sort function so that when compare two sentences
            then avoid consequtives words used or not?*/

            if (sentence[i] == sentence3[j])
            {
                similar3.insert(sentence[i]);
                sim3++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 3: " << sim3 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar3.begin(); it != similar3.end(); it++)
    {
        int count = count_if(sentence3.begin(), sentence3.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    // base case
    if (sim3 == 0)
    {
        cout << "\nPlagiarism for document3: 0.0%\n\n";
    }

    double sim1ilarity3 = static_cast<double>(sim3) / tsl * 100;
    /*if similiar sentences is 0 then already printed in above*/
    if (sim3 != 0)
    {
        cout << "\nPlagiarism for document3: " << fixed << setprecision(2) << sim1ilarity3 << "%\n\n";
    }

    /*Compare document4 to base file and print the output*/
    int sim4 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence4.size(); j++)
        {
            // Sorting the sentences before comparison
            /*use sort function so that when compare two sentences
            then avoid consequtives words used or not?*/

            if (sentence[i] == sentence4[j])
            {
                similar4.insert(sentence[i]);
                sim4++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 4: " << sim4 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar4.begin(); it != similar4.end(); it++)
    {
        int count = count_if(sentence4.begin(), sentence4.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    // base case
    if (sim4 == 0)
    {
        cout << "\nPlagiarism for document4: 0.0%\n\n";
    }

    double sim1ilarity4 = static_cast<double>(sim4) / tsl * 100;
    /*if similiar sentences is 0 then already printed in above*/
    if (sim4 != 0)
    {
        cout << "\nPlagiarism for document4: " << fixed << setprecision(2) << sim1ilarity4 << "%\n\n";
    }

    /*Compare document5 to base file and print the output*/
    int sim5 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence5.size(); j++)
        {
            // Sorting the sentences before comparison
            /*use sort function so that when compare two sentences
            then avoid consequtives words used or not?*/

            if (sentence[i] == sentence5[j])
            {
                similar5.insert(sentence[i]);
                sim5++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 5: " << sim5 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar5.begin(); it != similar5.end(); it++)
    {
        int count = count_if(sentence5.begin(), sentence5.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    // base case
    if (sim5 == 0)
    {
        cout << "\nPlagiarism for document5: 0.0%\n\n";
    }

    double sim1ilarity5 = static_cast<double>(sim5) / tsl * 100;
    /*if similiar sentences is 0 then already printed in above*/
    if (sim5 != 0)
    {
        cout << "\nPlagiarism for document5: " << fixed << setprecision(2) << sim1ilarity5 << "%\n\n";
    }

    /*
    Now calculate of the full project
    plagiarism= (every document plagiarism / total document)
    */

    double sim1ilarity, total_document_plagiarism;

    total_document_plagiarism = sim1ilarity1 + sim1ilarity2 + sim1ilarity3 + sim1ilarity4 + sim1ilarity5;

    sim1ilarity = static_cast<double>(total_document_plagiarism) / 5;

    cout << "\n\nTotal Plagiarism: " << fixed << setprecision(2) << sim1ilarity << "%\n\n\n";

    return 0;
}