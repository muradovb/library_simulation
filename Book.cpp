//
//  Book.cpp
//  
//
//  Created by Bayram Muradov on 23/03/2017.
//  Copyright © 2017 Bayram Muradov. All rights reserved.
//

#include "Book.hpp"
#include "iostream"
#include <string>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctype.h>
using namespace std;

//constructor
Book::Book(string titlee, string pubHousee, int date) {
    arsize=0;   //authList array size
    title = titlee;
    pubHouse= pubHousee;
    pubYear=date;
    authList=NULL;
}
Book::Book() {
}

//deconstructor
Book::~Book() {
    if(authList!=NULL)
        delete [] authList;
}

//methods
void Book:: setListNull() {
    authList=NULL;
}
string Book::getTitle() {
    return title;
}
string Book::getPubHouse() {
    return pubHouse;
}
int Book::getpubYear() {
    return pubYear;
}

string * Book::getAlist(){
    return authList;
}

string Book:: getAlistIndex(int index) {
    if(index>arsize) {
        return 0;
    }
    
    else
    return authList[index];
}
int Book::getArsize() {
    return arsize;
}

void Book:: setTitle(string bookTitle) {
    title= bookTitle;
}

void Book::setPublishingHouse(string publishingHouse) {
    pubHouse=publishingHouse;
}

void Book:: setPublishingYear(int data) {
    pubYear=data;
}

void Book::addAuthor(string authorName) {
    string * temp=authList;
    arsize++;

    authList= new string[arsize];
    for(int i =0; i<arsize-1;i++) {
        authList[i]=temp[i];
    }
    authList[arsize-1] = authorName;
    if(temp!=NULL) {
        delete[] temp;
    }
}
void Book::removeAuthor(string authorname) {
    string*temp=authList;
    arsize--;
    authList = new string[arsize];
    int index=0;
    bool exist;
    for(int i =0; i<arsize; i++) {
        if(temp[i]==authorname) {
            exist=true;
            index=i;
            break;
        }
    }
    if(exist) {
        for(int i =0; i< index;i++) {
            authList[i]=temp[i];
        }
        for(int i=index+1; i<arsize+1;i++) {
            authList[i-1]=temp[i];
        }
    }
    if(temp!=NULL) {
        delete[] temp;
    }
}
void Book:: display() {
    cout<<"---------"<<endl;
    cout<<title<<endl;
    cout<<pubHouse<<endl;
    cout<<pubYear<<endl;
    for(int i=0; i<arsize; i++) {
        cout<<authList[i]<<endl;
    }
    cout<<"---------"<<endl;
}

//makes the book title lowercase
void Book:: caseLow(){
    int boundary = title.size();
    char*locarr=new char[boundary];
    
    for(int i =0; i<boundary; i++) {
        locarr[i]=title.at(i);
    }
    string empt="";
    for(int i=0; i<boundary; i++){
        empt+=tolower(locarr[i]);
    }
    title=empt;
    
    if(locarr!=NULL) {
        delete [] locarr;
    }
}
//makes the author names in the array lowercase
void Book:: caseAuthLow(){
    for(int i =0; i<arsize; i++) {
        turnAllLow(authList[i]);
    }
}

//helpful function that will help to turn authList members to lowercase
void Book:: turnAllLow(string input) {
    int boundary = input.size();
    char*locarr=new char[boundary];
    
    for(int i =0; i<boundary; i++) {
        locarr[i]=input.at(i);
    }
    string empt="";
    for(int i=0; i<boundary; i++){
        empt+=tolower(locarr[i]);
    }
    input=empt;
    
    if(locarr!=NULL) {
        delete [] locarr;
    }

}








