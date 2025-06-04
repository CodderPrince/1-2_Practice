#include <bits\stdc++.h>
using namespace std;

// Separate every sentence
vector<string> splitS(const string &text)
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
        else
        {
            currentSentence += tolower(c);
        }
    }
    return sentence;
}

int main()
{
    string base = "base.txt";
    string file1 = "document1.txt";

    ifstream b(base), f1(file1);

    if (!b || !f1)
    {
        cout << "\nError opening file." << endl;
        return 1;
    }

    string text, text1;
    string line, line1;

    while (getline(b, line))
    {
        text += line;
    }
    b.close();

    while (getline(f1, line1))
    {
        text1 += line1;
    }
    f1.close();

    if (text.empty())
    {
        cout << "\nWarning!\nBase file is empty.\n\n\n";
        return 0;
    }

    if (text1.empty())
    {
        cout << "\nDocument 1 is empty!\nPlease input something!\n\n";
    }

    vector<string> sentence = splitS(text);
    vector<string> sentence1 = splitS(text1);

    sort(sentence.begin(), sentence.end());
    sort(sentence1.begin(), sentence1.end());

    set<string> similar1;

    // print base file
    cout << "\n**Base file**\n\n";
    for (int i = 0; i < sentence.size(); i++)
    {
        cout << sentence[i] << endl;
    }
    cout << endl;

    // print file 1
    cout << "\n**Document 1**\n\n";
    for (int i = 0; i < sentence1.size(); i++)
    {
        cout << sentence1[i] << endl;
    }
    cout << endl;

    int tsl = sentence.size();

    cout << "\nTotal Sentences in Base File: " << tsl << "\n\n";

    int sim1 = 0;
    for (int i = 0; i < tsl; i++)
    {
        for (int j = 0; j < sentence1.size(); j++)
        {
            // Sorting the sentences before comparison
            string sortedSentence = sentence[i];
            string sortedSentence1 = sentence1[j];
            sort(sortedSentence.begin(), sortedSentence.end());
            sort(sortedSentence1.begin(), sortedSentence1.end());

            if (sortedSentence == sortedSentence1)
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

    double total_document_plagiarism = similarity1;
    double total_document_similarity = total_document_plagiarism / 1;

    cout << "\n\nTotal Plagiarism: " << fixed << setprecision(2) << total_document_similarity << "%\n\n\n";

    return 0;
}
