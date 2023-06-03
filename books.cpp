#include <books.hpp>

// Methods for class "Book":

Book::Book(std::string title, std::string author, std::string isbn)
{
    this->title = title;
    this->author = author;
    this->isbn = isbn;
}
std::string Book::getTitle()
{
    return this->title;
}
std::string Book::getAuthor()
{
    return this->author;
}
std::string Book::getIsbn()
{
    return this->isbn;
}

// ---------------------------------------------------------------------------------------- //
// Methods for class "User":

User::User(std::string name)
{
    this->name = name;
    this->borrowedBook = NULL;
}
std::string User::getName()
{
    return this->name;
}
Book* User::getBorrowedBook()
{
    return this->borrowedBook; // book will always have a value or be null.
}
void User::borrowBook(Book* book)
{
    if (book == NULL)
    {
        // given Book is null!
        return;
    }
    this->borrowedBook = book;
}
void User::returnBook()
{
    this->borrowedBook = NULL;
}

// ---------------------------------------------------------------------------------------- //
// Methods for class "Library":

void Library::addBook(Book* book)
{
    this->books.push_back(book);
}
void Library::removeBook(Book* book)
{
    if (this->books.empty() || book == NULL)
        return;
    
    // search for book and remove if found
    for (size_t i = 0; i < this->books.size(); i++)
    {
        if (book == this->books[i])
        {
            this->books.erase(this->books.begin() + i); // I heard it's good practice to do this
            std::cout << "Successfully Removed" << std::endl;
            return;
        }
    }

    std::cout << "Nothing was removed:\n Book was not in library." << std::endl;
}
void Library::addUser(User* user)
{
    this->users.push_back(user);
}
void Library::removeUser(User* user)
{
    if (this->users.empty() || user == NULL)
        return;
    
    // search for user and remove if found
    for (size_t i = 0; i < this->users.size(); i++)
    {
        if (user == this->users[i])
        {
            this->users.erase(this->users.begin() + i);
            std::cout << "Successfully Removed" << std::endl;
            return;
        }
    }
    
    std::cout << "Nothing was removed:\n User was not in library." << std::endl;
}

void Library::checkOutBook(User* user, Book* book)
{
    if (user == NULL || book == NULL)
        return;
    
    if (user->getBorrowedBook() != NULL)
    {
        std::cout << "You already borrowed a book." << std::endl;
        return;
    }

    for (size_t i = 0; i < this->books.size(); i++)
    {
        if (book == this->books[i])
        {
            user->borrowBook(this->books[i]); // add book to user
            this->books.erase(this->books.begin() + i); // remove book from library
            std::cout << "Done. Enjoy your book!" << std::endl;
            return;
        }
    }
    
    std::cout << "sorry: Book was not in library." << std::endl;
    return;
}
void Library::checkInBook(User* user)
{
    if (user == NULL || user->getBorrowedBooks() == NULL)
        return;
    
    this->addBook(user->getBorrowedBooks());
    user->returnBook();

    std::cout << "Thanks, we hope to see you again." << std::endl;
}
void Library::checkInBook(User* user, Book* book)
{
    
}
void Library::saveToFile()
{
    std::ofstream outFile("mylibrary.bin", std::ios::binary);
    outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outFile.close();
}
void Library::loadFromFile()
{
    std::ifstream inFile("mylibrary.bin", std::ios::binary);
    if (inFile)
    {
        inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
        inFile.close();
    }
}
