#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,string> id1,pair<int,string> id2){
    if(id1.first != id2.first)
        return id1.first < id2.first;
    else
        return id1.second > id2.second;
}

void make_reading(string input){
    /* STRUCTURES */

    //Key: student id
    //Value: project name
    map<string, string> students;

    //List of students erased
    set<string> erased;

    //Projects
    map<string, set<string>> projects;

    /*ALGORITHM*/
    string cur_project;
    while(input != "1"){
        if('A' <= input[0] && input[0] <= 'Z'){//Input is cur_project
            cur_project = input;
            //Create a set to consider empty sets
            set<string> empty_set;
            projects[ cur_project ] = empty_set;
        }else{//Input is student id
            //If the student isn't in erased set
            if( erased.find(input) == erased.end() ){
                //If the students don't have project  OR the project that it have is the same
                if(students.count(input) == 0 || students[input] == cur_project){
                    students[input] = cur_project;
                    projects[cur_project].insert(input);
                }else{
                    erased.insert(input);
                    projects[ students[input] ].erase(input);
                    students.erase(input);
                }
            }
        }
        getline(cin, input);
    }

    /* PRINTED */
    //Control the priority of printed of project
    //First element: legth
    //Second element: project name
    priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(&cmp) > printed (&cmp);

    //Constructor of the priority_queue
    for(auto it : projects){
        printed.push( make_pair(it.second.size(),it.first) );
    }

    //Printed
    while(!printed.empty()){
        cout << printed.top().second << " " << printed.top().first << endl;
        printed.pop();
    }
}

int main(){
    string input;
    getline(cin, input);
    while(input != "0"){
        make_reading(input);
        getline(cin, input);
    }

    return 0;
}


//Name projects
//Subscribed
//Again

//Erased: set
//Dict: id -> project (control the unique)
//Dict: project -> [ids] (control the students)