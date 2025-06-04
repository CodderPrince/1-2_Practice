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
    for (char c : text)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else if (c == '\n')
        {
            continue;
        }

        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence;
}

// Separate every sentence for document 1
vector<string> spilitS1(const string &text1)
{
    vector<string> sentence1;
    string currentSentence;
    for (char c : text1)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence1.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else if (c == '\n')
        {
            continue;
        }
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence1;
}

// Separate every sentence for document 2
vector<string> spilitS2(const string &text2)
{
    vector<string> sentence2;
    string currentSentence;
    for (char c : text2)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence2.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else if (c == '\n')
        {
            continue;
        }
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence2;
}

// Separate every sentence for document 3
vector<string> spilitS3(const string &text3)
{
    vector<string> sentence3;
    string currentSentence;
    for (char c : text3)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence3.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else if (c == '\n')
        {
            continue;
        }
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence3;
}

// Separate every sentence for document 4
vector<string> spilitS4(const string &text4)
{
    vector<string> sentence4;
    string currentSentence;
    for (char c : text4)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence4.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else if (c == '\n')
        {
            continue;
        }
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence4;
}

// Separate every sentence for document 5
vector<string> spilitS5(const string &text5)
{
    vector<string> sentence5;
    string currentSentence;
    for (char c : text5)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence5.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else if (c == '\n')
        {
            continue;
        }
        else
        {
            currentSentence += tolower(c);
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

    // Manage if any document is empty then print an warning message
    if (text1.empty())
    {
        cout << "\nDocument 1 is empty!\nPlease input something!\n\n";
    }

    if (text2.empty())
    {
        cout << "\nDocument 2 is empty!\nPlease input something!\n\n";
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
    vector<string> similar1;
    vector<string> similar2;
    vector<string> similar3;
    vector<string> similar4;
    vector<string> similar5;

    // now outer loop == base file total sentences
    int tsl = sentence.size();

    // print base file
    cout << "\n**Base file**\n";
    for (i = 0; i < sentence.size(); i++)
    {
        cout << sentence[i] << endl;
    }
    cout << endl;

    // print file 1
    cout << "\n**Document 1**\n";
    for (i = 0; i < sentence1.size(); i++)
    {
        cout << sentence1[i] << endl;
    }
    cout << endl;

    /*Compare document1 to base file and print the output*/
    int sim1 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence1.size(); j++)
        {
            if (sentence[i] == sentence1[j])
            {
                similar1.push_back(sentence[i]);
                sim1++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 1: " << sim1 << endl;
    for (auto &s : similar1)
    {
        cout << s << endl;
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

    // print file 2
    cout << "\n**Document 2**\n";
    for (i = 0; i < sentence2.size(); i++)
    {
        cout << sentence2[i] << endl;
    }
    cout << endl;

    /*Compare document2 to base file and print the output*/
    int sim2 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence2.size(); j++)
        {
            if (sentence[i] == sentence2[j])
            {
                similar2.push_back(sentence[i]);
                sim2++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 2: " << sim2 << endl;
    for (auto &s : similar2)
    {
        cout << s << endl;
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

    // print file 3
    cout << "\n**Document 3**\n";
    for (i = 0; i < sentence3.size(); i++)
    {
        cout << sentence3[i] << endl;
    }
    cout << endl;

    /*Compare document3 to base file and print the output*/
    int sim3 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence3.size(); j++)
        {
            if (sentence[i] == sentence3[j])
            {
                similar3.push_back(sentence[i]);
                sim3++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 3: " << sim3 << endl;
    for (auto &s : similar3)
    {
        cout << s << endl;
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

    // print file 4
    cout << "\n**Document 4**\n";
    for (i = 0; i < sentence4.size(); i++)
    {
        cout << sentence4[i] << endl;
    }
    cout << endl;

    /*Compare document4 to base file and print the output*/
    int sim4 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence4.size(); j++)
        {
            if (sentence[i] == sentence4[j])
            {
                similar4.push_back(sentence[i]);
                sim4++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 4: " << sim4 << endl;
    for (auto &s : similar4)
    {
        cout << s << endl;
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

    // print file 5
    cout << "\n**Document 5**\n";
    for (i = 0; i < sentence5.size(); i++)
    {
        cout << sentence5[i] << endl;
    }
    cout << endl;

    /*Compare document2 to base file and print the output*/
    int sim5 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence5.size(); j++)
        {
            if (sentence[i] == sentence5[j])
            {
                similar5.push_back(sentence[i]);
                sim5++;
            }
        }
    }

    // print similar sentences
    cout << "\nTotal similar sentence in document 5: " << sim5 << endl;
    for (auto &s : similar5)
    {
        cout << s << endl;
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

    /*Now calculate of the full project
    plagiarism= (every document plagiarism / total document)*/

    double sim1ilarity, total_document_plagiarism;

    total_document_plagiarism = sim1ilarity1 + sim1ilarity2 + sim1ilarity3 + sim1ilarity4 + sim1ilarity5;

    sim1ilarity = static_cast<double>(total_document_plagiarism) / 5;

    cout << "\n\nTotal Plagiarism: " << fixed << setprecision(2) << sim1ilarity << "%\n\n\n";

    return 0;
}