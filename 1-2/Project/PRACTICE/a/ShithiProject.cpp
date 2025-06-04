#include <bits/stdc++.h>
using namespace std;

int i, j;

vector<string> SentenceSeparator(const string &documet)
{
    vector<string> sentence;
    string currentSentence;
    for (char c : documet)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence;
}

vector<string> SentenceSeparator1(const string &documet1)
{
    vector<string> sentence1;
    string currentSentence;
    for (char c : documet1)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence1.push_back(currentSentence + c);
            currentSentence.clear();
        }
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence1;
}

vector<string> SentenceSeparator2(const string &documet2)
{
    vector<string> sentence2;
    string currentSentence;
    for (char c : documet2)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            sentence2.push_back(currentSentence + c);
            currentSentence.clear();
        }
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

    string documet, documet1, documet2;
    string line, line1, line2;

    while (getline(b, line))
    {
        documet += line;
    }
    b.close();

    while (getline(f1, line1))
    {
        documet1 += line1;
    }
    f1.close();

    while (getline(f2, line2))
    {
        documet2 += line2;
    }
    f2.close();

    if (documet.empty())
    {
        cout << "\nWarning!\nBase file is empty.\n\n\n";
        return 0;
    }

    if (documet1.empty())
    {
        cout << "\nDocument 1 is empty!\nPlease input something!\n\n";
    }

    if (documet2.empty())
    {
        cout << "\nDocument 2 is empty!\nPlease input something!\n\n";
    }

    vector<string> sentence = SentenceSeparator(documet);
    vector<string> sentence1 = SentenceSeparator1(documet1);
    vector<string> sentence2 = SentenceSeparator2(documet2);

    set<string> similar1;
    set<string> similar2;

    int tsl = sentence.size();

    int sim1 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence1.size(); j++)
        {
            if (sentence[i] == sentence1[j])
            {
                similar1.insert(sentence[i]);
                sim1++;
            }
        }
    }

    cout << "\nTotal similar sentence in document 1: " << sim1 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar1.begin(); it != similar1.end(); it++)
    {
        int count = count_if(sentence1.begin(), sentence1.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    if (sim1 == 0)
    {
        cout << "\nPlagiarism for document1: 0.0%\n\n";
    }

    double similarity1 = static_cast<double>(sim1) / tsl * 100;
    if (sim1 != 0)
    {
        cout << "\nPlagiarism for document1: " << fixed << setprecision(2) << similarity1 << "%\n\n";
    }

    int sim2 = 0;
    for (i = 0; i < tsl; i++)
    {
        for (j = 0; j < sentence2.size(); j++)
        {
            if (sentence[i] == sentence2[j])
            {
                similar2.insert(sentence[i]);
                sim2++;
            }
        }
    }

    cout << "\nTotal similar sentence in document 2: " << sim2 << endl;
    cout << "Similar sentences are given below:\n\n";
    for (auto it = similar2.begin(); it != similar2.end(); it++)
    {
        int count = count_if(sentence2.begin(), sentence2.end(), [&](const string &s)
                             { return s == *it; });
        cout << *it << " (" << count << " times)" << endl;
    }
    cout << endl;

    if (sim2 == 0)
    {
        cout << "\nPlagiarism for document2: 0.0%\n\n";
    }

    double sim1ilarity2 = static_cast<double>(sim2) / tsl * 100;
    if (sim2 != 0)
    {
        cout << "\nPlagiarism for document2: " << fixed << setprecision(2) << sim1ilarity2 << "%\n\n";
    }

    double total_document_plagiarism = similarity1 + sim1ilarity2;
    double total_document_similarity = total_document_plagiarism / 2;

    cout << "\n\nTotal Plagiarism: " << fixed << setprecision(2) << total_document_similarity << "%\n\n\n";

    return 0;
}