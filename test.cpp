#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers{1, 2, 3, 4, 5, 6, 7};

  cout << numbers.size() << endl;

  for (int i = numbers.size() - 1; i >= 0; --i) {
  }

  for (int i = 1; i < numbers.size() - 1; ++i)
    numbers[i] = numbers[i + 1];

  for (int i = 0; i < numbers.size() - 1;)
    cout << numbers[i++] << ' ' << endl;

  return 0;
}

