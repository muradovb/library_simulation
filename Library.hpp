//
//  Library.hpp
//  
//
//  Created by Bayram Muradov on 23/03/2017.
//  Copyright © 2017 Bayram Muradov. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp

#include <stdio.h>
#include <iostream>
#include "Book.hpp"
using namespace std;

class Library {
public:
//constructor proto
Library ();

//destructor proto
~Library ();

//methods proto
void addBook( string bookTitle, string publishingHouse, int publishingYear );

void removeBook( string bookTitle );

void addCoauthor( string bookTitle, string coauthorName );

void removeCoauthor ( string bookTitle, string coauthorName );

void displayAllBooks();

void displayBook( string bookTitle );

void displayAuthor( string authorName );

void display();

void makeAllLow();

void turnLow(string input);
    
Book* getBooks() {
        return books;
}
    
private:
        int size;
        Book *books;
};

#endif /* Library_hpp */

