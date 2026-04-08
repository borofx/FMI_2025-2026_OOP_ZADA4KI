#include <iostream>
#include <cstring>

class Book{
private: 
    char* name;
    char* author;
    int year;
    long int ISBN;

    void deepCopy(const char* src, char*& dest){
        if(src){
            dest = new char[strlen(src)+1];
            strcpy(dest,src);

        }else{
            dest = new char[1];
            dest[0] = '\0';
            return;
        }
    }
    void copyFrom(const Book& other){
        deepCopy(other.name, name);
        deepCopy(other.author, author);
        year = other.year;
        ISBN = other.ISBN;
    }
    void free(){
        delete[] name;
        name = nullptr;
        delete[] author;
        author = nullptr;
        year = 0;
        ISBN = 0;
    }
public:

    long int getISBN() const {
        return ISBN;
    }
    const char* getAuthor() const{
        return author;
    }
    const char* getName() const{
        return name;
    }
    Book(){
        name = new char[1];
        name[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        year = 0;
        ISBN = 0;
    }
    Book(const char* n, const char* au, int ye, long int isb){
        deepCopy(n,name);
        deepCopy(au,this->author);
        year = ye;
        ISBN = isb;
    }
    Book(const Book& other){
        copyFrom(other);
    }
    Book& operator=(const Book& other){
        if(this != &other){
            free();
            copyFrom(other);
        }
        return *this;
    }
    ~Book(){
        free();
    }
    friend std::ostream& operator<<(std::ostream& os, const Book& book){
        os << '"' << (book.name ? book.name : "Unknown") << '"'
           << " by " << (book.author ? book.author : "Unknown") 
           << " (" << book.year << ") - ISBN: " << book.ISBN;
           return os; 
    }
};

class Library{
private: 
    Book* books;
    size_t capacity;
    size_t count;

    void copyFrom(const Library& other){
        capacity = other.capacity;
        count = other.count;
        books = new Book[capacity];

        for(int i = 0; i < count; i++){
            books[i] = other.books[i];
        }
    }
    
    void free(){
        delete[] books;
        books = nullptr;
        capacity = 0;
        count = 0;
    }

    void resize(){
        if(capacity == 0) capacity = 1;
        capacity *= 2;
        Book* newBooks = new Book[capacity];

        for(int i = 0; i < count; i++){
            newBooks[i] = books[i];
        }

        delete[] books;
        books = newBooks;
    }

    public:
        Library(){
            capacity = 2;
            count = 0;
            books = new Book[capacity];
        }

        Library(const Library& other){
            copyFrom(other);
        }
        Library& operator=(const Library& other){
            if(this != &other){
                free();
                copyFrom(other);
            }
            return *this;
        }

        ~Library(){
            free();
        }

        void addBook(const Book& newBook){
            if(count == capacity)
                resize();

                books[count] = newBook;
                count++;
        }

        void removeBook(long int searchISBN){
            for(int i = 0; i < count; i++){
                if(books[i].getISBN() == searchISBN){
                    for(int j = i; j < count - 1; j++){
                        books[j] = books[j+1];
                    }
                    count--;
                    break;            
                }
            }
                std::cout << "Book not found!\n";
        }

        void findBookByAuthor(const char* author){
            bool found = false;
            for(int i = 0; i < count; i++){
                if(strcmp(books[i].getAuthor(),author) == 0){
                    std::cout << "Found book " << books[i].getName() << '\n';
                    found = true;
                }
            }
            if(!found)
                std::cout << "No books were found \n";
        }

        friend std::ostream& operator<<(std::ostream& os, const Library& lib){
            if(lib.count == 0){
                os<< "The library is empty. \n";
                return os;
            }

            os << "=== Library Contents (" << lib.count << " books) ===\n";
            for(int i = 0; i < lib.count; i++){
                os << i + 1 << ". " << lib.books[i] << '\n';
            }
            os << "======================\n";
            return os;
        }
};


int main(){

}