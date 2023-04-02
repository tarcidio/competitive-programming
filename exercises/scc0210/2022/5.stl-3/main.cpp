#include <bits/stdc++.h>

using namespace std;

// True: id1 < id2
bool cmp(pair<int, string> id1, pair<int, string> id2) {
  if (id1.first != id2.first)
    return id1.first < id2.first;
  else
    return id1.second > id2.second;
}

void print_ans(map<string, set<string>> projects,
               map<string, string> students) {
  /* PRINTED */
  // Control the priority of printed of project
  // First element: legth
  // Second element: project name
  vector<pair<int, string>> printed;

  for (auto it : projects) {
    int cont = 0;
    for (auto id : it.second)
      if (students[id] != "-1")
        cont++;
    printed.push_back(make_pair(cont, it.first));
  }

  // Constructor of the priority_queue
  /*for (auto it : projects)
    printed.push_back(make_pair(it.second.size(), it.first));*/
  sort(printed.rbegin(), printed.rend(), cmp);

  // Printed
  for (auto it : printed)
    cout << it.second << " " << it.first << endl;
}

void make_reading(string input) {
  /* STRUCTURES */

  // Key: student id
  // Value: project name
  map<string, string> students;

  // Projects
  map<string, set<string>> projects;

  /*ALGORITHM*/
  string cur_project;
  while (input != "1") {
    if ('A' <= input[0] && input[0] <= 'Z') { // Input is cur_project
      cur_project = input;
      // Create a set to consider empty sets
      projects[cur_project] = {};
    } else { // Input is student id
      if (students.count(input) == 0 || students[input] == cur_project) {
        students[input] = cur_project;
        projects[cur_project].insert(input);
      } else if (students[input] != "-1") {
        // projects[students[input]].erase(input);
        students[input] = "-1";
      }
    }
    getline(cin, input);
  }
  print_ans(projects, students);
}

int main() {
  string input;
  getline(cin, input);
  while (input != "0") {
    make_reading(input);
    getline(cin, input);
  }

  return 0;
}
