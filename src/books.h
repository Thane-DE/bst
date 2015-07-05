#ifndef BOOKS_H_
#define BOOKS_H_

struct Book {
	unsigned long ISBN;
	const char *author_name;
	const char *book_title;
};

struct Book *newBook(unsigned long ISBN_nr, char *author_name, char *book_title);

void destroyBook(struct Book *the_book);

unsigned long getISBN(struct Book *the_book);

const char *getTitle(struct Book *the_book);

const char *getAuthor(struct Book *the_book);

#endif /* BOOKS_H_ */
