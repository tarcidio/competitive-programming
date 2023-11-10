#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> books, int value) {
  int num_books = books.size();
  vector<tuple<int, int, int>> ans;
  for (int i = 0; i < num_books; i++) {
    for (int j = i + 1; j < num_books; j++) {
      if (books[i] + books[j] == value) {
        if (books[i] < books[j])
          ans.emplace_back(abs(books[i] - books[j]), books[i], books[j]);
        else
          ans.emplace_back(abs(books[i] - books[j]), books[j], books[i]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << "Peter should buy books whose prices are " << get<1>(ans[0])
       << " and " << get<2>(ans[0]) << "." << endl << endl;
}

int main() {
  int num_books;

  while (cin >> num_books) {
    // Reading
    vector<int> books;
    int book;
    while (num_books--) {
      cin >> book;
      books.push_back(book);
    }
    int value;
    cin >> value;
    // Algorithm
    solve(books, value);
  }

  return 0;
}
