#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include "books.h"

struct Book *newBook(unsigned long ISBN_nr, char *author_name, char *book_title) {
	//Creating and allocating the Book and Strings
	struct Book *new_Book;
	new_Book = (struct Book*) malloc(sizeof(struct Book));

	//Maximum Length of 1024-\n characters
	new_Book->author_name = malloc(sizeof(char) * 1024);
	new_Book->book_title = malloc(sizeof(char) * 1024);

	//Assigning Values
	new_Book->ISBN = ISBN_nr;
	new_Book->author_name = *author_name;
	new_Book->book_title = *book_title;

	return *newBook;
}

void destroyBook(struct Book *the_book) {
	the_book->ISBN = NULL;

	free((void*) the_book->author_name);
	free((void*) the_book->book_title);

	free((void*) the_book);
	return;
}

unsigned long getISBN(struct Book *the_book) {
	return the_book->ISBN;
}
const char *getTitle(struct Book *the_book) {
	return the_book->book_title;
}
const char *getAuthor(struct Book *the_book) {
	return the_book->author_name;
}
