#include<string>
using std::string;
typedef string::size_type sz;

void reset(int *);
void reset(int &);
string::size_type find_char(const string, char, string::size_type &);
bool is_sentence(const string &);
void print(const char *);
void print(const int *, const int *);
void print(const int[], size_t);
void print(int (&arr)[10]);
int factorial(int);
// no default for the heit or width paramters
void screen(sz, sz, char = ' ');
// error: redelaration in char
//void screen(sz = 24, sz = 80, char = ' ');
// ok: adds default arguments
void screen(sz = 24, sz = 80, char);