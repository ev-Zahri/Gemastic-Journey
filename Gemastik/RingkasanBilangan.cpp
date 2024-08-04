#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> numbers(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    std::sort(numbers.begin(), numbers.end());

    std::vector<std::pair<int, int>> summary;
    int start = numbers[0];
    int end = numbers[0];

    for(int i = 1; i < N; ++i) {
        if(numbers[i] == end + 1) {
            end = numbers[i];
        } else if (numbers[i] == end) {
            continue; // Skip duplicate numbers
        } else {
            summary.push_back({start, end});
            start = numbers[i];
            end = numbers[i];
        }
    }
    summary.push_back({start, end});

    for(size_t i = 0; i < summary.size(); ++i) {
        if(summary[i].first == summary[i].second) {
            std::cout << summary[i].first;
        } else {
            std::cout << summary[i].first << "-" << summary[i].second;
        }
        if(i != summary.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;

    return 0;
}
