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
            continue;
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
            continue;
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
            continue;
        else
        {
            currentSentence += tolower(c);
        }
    }

    return sentence2;
}

int main()
{
    string base = "base.txt";
    string file1 = "document1.txt";
    string file2 = "document2.txt";

    ifstream b(base), f1(file1), f2(file2);

    if (!b || !f1 || !f2)
    {
        cout << "\nError opening file." << endl;
        return 1;
    }

    string text, text1, text2;
    string line, line1, line2;

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

    // Manage if any document is empty
    if (text1.empty() || text2.empty())
    {
        cout << "\nPlagiarism: 0.0%\n\n";
        return 0;
    }
    vector<string> sentence = spilitS(text);
    vector<string> sentence1 = spilitS1(text1);
    vector<string> sentence2 = spilitS2(text2);

    // int tsl = max(sentence1.size(), sentence2.size());
    int tsl = sentence.size();

    // print base file
    cout << "\n**Base file**\n";
    for (i = 0; i < sentence.size(); i++)
    {
        cout << sentence[i];
    }
    cout << endl;

    // print file 1
    cout << "\n**Document 1**\n";
    for (i = 0; i < sentence1.size(); i++)
    {
        cout << sentence1[i];
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
                sim1++;
            }
        }
    }

    // base case
    if (sim1 == 0)
    {
        cout << "\nPlagiarism for document1: 0.0%\n\n";
        return 0;
    }
    double sim1ilarity1 = static_cast<double>(sim1) / tsl * 100;

    cout << "\nPlagiarism for document1: " << fixed << setprecision(2) << sim1ilarity1 << "%\n\n";

    // print file 2
    cout << "\n**Document 2**\n";
    for (i = 0; i < sentence2.size(); i++)
    {
        cout << sentence2[i];
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
                sim2++;
            }
        }
    }

    // base case
    if (sim2 == 0)
    {
        cout << "\nPlagiarism for document2: 0.0%\n\n";
        return 0;
    }
    double sim1ilarity2 = static_cast<double>(sim2) / tsl * 100;

    cout << "\nPlagiarism for document2: " << fixed << setprecision(2) << sim1ilarity2 << "%\n\n";

    return 0;
}