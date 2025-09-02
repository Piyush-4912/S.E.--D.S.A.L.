/*A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. Find the time and space requirements of your method.*/
#include <iostream>
#include <string>
using namespace std;

// Node structure for Book/Chapter/Section
struct Node {
    string name;       // Name of the Book / Chapter / Section
    Node* link1;       // Pointers to sub-nodes (children)
    Node* link2;
    Node* link3;

    // Constructor for easy initialization
    Node(string n = "") {
        name = n;
        link1 = link2 = link3 = nullptr;
    }
};

// Global root pointer for the Book
Node* Root = nullptr;

// ================== TREE CREATION ==================

// Create Book (Root node)
void createBook() {
    string bookName;
    cout << "\nEnter the Book name: ";
    cin >> bookName;
    Root = new Node(bookName);
}

// Insert Chapter under Root
void insertChapter() {
    if (!Root) {
        cout << "\nCreate a book first!\n";
        return;
    }
    string chapName;
    cout << "\nEnter Chapter name: ";
    cin >> chapName;

    Node* temp = new Node(chapName);

    if (!Root->link1) Root->link1 = temp;
    else if (!Root->link2) Root->link2 = temp;
    else if (!Root->link3) Root->link3 = temp;
    else cout << "\nCan't add more than 3 Chapters.\n";
}

// Insert Section under a specific Chapter
void insertSection(Node* chapter) {
    if (!chapter) return;

    string secName;
    cout << "\nEnter Section name for Chapter " << chapter->name << ": ";
    cin >> secName;

    Node* temp = new Node(secName);

    if (!chapter->link1) chapter->link1 = temp;
    else if (!chapter->link2) chapter->link2 = temp;
    else if (!chapter->link3) chapter->link3 = temp;
    else cout << "\nCan't add more than 3 Sections.\n";
}

// Wrapper for inserting Sections into a chosen Chapter
void insertSections() {
    if (!Root) {
        cout << "\nCreate a book first!\n";
        return;
    }

    int chap;
    cout << "\nEnter Chapter number to insert Sections (1/2/3): ";
    cin >> chap;

    Node* selected = nullptr;
    if (chap == 1) selected = Root->link1;
    else if (chap == 2) selected = Root->link2;
    else if (chap == 3) selected = Root->link3;

    if (!selected) {
        cout << "\nInvalid choice or Chapter not created yet.\n";
        return;
    }

    // Let user insert up to 3 sections
    for (int i = 0; i < 3; i++) {
        char choice;
        cout << "Do you want to add Section " << (i + 1) << "? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
            insertSection(selected);
    }
}

// ================== DISPLAY TREE ==================

// Display the Book → Chapters → Sections
void displayTree() {
    if (!Root) {
        cout << "\nNo Book created yet!\n";
        return;
    }

    cout << "\nBook: " << Root->name;

    Node* chapters[3] = {Root->link1, Root->link2, Root->link3};

    for (int i = 0; i < 3; i++) {
        if (chapters[i]) {
            cout << "\n  Chapter " << (i + 1) << ": " << chapters[i]->name;

            Node* sections[3] = {chapters[i]->link1, chapters[i]->link2, chapters[i]->link3};
            for (int j = 0; j < 3; j++) {
                if (sections[j])
                    cout << "\n     Section " << (j + 1) << ": " << sections[j]->name;
            }
        }
    }
}

// ================== MAIN ==================
int main() {
    cout << "\n# PRACTICAL NO. 03 (B_5) - GENERAL TREE IMPLEMENTATION #";

    createBook();

    // Insert 3 Chapters
    for (int i = 0; i < 3; i++) {
        char choice;
        cout << "\nDo you want to add Chapter " << (i + 1) << "? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
            insertChapter();
    }

    // Insert Sections in Chapters
    for (int i = 0; i < 3; i++) {
        char choice;
        cout << "\nDo you want to add Sections in any Chapter? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
            insertSections();
    }

    // Display entire tree
    displayTree();

    return 0;
}
