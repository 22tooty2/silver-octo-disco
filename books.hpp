#ifndef my_lib
#define my_lib

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#define max_adult_books 2

// Book class
class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
public:
    Book(std::string title, std::string author, std::string isbn);
    std::string getTitle(); // return book title
    std::string getAuthor(); // return book author
    std::string getIsbn(); // return isbm number
};

// User class
class User {
private:
    std::string name;
public:
    User(std::string name);
    std::string getName(); // return user name
    virtual std::vector<Book*> getBorrowedBooks(); // return the borrowed books (if exists)
    virtual void borrowBook(Book* book); // setter to borrowed book
    virtual void returnBook(Book* book); // setter to remove his book
};

class BabyUser {
    private:
        std::vector<Book> borrowedBook;
    public:
        BabyUser(std::string name);
        void borrowBook(Book* book) override;
        void returnBook(Book* book) override;
}

class AdultUser {
    private:
        Book* borrowedBook;
    public:
    AdultUser(std::string name);
    void borrowBook(Book* book) override;
    void returnBook(Book* book) override;
}

// Library class
class Library {
private:
    std::vector<Book*> books; // vector of books in library
    std::vector<User*> users; // vector of users in library
public:
    Library(); // I don't need a constructor for this, vectors will start empty by default.
    void addBook(Book* book); // add given book to library
    void removeBook(Book* book); // remove given book from library
    void addUser(User* user); // add given user to library
    void removeUser(User* user); // remove given user from library
    void checkOutBook(User* user, Book* book); // save book to user
    void checkInBook(User* user); // remove book from user
    void checkInBook(User* user, Book* book); // remove book from adult user
    void saveToFile(); // save library state to file
    void loadFromFile(); // load library state from file
};
#endif