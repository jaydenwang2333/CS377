#include <map>
#include <queue>
#include <set>
#include <string>
#include <fstream>
#include <inverter.h>
//#include<vector>
#include <sstream>
#include <iostream>
#include <ctype.h>


using namespace std;

//map<string,vector<int> > invertedIndex;
map<string, set<int> > invertedIndex;
string build_inverted_index(string filename) {

//int id;
int fileNumber = 0;
string fileName;
ifstream file;
file.open(filename);
string result;

// open input file
if(!file){
  cout<<"file open fail";
  exit(1);
}

// open file from input file 
while(getline(file,filename)){
  ifstream file2(filename);
  if(!file2){
    cout<<"file open fail";
    exit(1);
  }

  string text;
  string line;
  // get all text by line and store into string text
  while(getline(file2,line)){
    text+=line;
  }
  // chech letter
  for(string::size_type i = 0; i<text.length();i++){
    if(!isalpha(text[i]))
    text[i]=' ';
  }
  
  // find word from invertedIndex map 
  stringstream ss(text);
  string word;
  while(ss>>word){
    //if can not find word from map then add it to map
    if(invertedIndex.find(word)!= invertedIndex.end()) {
      invertedIndex[word].insert(fileNumber);
  }else {

    //if find it then, current file number will be its key.
                set<int> fileNumbers;
                fileNumbers.insert(fileNumber);
                //invertedIndex[word] = fileNumbers;
                invertedIndex.insert(pair<string,set<int>>(word,fileNumbers));
            }
        }
        fileNumber++;

        file2.close();
}
  map<string, set<int> >::iterator it;
   for (it = invertedIndex.begin(); it != invertedIndex.end(); it++) {
     result+=it->first+":"+" ";
   set<int> fileNumbers = it->second;
        set<int>::iterator it2;
        for (it2 = fileNumbers.begin(); it2 != fileNumbers.end(); it2++) {
            result+= *it2 + " ";
        }
        result+="\n";
   }

/*while(file){
  string temp;
  while(file>>temp){
    invertedIndex[temp].push_back(id);
  }
}
map<string,vector<int> >::iterator map_it;
map_it=invertedIndex.begin();
while(map_it != invertedIndex.end()){
    string temp1 = map_it->first;
    result+=temp1+" ";
    //cout<<temp1<<" ";
    for(int i = 0; i !=invertedIndex[temp1].size();i++)
    result+=invertedIndex[temp1][i]+" ";
    result+="\n";
    map_it++;
}*/
  return result;
}
