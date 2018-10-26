//
//  Book.hpp
//  homework1_201
//
//  Created by Bayram Muradov on 23/03/2017.
//  Copyright © 2017 Bayram Muradov. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <iostream>
using namespace std;



class Book {
    
    //constructor proto
    public:
    Book();
    Book(string title, string pubHouse, int pubYear);
    //deconstructor proto
    ~Book();
    //methods proto
    string getTitle();
    void caseLow();
    void turnAllLow(string input);
    void caseAuthLow();
    void setListNull();
    string getPubHouse();
    int getpubYear();
    string * getAlist();
    void setTitle(string bookTitle);
    void setPublishingHouse(string publishingHouse);
    void setPublishingYear(int data);
    void display();
    void addAuthor(string authorName);
    void removeAuthor(string authorname);
    string getAlistIndex(int index);
    int getArsize();
    //properties
    private:
    string title;
    string pubHouse;
    int pubYear;
    string *authList;
    int arsize;
    

};
#endif /* Book_hpp */
