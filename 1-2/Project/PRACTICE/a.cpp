#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

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
    string file1 = "document1.txt";
    string file2 = "document2.txt";

    ifstream f1(file1), f2(file2);

    if (!f1 || !f2)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string text1, text2, word1, word2;

    while (f1 >> word1)
    {
        text1 += word1 + " ";
    }
    f1.close();

    while (f2 >> word2)
    {
        text2 += word2 + " ";
    }
    f2.close();

    vector<string> sentence1 = spilitS1(text1);
    vector<string> sentence2 = spilitS2(text2);

    int tsl = max(sentence1.size(), sentence2.size());

    // print file 1
    cout << "Document 1\n";
    for (int i = 0; i < sentence1.size(); i++)
    {
        cout << sentence1[i];
    }
    cout << endl;

    // print file 2
    cout << "Document 2\n";
    for (int i = 0; i < sentence2.size(); i++)
    {
        cout << sentence2[i];
    }
    cout << endl;

    int sim = 0;
    for (int i = 0; i < tsl; i++)
    {
        for (int j = 0; j < tsl; j++)
        {
            if (sentence1[i] == sentence2[j])
            {
                sim++;
            }
        }
    }

    if (sim == 0)
    {
        cout << "\nPlagiarism: 0.0%\n\n";
        return 0;
    }
    double similarity = static_cast<double>(sim) / tsl * 100;

    cout << "\nPlagiarism: " << fixed << setprecision(2) << similarity << "%\n\n";

    return 0;
}
