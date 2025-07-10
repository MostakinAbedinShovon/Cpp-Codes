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
    set<int> currentPages;
    int hits = 0, misses = 0;
    for (int i = 0; i < numberOfPageSequences; i++){
        int page = pageSequences[i];
        bool hitOrNot = false;
        if (currentPages.find(page) != currentPages.end()){
            hitOrNot = true;
            hitMiss[i] = 'H';
            hits++;}
        else {
            hitMiss[i] = 'M';
            misses++;
            if (currentPages.size() < numberOfFrames) currentPages.insert(page);
            else {
                int farthestUse = -1;
                int pageToReplace = -1;
                for (int p : currentPages){
                    bool found = false;
                    for (int j = i + 1; j < numberOfPageSequences; j++){
                        if (pageSequences[j] == p){
                            found = true;
                            if (j > farthestUse){
                                farthestUse = j;
                                pageToReplace = p;}
                            break;}}
                    if (!found){
                        pageToReplace = p;
                        break;}}
                currentPages.erase(pageToReplace),currentPages.insert(page);}}
        int idx = 0;
        for (int val : currentPages){
            if (idx < numberOfFrames)
                table[idx][i] = val;
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
