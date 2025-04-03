#include <iostream>
#include <string>
using namespace std;

// Base Media class
class Media {
public:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool checkedOut;

    Media(string t, string pd, string id, string pub)
        : title(t), publicationDate(pd), uniqueID(id), publisher(pub), checkedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Status: " << (checkedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if (!checkedOut) {
            checkedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem() {
        if (checkedOut) {
            checkedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    virtual ~Media() {}
};

// Book class
class Book : public Media {
public:
    string author;
    string ISBN;
    int numberOfPages;

    Book(string t, string pd, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pd, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        cout << "BOOK DETAILS" << endl;
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }
};

// DVD class
class DVD : public Media {
public:
    string director;
    int duration; // in minutes
    string rating;

    DVD(string t, string pd, string id, string pub, string dir, int dur, string rat)
        : Media(t, pd, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override {
        cout << "DVD DETAILS" << endl;
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};

// CD class
class CD : public Media {
public:
    string artist;
    int numberOfTracks;
    string genre;

    CD(string t, string pd, string id, string pub, string art, int tracks, string gen)
        : Media(t, pd, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        cout << "CD DETAILS" << endl;
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

// Search functions
void searchByTitle(Media* media, string title) {
    if (media->title == title) {
        media->displayInfo();
    }
}

void searchByID(Media* media, string id) {
    if (media->uniqueID == id) {
        media->displayInfo();
    }
}

int main() {


    return 0;
}