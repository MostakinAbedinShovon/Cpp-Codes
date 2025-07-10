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
    char hitMiss[numberOfPageSequences];
    int table[numberOfFrames][numberOfPageSequences];
    for (int i = 0; i < numberOfFrames; i++) fill(table[i], table[i] + numberOfPageSequences, -1);
    list<int> recentPages;
    map<int, list<int>::iterator> pageMap;
    int hits = 0, misses = 0;
    for (int i = 0; i < numberOfPageSequences; i++){
        int page = pageSequences[i];
        bool hitOrNot = false;
        if (pageMap.find(page) != pageMap.end()){
            hitOrNot = true;
            recentPages.erase(pageMap[page]);
            recentPages.push_front(page);
            pageMap[page] = recentPages.begin();}
        if (hitOrNot) hits++,hitMiss[i] = 'H';
        else {
            hitMiss[i] = 'M';
            misses++;
            if (recentPages.size() == numberOfFrames){
                int lru = recentPages.back();
                recentPages.pop_back();
                pageMap.erase(lru);}
            recentPages.push_front(page);
            pageMap[page] = recentPages.begin();}
        int idx = 0;
        for (int val : recentPages){
            if (idx < numberOfFrames)table[idx][i] = val; 
            idx++;}
        while (idx < numberOfFrames) idx++, table[idx][i] = -1;}
    cout << "\nFrame\t:";
    for (int i = 0; i < numberOfPageSequences; i++) cout << setw(2) << pageSequences[i] << " ";
    for (int i = 0; i < numberOfFrames; i++){
        cout << "\nF" << i + 1 << "\t:";
        for (int j = 0; j < numberOfPageSequences; j++){
            if (table[i][j] == -1) cout << " - ";
            else cout << setw(2) << table[i][j] << " ";}}
    cout << "\n(H/M)\t: ";
    for (int i = 0; i < numberOfPageSequences; i++) cout << hitMiss[i] << "  ";
    cout << "\n\nTotal Hits\t: " << hits;
    cout << "\nHit Rate\t: " << fixed << setprecision(2) << (hits * 100.0 / numberOfPageSequences) << "%";
    cout << "\nTotal Misses\t: " << misses;
    cout << "\nMiss Rate\t: " << fixed << setprecision(2) << (misses * 100.0 / numberOfPageSequences) << "%\n";
    return 0;
}

// Inputs:

// 12
// 3
// 2 3 2 1 5 2 4 5 3 2 5 2
