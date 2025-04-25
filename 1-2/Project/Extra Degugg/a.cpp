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


//Use lamda function for printing
1. Lamda function mainly print sentences in alphabatically order.

Syntax:
for(it=sentence1.begin(); it != sentence1.end() ; it++)
{
    int count = count_if(sentence1.begin(),sentence1.end(), [&](const string &s)
    {
        return s=*it;
    });
}
*/

#include <bits\stdc++.h>
using namespace std;

int i, j;

/*                           Some Popular Conjunction List
and             after           although            as          as if       as long as
as soon as      as though       at                  because     before      besides
but             even if         even though         except      for         forasmuch as
howbeit         if              in case             lest        once        in order that
now that        only if         provided that       since       so          so that
supposing       than            then                therefore   till        unless
untill          when            whenever            where       whether     while
or              with            yet
*/

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
        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 'n' && text[i + 3] == 'd' && text[i + 4] == ' ')
        {
            currentSentence += "and";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        // special case for 'or' conjunction
        else if (text[i] == ' ' && text[i + 1] == 'o' && text[i + 2] == 'r' && text[i + 3] == ' ')
        {
            currentSentence += "or";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 'f' && text[i + 3] == 't' && text[i + 4] == 'e' && text[i + 5] == 'r' && text[i + 6] == ' ')
        {
            currentSentence += "after";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 'l' && text[i + 3] == 't' && text[i + 4] == 'h' && text[i + 5] == 'o' && text[i + 6] == 'u' && text[i + 7] == 'g' && text[i + 8] == 'h' && text[i + 9] == ' ')
        {
            currentSentence += "although";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 's' && text[i + 3] == ' ')
        {
            currentSentence += "as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 's' && text[i + 3] == 'i' && text[i + 4] == 'f' && text[i + 5] == ' ')
        {
            currentSentence += "as if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 's' && text[i + 3] == 'l' && text[i + 4] == 'o' && text[i + 5] == 'n' && text[i + 6] == 'g' && text[i + 7] == ' ' && text[i + 8] == 'a' && text[i + 9] == 's' && text[i + 10] == ' ')
        {
            currentSentence += "as long as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 's' && text[i + 3] == 's' && text[i + 4] == 'o' && text[i + 5] == 'o' && text[i + 6] == 'n' && text[i + 7] == ' ' && text[i + 8] == 'a' && text[i + 9] == 's' && text[i + 10] == ' ')
        {
            currentSentence += "as soon as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 's' && text[i + 3] == 't' && text[i + 4] == 'h' && text[i + 5] == 'o' && text[i + 6] == 'u' && text[i + 7] == 'g' && text[i + 8] == 'h' && text[i + 9] == ' ')
        {
            currentSentence += "as though";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text[i] == ' ' && text[i + 1] == 'a' && text[i + 2] == 't' && text[i + 3] == ' ')
        {
            currentSentence += "at";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text[i] == ' ' && text[i + 1] == 'b' && text[i + 2] == 'e' && text[i + 3] == 'c' && text[i + 4] == 'a' && text[i + 5] == 'u' && text[i + 6] == 's' && text[i + 7] == 'e' && text[i + 8] == ' ')
        {
            currentSentence += "because";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 'b' && text[i + 2] == 'e' && text[i + 3] == 'f' && text[i + 4] == 'o' && text[i + 5] == 'r' && text[i + 6] == 'e' && text[i + 7] == ' ')
        {
            currentSentence += "before";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }

        else if (text[i] == ' ' && text[i + 1] == 'b' && text[i + 2] == 'e' && text[i + 3] == 's' && text[i + 4] == 'i' && text[i + 5] == 'd' && text[i + 6] == 'e' && text[i + 7] == 's' && text[i + 8] == ' ')
        {
            currentSentence += "besides";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 'b' && text[i + 2] == 'u' && text[i + 3] == 't' && text[i + 4] == ' ')
        {
            currentSentence += "but";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        else if (text[i] == ' ' && text[i + 1] == 'e' && text[i + 2] == 'v' && text[i + 3] == 'e' && text[i + 4] == 'n' && text[i + 5] == ' ' && text[i + 6] == 'i' && text[i + 7] == 'f' && text[i + 8] == ' ')
        {
            currentSentence += "even if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 'e' && text[i + 2] == 'v' && text[i + 3] == 'e' && text[i + 4] == 'n' && text[i + 5] == ' ' && text[i + 6] == 't' && text[i + 7] == 'h' && text[i + 8] == 'o' && text[i + 9] == 'u' && text[i + 10] == 'g' && text[i + 11] == 'h' && text[i + 12] == ' ')
        {
            currentSentence += "even though";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 12;
        }

        else if (text[i] == ' ' && text[i + 1] == 'e' && text[i + 2] == 'x' && text[i + 3] == 'c' && text[i + 4] == 'e' && text[i + 5] == 'p' && text[i + 6] == 't' && text[i + 7] == ' ')
        {
            currentSentence += "except";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }

        else if (text[i] == ' ' && text[i + 1] == 'f' && text[i + 2] == 'o' && text[i + 3] == 'r' && text[i + 4] == ' ')
        {
            currentSentence += "for";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        else if (text[i] == ' ' && text[i + 1] == 'f' && text[i + 2] == 'o' && text[i + 3] == 'r' && text[i + 4] == 'a' && text[i + 5] == 's' && text[i + 6] == 'm' && text[i + 7] == 'u' && text[i + 8] == 'c' && text[i + 9] == 'h' && text[i + 10] == ' ' && text[i + 11] == 'a' && text[i + 12] == 's' && text[i + 13] == ' ')
        {
            currentSentence += "forasmuch as";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 13;
        }

        else if (text[i] == ' ' && text[i + 1] == 'h' && text[i + 2] == 'o' && text[i + 3] == 'w' && text[i + 4] == 'b' && text[i + 5] == 'e' && text[i + 6] == 'i' && text[i + 7] == 't' && text[i + 8] == ' ')
        {
            currentSentence += "howbeit";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 'i' && text[i + 2] == 'f' && text[i + 3] == ' ')
        {
            currentSentence += "if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text[i] == ' ' && text[i + 1] == 'i' && text[i + 2] == 'n' && text[i + 3] == ' ' && text[i + 4] == 'c' && text[i + 5] == 'a' && text[i + 6] == 's' && text[i + 7] == 'e' && text[i + 8] == ' ')
        {
            currentSentence += "in case";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 'i' && text[i + 2] == 'n' && text[i + 3] == ' ' && text[i + 4] == 'o' && text[i + 5] == 'r' && text[i + 6] == 'd' && text[i + 7] == 'e' && text[i + 8] == 'r' && text[i + 9] == ' ' && text[i + 10] == 't' && text[i + 11] == 'h' && text[i + 12] == 'a' && text[i + 13] == 't' && text[i + 14] == ' ')
        {
            currentSentence += "in order that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 14;
        }

        else if (text[i] == ' ' && text[i + 1] == 'l' && text[i + 2] == 'e' && text[i + 3] == 's' && text[i + 4] == 't' && text[i + 5] == ' ')
        {
            currentSentence += "lest";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text[i] == ' ' && text[i + 1] == 'n' && text[i + 2] == 'o' && text[i + 3] == 'w' && text[i + 4] == ' ' && text[i + 5] == 't' && text[i + 6] == 'h' && text[i + 7] == 'a' && text[i + 8] == 't' && text[i + 9] == ' ')
        {
            currentSentence += "now that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text[i] == ' ' && text[i + 1] == 'o' && text[i + 2] == 'n' && text[i + 3] == 'c' && text[i + 4] == 'e' && text[i + 5] == ' ')
        {
            currentSentence += "once";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text[i] == ' ' && text[i + 1] == 'o' && text[i + 2] == 'n' && text[i + 3] == 'l' && text[i + 4] == 'y' && text[i + 5] == ' ' && text[i + 6] == 'i' && text[i + 7] == 'f' && text[i + 8] == ' ')
        {
            currentSentence += "only if";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 'p' && text[i + 2] == 'r' && text[i + 3] == 'o' && text[i + 4] == 'v' && text[i + 5] == 'i' && text[i + 6] == 'd' && text[i + 7] == 'e' && text[i + 8] == 'd' && text[i + 9] == ' ' && text[i + 10] == 't' && text[i + 11] == 'h' && text[i + 12] == 'a' && text[i + 13] == 't' && text[i + 14] == ' ')
        {
            currentSentence += "provided that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 14;
        }

        else if (text[i] == ' ' && text[i + 1] == 's' && text[i + 2] == 'i' && text[i + 3] == 'n' && text[i + 4] == 'c' && text[i + 5] == 'e' && text[i + 6] == ' ')
        {
            currentSentence += "since";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text[i] == ' ' && text[i + 1] == 's' && text[i + 2] == 'o' && text[i + 3] == ' ' && text[i + 4] == 't' && text[i + 5] == 'h' && text[i + 6] == 'a' && text[i + 7] == 't' && text[i + 8] == ' ')
        {
            currentSentence += "so that";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 8;
        }

        else if (text[i] == ' ' && text[i + 1] == 's' && text[i + 2] == 'u' && text[i + 3] == 'p' && text[i + 4] == 'p' && text[i + 5] == 'o' && text[i + 6] == 's' && text[i + 7] == 'i' && text[i + 8] == 'n' && text[i + 9] == 'g' && text[i + 10] == ' ')
        {
            currentSentence += "supposing";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
        }

        else if (text[i] == ' ' && text[i + 1] == 't' && text[i + 2] == 'h' && text[i + 3] == 'a' && text[i + 4] == 'n' && text[i + 5] == ' ')
        {
            currentSentence += "than";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text[i] == ' ' && text[i + 1] == 't' && text[i + 2] == 'h' && text[i + 3] == 'e' && text[i + 4] == 'n' && text[i + 5] == ' ')
        {
            currentSentence += "then";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text[i] == ' ' && text[i + 1] == 't' && text[i + 2] == 'h' && text[i + 3] == 'e' && text[i + 4] == 'r' && text[i + 5] == 'e' && text[i + 6] == ' ' && text[i + 7] == 'f' && text[i + 8] == 'o' && text[i + 9] == 'r' && text[i + 10] == 'e' && text[i + 11] == ' ')
        {
            currentSentence += "therefore";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }

        else if (text[i] == ' ' && text[i + 1] == 't' && text[i + 2] == 'i' && text[i + 3] == 'l' && text[i + 4] == 'l' && text[i + 5] == ' ')
        {
            currentSentence += "till";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text[i] == ' ' && text[i + 1] == 'u' && text[i + 2] == 'n' && text[i + 3] == 'l' && text[i + 4] == 'e' && text[i + 5] == 's' && text[i + 6] == 's' && text[i + 7] == ' ')
        {
            currentSentence += "unless";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 7;
        }

        else if (text[i] == ' ' && text[i + 1] == 'u' && text[i + 2] == 'n' && text[i + 3] == 't' && text[i + 4] == 'i' && text[i + 5] == 'l' && text[i + 6] == ' ')
        {
            currentSentence += "until";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text[i] == ' ' && text[i + 1] == 'w' && text[i + 2] == 'e' && text[i + 3] == 'h' && text[i + 4] == 'e' && text[i + 5] == 'n' && text[i + 6] == ' ')
        {
            currentSentence += "when";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text[i] == ' ' && text[i + 1] == 'w' && text[i + 2] == 'h' && text[i + 3] == 'e' && text[i + 4] == 'n' && text[i + 5] == 'e' && text[i + 6] == 'v' && text[i + 7] == 'e' && text[i + 8] == 'r' && text[i + 9] == ' ')
        {
            currentSentence += "whenever";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text[i] == ' ' && text[i + 1] == 'w' && text[i + 2] == 'h' && text[i + 3] == 'e' && text[i + 4] == 'r' && text[i + 5] == 'e' && text[i + 6] == ' ' && text[i + 7] == 'a' && text[i + 8] == 's' && text[i + 9] == ' ')
        {
            currentSentence += "whereas";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text[i] == ' ' && text[i + 1] == 'w' && text[i + 2] == 'h' && text[i + 3] == 'e' && text[i + 4] == 't' && text[i + 5] == 'h' && text[i + 6] == 'e' && text[i + 7] == 'r' && text[i + 8] == ' ' && text[i + 9] == 'o' && text[i + 10] == 'r' && text[i + 11] == ' ')
        {
            currentSentence += "whether";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 11;
        }

        else if (text[i] == ' ' && text[i + 1] == 'w' && text[i + 2] == 'h' && text[i + 3] == 'i' && text[i + 4] == 'l' && text[i + 5] == 'e' && text[i + 6] == ' ')
        {
            currentSentence += "while";
            sentence.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else
        {
            currentSentence += text[i];
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
        else if (text1[i] == ' ' && text1[i + 1] == 'a' && text1[i + 2] == 'n' && text1[i + 3] == 'd' && text1[i + 4] == ' ')
        {
            currentSentence += "and";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text1[i] == ' ' && text1[i + 1] == 'b' && text1[i + 2] == 'u' && text1[i + 3] == 't' && text1[i + 4] == ' ')
        {
            currentSentence += "but";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        // special case for 'or' conjunction
        else if (text1[i] == ' ' && text1[i + 1] == 'o' && text1[i + 2] == 'r' && text1[i + 3] == ' ')
        {
            currentSentence += "or";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text1[i] == ' ' && text1[i + 1] == 'a' && text1[i + 2] == 'f' && text1[i + 3] == 't' && text1[i + 4] == 'e' && text1[i + 5] == 'r' && text1[i + 6] == ' ')
        {
            currentSentence += "after";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text1[i] == ' ' && text1[i + 1] == 'a' && text1[i + 2] == 'l' && text1[i + 3] == 't' && text1[i + 4] == 'h' && text1[i + 5] == 'o' && text1[i + 6] == 'u' && text1[i + 7] == 'g' && text1[i + 8] == 'h' && text1[i + 9] == ' ')
        {
            currentSentence += "although";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text1[i] == ' ' && text1[i + 1] == 'a' && text1[i + 2] == 's' && text1[i + 3] == ' ')
        {
            currentSentence += "as";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text1[i] == ' ' && text1[i + 1] == 'a' && text1[i + 2] == 's' && text1[i + 3] == 'i' && text1[i + 4] == 'f' && text1[i + 5] == ' ')
        {
            currentSentence += "as if";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text1[i] == ' ' && text1[i + 1] == 'a' && text1[i + 2] == 's' && text1[i + 3] == 'l' && text1[i + 4] == 'o' && text1[i + 5] == 'n' && text1[i + 6] == 'g' && text1[i + 7] == ' ' && text1[i + 8] == 'a' && text1[i + 9] == 's' && text1[i + 10] == ' ')
        {
            currentSentence += "as long as";
            sentence1.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
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
        // special case for 'and' conjunction
        else if (text2[i] == ' ' && text2[i + 1] == 'a' && text2[i + 2] == 'n' && text2[i + 3] == 'd' && text2[i + 4] == ' ')
        {
            currentSentence += "and";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text2[i] == ' ' && text2[i + 1] == 'b' && text2[i + 2] == 'u' && text2[i + 3] == 't' && text2[i + 4] == ' ')
        {
            currentSentence += "but";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        // special case for 'or' conjunction
        else if (text2[i] == ' ' && text2[i + 1] == 'o' && text2[i + 2] == 'r' && text2[i + 3] == ' ')
        {
            currentSentence += "or";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text2[i] == ' ' && text2[i + 1] == 'a' && text2[i + 2] == 'f' && text2[i + 3] == 't' && text2[i + 4] == 'e' && text2[i + 5] == 'r' && text2[i + 6] == ' ')
        {
            currentSentence += "after";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text2[i] == ' ' && text2[i + 1] == 'a' && text2[i + 2] == 'l' && text2[i + 3] == 't' && text2[i + 4] == 'h' && text2[i + 5] == 'o' && text2[i + 6] == 'u' && text2[i + 7] == 'g' && text2[i + 8] == 'h' && text2[i + 9] == ' ')
        {
            currentSentence += "although";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text2[i] == ' ' && text2[i + 1] == 'a' && text2[i + 2] == 's' && text2[i + 3] == ' ')
        {
            currentSentence += "as";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text2[i] == ' ' && text2[i + 1] == 'a' && text2[i + 2] == 's' && text2[i + 3] == 'i' && text2[i + 4] == 'f' && text2[i + 5] == ' ')
        {
            currentSentence += "as if";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text2[i] == ' ' && text2[i + 1] == 'a' && text2[i + 2] == 's' && text2[i + 3] == 'l' && text2[i + 4] == 'o' && text2[i + 5] == 'n' && text2[i + 6] == 'g' && text2[i + 7] == ' ' && text2[i + 8] == 'a' && text2[i + 9] == 's' && text2[i + 10] == ' ')
        {
            currentSentence += "as long as";
            sentence2.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
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
        // special case for 'and' conjunction
        else if (text3[i] == ' ' && text3[i + 1] == 'a' && text3[i + 2] == 'n' && text3[i + 3] == 'd' && text3[i + 4] == ' ')
        {
            currentSentence += "and";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text3[i] == ' ' && text3[i + 1] == 'b' && text3[i + 2] == 'u' && text3[i + 3] == 't' && text3[i + 4] == ' ')
        {
            currentSentence += "but";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        // special case for 'or' conjunction
        else if (text3[i] == ' ' && text3[i + 1] == 'o' && text3[i + 2] == 'r' && text3[i + 3] == ' ')
        {
            currentSentence += "or";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text3[i] == ' ' && text3[i + 1] == 'a' && text3[i + 2] == 'f' && text3[i + 3] == 't' && text3[i + 4] == 'e' && text3[i + 5] == 'r' && text3[i + 6] == ' ')
        {
            currentSentence += "after";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text3[i] == ' ' && text3[i + 1] == 'a' && text3[i + 2] == 'l' && text3[i + 3] == 't' && text3[i + 4] == 'h' && text3[i + 5] == 'o' && text3[i + 6] == 'u' && text3[i + 7] == 'g' && text3[i + 8] == 'h' && text3[i + 9] == ' ')
        {
            currentSentence += "although";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text3[i] == ' ' && text3[i + 1] == 'a' && text3[i + 2] == 's' && text3[i + 3] == ' ')
        {
            currentSentence += "as";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text3[i] == ' ' && text3[i + 1] == 'a' && text3[i + 2] == 's' && text3[i + 3] == 'i' && text3[i + 4] == 'f' && text3[i + 5] == ' ')
        {
            currentSentence += "as if";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text3[i] == ' ' && text3[i + 1] == 'a' && text3[i + 2] == 's' && text3[i + 3] == 'l' && text3[i + 4] == 'o' && text3[i + 5] == 'n' && text3[i + 6] == 'g' && text3[i + 7] == ' ' && text3[i + 8] == 'a' && text3[i + 9] == 's' && text3[i + 10] == ' ')
        {
            currentSentence += "as long as";
            sentence3.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
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
        // special case for 'and' conjunction
        else if (text4[i] == ' ' && text4[i + 1] == 'a' && text4[i + 2] == 'n' && text4[i + 3] == 'd' && text4[i + 4] == ' ')
        {
            currentSentence += "and";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text4[i] == ' ' && text4[i + 1] == 'b' && text4[i + 2] == 'u' && text4[i + 3] == 't' && text4[i + 4] == ' ')
        {
            currentSentence += "but";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        // special case for 'or' conjunction
        else if (text4[i] == ' ' && text4[i + 1] == 'o' && text4[i + 2] == 'r' && text4[i + 3] == ' ')
        {
            currentSentence += "or";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text4[i] == ' ' && text4[i + 1] == 'a' && text4[i + 2] == 'f' && text4[i + 3] == 't' && text4[i + 4] == 'e' && text4[i + 5] == 'r' && text4[i + 6] == ' ')
        {
            currentSentence += "after";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text4[i] == ' ' && text4[i + 1] == 'a' && text4[i + 2] == 'l' && text4[i + 3] == 't' && text4[i + 4] == 'h' && text4[i + 5] == 'o' && text4[i + 6] == 'u' && text4[i + 7] == 'g' && text4[i + 8] == 'h' && text4[i + 9] == ' ')
        {
            currentSentence += "although";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text4[i] == ' ' && text4[i + 1] == 'a' && text4[i + 2] == 's' && text4[i + 3] == ' ')
        {
            currentSentence += "as";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text4[i] == ' ' && text4[i + 1] == 'a' && text4[i + 2] == 's' && text4[i + 3] == 'i' && text4[i + 4] == 'f' && text4[i + 5] == ' ')
        {
            currentSentence += "as if";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text4[i] == ' ' && text4[i + 1] == 'a' && text4[i + 2] == 's' && text4[i + 3] == 'l' && text4[i + 4] == 'o' && text4[i + 5] == 'n' && text4[i + 6] == 'g' && text4[i + 7] == ' ' && text4[i + 8] == 'a' && text4[i + 9] == 's' && text4[i + 10] == ' ')
        {
            currentSentence += "as long as";
            sentence4.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
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

        // special case for 'and' conjunction
        else if (text5[i] == ' ' && text5[i + 1] == 'a' && text5[i + 2] == 'n' && text5[i + 3] == 'd' && text5[i + 4] == ' ')
        {
            currentSentence += "and";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }
        else if (text5[i] == ' ' && text5[i + 1] == 'b' && text5[i + 2] == 'u' && text5[i + 3] == 't' && text5[i + 4] == ' ')
        {
            currentSentence += "but";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 4;
        }

        // special case for 'or' conjunction
        else if (text5[i] == ' ' && text5[i + 1] == 'o' && text5[i + 2] == 'r' && text5[i + 3] == ' ')
        {
            currentSentence += "or";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text5[i] == ' ' && text5[i + 1] == 'a' && text5[i + 2] == 'f' && text5[i + 3] == 't' && text5[i + 4] == 'e' && text5[i + 5] == 'r' && text5[i + 6] == ' ')
        {
            currentSentence += "after";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 6;
        }

        else if (text5[i] == ' ' && text5[i + 1] == 'a' && text5[i + 2] == 'l' && text5[i + 3] == 't' && text5[i + 4] == 'h' && text5[i + 5] == 'o' && text5[i + 6] == 'u' && text5[i + 7] == 'g' && text5[i + 8] == 'h' && text5[i + 9] == ' ')
        {
            currentSentence += "although";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 9;
        }

        else if (text5[i] == ' ' && text5[i + 1] == 'a' && text5[i + 2] == 's' && text5[i + 3] == ' ')
        {
            currentSentence += "as";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 3;
        }

        else if (text5[i] == ' ' && text5[i + 1] == 'a' && text5[i + 2] == 's' && text5[i + 3] == 'i' && text5[i + 4] == 'f' && text5[i + 5] == ' ')
        {
            currentSentence += "as if";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 5;
        }

        else if (text5[i] == ' ' && text5[i + 1] == 'a' && text5[i + 2] == 's' && text5[i + 3] == 'l' && text5[i + 4] == 'o' && text5[i + 5] == 'n' && text5[i + 6] == 'g' && text5[i + 7] == ' ' && text5[i + 8] == 'a' && text5[i + 9] == 's' && text5[i + 10] == ' ')
        {
            currentSentence += "as long as";
            sentence5.push_back(currentSentence);
            currentSentence.clear();
            i += 10;
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