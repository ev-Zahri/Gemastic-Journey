#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    list<int> cardStack;
    unordered_map<int, list<int>::iterator> cardMap;
    
    for (int i = 0; i < N; ++i) {
        int card;
        cin >> card;
        cardStack.push_back(card);
        cardMap[card] = --cardStack.end();
    }
    
    for (int i = 0; i < K; ++i) {
        char operation;
        int X;
        cin >> operation >> X;
        
        if (operation == 'A') {
            if (cardMap.find(X) == cardMap.end()) {
                cardStack.push_front(X);
                cardMap[X] = cardStack.begin();
            }
        } else if (operation == 'G') {
            if (cardMap.find(X) != cardMap.end()) {
                auto it = cardMap[X];
                list<int> tempList(it, cardStack.end());
                cardStack.erase(it, cardStack.end());
                cardStack.insert(cardStack.begin(), tempList.begin(), tempList.end());
                
                for (auto tempIt = cardStack.begin(); tempIt != cardStack.end(); ++tempIt) {
                    cardMap[*tempIt] = tempIt;
                }
            }
        }
    }
    
    // Output the results
    cout << cardStack.size() << endl;
    for (const int& card : cardStack) {
        cout << card << " ";
    }
    cout << endl;
    
    return 0;
}
