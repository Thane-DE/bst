#ifndef BOOKS_H_
#define BOOKS_H_

struct Book {
	unsigned long ISBN;
	char *author_name;
	char *book_title;
};

struct Book *newBook(unsigned long ISBN_nr, char *author_name, char *book_title);

void destroy_book(struct Book *the_book);

unsigned long getISBN(struct Book *the_book);

const char *getTitle(struct Book *the_book);

const char *getAuthor(struct Book *the_book);

#endif /* BOOKS_H_ */
