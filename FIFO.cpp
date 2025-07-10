#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfPageSequences, numberOfFrames;
    cout << "\nNumber of Page Sequences: ";
    cin >> numberOfPageSequences;
    cout << "Number of Frames: ";
    cin >> numberOfFrames;
    int pageSequences[numberOfPageSequences];
    cout << "Page Sequences: ";
    for (int i = 0; i < numberOfPageSequences; i++) cin >> pageSequences[i];
    char hitMiss[100];
    int frames[numberOfPageSequences+1], table[numberOfFrames+1][numberOfPageSequences+1];
    fill(frames, frames + numberOfFrames, -1);
    int cnt = 0, hits = 0, misses = 0;
    for (int i = 0; i < numberOfPageSequences; i++)
    {
        bool hitOrNot = false;
        int page = pageSequences[i];
        for (int j = 0; j < numberOfFrames; j++)
        {
            if (frames[j] == page)
            {
                hitOrNot = true;
                break;
            }
        }
        if (hitOrNot) hits++, hitMiss[i] = 'H';
        else
        {
            misses++;
            hitMiss[i] = 'M';
            frames[cnt] = page;
            cnt = (cnt + 1) % numberOfFrames;
        }
        for (int j = 0; j < numberOfFrames; j++) table[j][i] = frames[j];
    }
    cout << "\nFrame\t:";
    for (int i = 0; i < numberOfPageSequences; i++) cout << setw(2) << pageSequences[i] << " ";
    for (int i = 0; i < numberOfFrames; i++)
    {
        cout << "\nF" << i + 1 << "\t:";
        for (int j = 0; j < numberOfPageSequences; j++)
        {
            if (table[i][j] == -1) cout << " - ";
            else cout << setw(2) << table[i][j] << " ";   
        }
    }
    cout << "\n(H/M)\t: ";
    for (int i = 0; i < numberOfPageSequences; i++) cout << hitMiss[i] << "  ";
    cout << "\n\nTotal Misses\t: " << misses;
    cout << "\nMiss Rate\t: " << fixed << setprecision(2) << (misses * 100.0 / numberOfPageSequences) << "%";
    cout << "\nTotal Hits\t: " << hits;
    cout << "\nHit Rate\t: " << fixed << setprecision(2) << (hits * 100.0 / numberOfPageSequences) << "%\n";
    return 0;
}

// Inputs:

// 19
// 3
// 3 2 1 3 4 1 6 2 4 3 4 2 1 4 5 2 1 3 4