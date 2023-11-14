#include <vector>

#include "book.h"

int main()
{

    Book emptyBook = Book();

    Book c_prog = Book("The C Programming Language","9780131101630",272);

    std::vector<Book*> HarryPotter(7);
    HarryPotter[0] = new Book("Sorcerer's Stone","978-0-7475-3269-9",223);
    HarryPotter[1] = HarryPotter[0]->make_next_book("Chamber of Secrets","0-7475-3849-2",251);
    HarryPotter[2] = HarryPotter[1]->make_next_book("Prisoner of Azkaban","0-7475-4215-5",317);
    HarryPotter[3] = HarryPotter[2]->make_next_book("Goblet of Fire","0-7475-4624-X",636);
    HarryPotter[4] = HarryPotter[3]->make_next_book("Order of the Phoenix","0-7475-5100-6",766);
    HarryPotter[5] = HarryPotter[4]->make_next_book("Half Blood Prince","0-7475-8108-8",607);
    HarryPotter[6] = HarryPotter[5]->make_next_book("Deathly Hallows","0-7475-9105-9",607);

    emptyBook.print_all();
    c_prog.print_all();

    for(Book* book : HarryPotter)
    {
        book->print_all();
    }

    return 0;
}