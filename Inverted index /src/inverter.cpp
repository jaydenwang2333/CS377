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
//map<string, set<int> > invertedIndex;
string build_inverted_index(string filename) {
map<string, set<int> > invertedIndex;
//int id;
int fileNumber = 0;
string fileName;
ifstream file;
file.open(filename);
string result;
if(!file){
  cout<<"file open fail";
  exit(1);
}
while(getline(file,filename)){
  ifstream file2(filename);
  if(!file2 || file2.eof()){
    cout<<"file open fail";
    continue;
    //exit(1);
  }
  

  string text;
  string line;
  while(getline(file2,line)){
    text+=line+" ";
  }
  
  for(string::size_type i = 0; i<text.length();i++){
    if(!isalpha(text[i]))
    text[i]=' ';
  
  
  }
  stringstream ss(text);
  string word;
  //set<int> fileNumbers;
  while(ss>>word){
    //result+=word;
    if(invertedIndex.find(word)!= invertedIndex.end()) {
      invertedIndex[word].insert(fileNumber);

	
  }else {
                set<int> fileNumbers;
                fileNumbers.insert(fileNumber);
                invertedIndex[word]=fileNumbers;
                //invertedIndex.insert(pair<string,set<int>>(word,fileNumbers));
		
            }
        }
        fileNumber++;

        file2.close();
}
  map<string, set<int> >::iterator it;
   for (it = invertedIndex.begin(); it != invertedIndex.end(); it++) {
    result+=it->first+":"+" ";
   set<int> fileNumber2 = it->second;
        set<int>::iterator it2;
       for (it2 = fileNumber2.begin(); it2 != fileNumber2.end(); it2++) {
          int temp = *it2;
          stringstream xd;
          xd<<temp;
          result+=xd.str()+" ";
            //result+=*it2 + " ";
        }
        result.pop_back();
      result+="\n";
   }


  return result;
}
