#include "Book.h"
#include "Page.h"
#include <bits/stdc++.h> 
using namespace std;

void Book::build_index(const set<string>& words){
    for(string w : words){
        set<size_t> index = {}; //*declare index
        size_t curr = 1;        //*declare number to be added 

        for(Page p : book_){    //*enter the pages of the book

            for(size_t i = 0; i < p.get_num_lines(); i++){  //*iterate over all lines of the page
                string s = p.get_line(i);                   //*load line into a string
                if(s.find(w) != s.npos){                              //*check if word is in line
                    index.insert(curr);                     //*add index to the set if string in line
                    break;
                }
            }
            curr++;

        }
    if(!index.empty()){
        index_.insert({w,index});
        }
    index.clear();    
    }
}