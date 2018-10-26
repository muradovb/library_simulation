//
//  Library.cpp
//  
//
//  Created by Bayram Muradov on 23/03/2017.
//  Copyright © 2017 Bayram Muradov. All rights reserved.
//

#include "Library.hpp"

#include "Book.hpp"
#include "iostream"
#include <string>
#include <stdio.h>
using namespace std;

//constructor
Library:: Library() {
    size=0;
    books = new Book[size];
}

//deconstructor
Library:: ~Library() {
    delete[]books;
}

//methods
void Library:: addBook( string bookTitle, string publishingHouse, int publishingYear ) {
    makeAllLow(); //making every title lowercase
    turnLow(bookTitle);
    bool start=true;
    for(int i=0; i<size;i++) {
        if(books[i].getTitle()==bookTitle) {
            start = false;
            cout<<"operation cannot be performed. book already exists"<<endl;
            //break;
        }
    }
    if(start) {
        Book * temp = books;
        size++;
        books = new Book[size];
        for (int i =0; i <size-1; i++) {
            books[i] =temp[i];
            //the last element in the array is "GARBAGE BOOK"
        }
        //setting properties of the garbage book to our "DESIRED BOOK"
        books[size-1].setTitle(bookTitle);
        books[size-1].setPublishingHouse(publishingHouse);
        books[size-1].setPublishingYear(publishingYear);
        books[size-1].setListNull();
        if(temp!=NULL) {
            delete[] temp;
        }
    }
}

//makes every book in the library lowercase
void Library::makeAllLow() {
    for(int i =0; i<size; i++) {
        books[i].caseLow();
    }
}


void Library::display() {
    for(int i=0; i<size; i++) {
        (books[i]).display();
    }
}

void Library::displayAllBooks(){
    display();
}

void Library::displayBook(string bookTitle) {
    bool exist=false;
    int index=0;
    for(int i =0; i<size; i++) {
        if(books[i].getTitle()==bookTitle) {
            exist = true;
            index=i;
            break;
        }
    }
    if(exist) {
        (books[index]).display();
        
    }
    else
        cout<<"d.n.e"<<endl;
}

void Library:: addCoauthor(string bookTitle, string coauthorName) {
    makeAllLow();
    //turning the coauthorName to lowercase
    turnLow(coauthorName);
    //turning every authorname to lowercase
    for(int i =0; i<size; i++) {
        books[i].caseAuthLow();
    }
    bool exist=false;
    bool start=true;
    int index =0;
    for(int i =0; i<size; i++) {
        if(books[i].getTitle()==bookTitle) {
            exist =true;
            index=i; //finding the specific book
            break;
        }
    }
    for(int i =0; i<(books[index].getArsize()); i++){
        if(books[index].getAlistIndex(i)==coauthorName){
            start=false;
            break;
        }
    }
    
    if(exist&&start) {
        books[index].addAuthor(coauthorName);
    }
    else
        cout<<"operation cannot be performed"<<endl;
    
}
void Library::displayAuthor(string authorName) {
    bool exist = false;
    turnLow(authorName); //turning string to lowercase
    for(int i =0; i<size; i++) {
        books[i].caseAuthLow(); //making all authornames in the books lowercase
    }
    
    for (int i=0; i<size; i++) {
        for(int j=0; j<(books[i].getArsize()); j++) {
            if(books[i].getAlistIndex(j)==authorName) {
                exist=true;
            }
        }
    }
    if(exist==true) {
        for (int i=0; i<size; i++) {
            for(int j=0; j<(books[i].getArsize()); j++) {
                if(books[i].getAlistIndex(j)==authorName) {
                    cout<<books[i].getAlistIndex(j)<<endl;
                }
            }
        }
    }
    else
        cout<<"author doesnt have a book in lib."<<endl;
}

void Library::removeBook(string bookTitle){
    //making all book titles lowercase
    makeAllLow();
    //making bookTitle lowercase
    turnLow(bookTitle);
    //check whether the book exists or not
    bool exist = false;
    for(int i =0; i<size; i++) {
        if(books[i].getTitle()==bookTitle) {
            exist=true;
            break;
        }
    }
    if(exist) {
        Book * temp = books;
        size--;
        books = new Book [size];
        //getting the index of desired book
        for (int i = 0; i<size+1; i++) {
            //finding the desired book in the array
            if(temp[i].getTitle()==bookTitle) {
                //copying first half
                for(int j=0; j<i; j++) {
                    books[j] = temp[j];
                }
                //copying second half
                for(int j=i+1; j<size+1; j++) {
                    books[j-1] = temp[j];
                }
            }
        }
        if(temp!=NULL) {
            delete [] temp;
        }
        cout<<"removed"<<endl;
    }
    else {
        cout<<"d.n.e"<<endl;
    }
    
    
}

void Library::removeCoauthor(string bookTitle, string coauthorName) {
    //turning string to lowercase
    turnLow(coauthorName);
    //turning every book authors to lowercase
    for(int i =0; i<size; i++) {
        books[i].caseAuthLow();
    }
    bool exist_book = false;
    int index=0;
    for(int i =0;i<size; i++) {
        if(books[i].getTitle()==bookTitle) {
            exist_book=true;
            break;
        }
    }
    if(exist_book) {
        for(int i =0;i<size; i++) {
            if(books[i].getTitle()==bookTitle) {
                index=i;
                break;
            }
        }
        cout<<"book found"<<endl;
        bool exist_author;
        int boundary=books[index].getArsize();
        for(int i=0; i<boundary; i++) {
            if(books[index].getAlistIndex(i)==coauthorName) {
                exist_author=true;
                break;
            }
        }
        if(exist_author) {
            books[index].removeAuthor(coauthorName);
            cout<<"author removed";
        }
        else
            cout<<"author d.n.e"<<endl;
    }
    if(exist_book==0)
        cout<<"book d.n.e"<<endl;
}

//function that is helpful to make strings lowercase
void Library:: turnLow(string input) {
    int boundary = input.size();//getting input size
    char*locarr=new char[boundary]; // creating char array that will keep the chars
    //filling array
    for(int i =0; i<boundary; i++) {
        locarr[i]=input.at(i);
    }
    string empt="";
    for(int i=0; i<boundary; i++){
        empt+=tolower(locarr[i]); //turning the string to lowercase
    }
    input=empt;
    
    if(locarr!=NULL) {
        delete [] locarr;
    }
}





