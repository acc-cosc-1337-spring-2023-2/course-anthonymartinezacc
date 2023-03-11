//header file to hold function prototypes for the DNA script
//contributors: Anthony
//progress: complete
using std::string;

double get_gc_content(const string& dnaString);

string get_dna_complement(string dnaString);

string reverse_string(string dnaStringComplement);

bool onlyConsistsOf(string& dnaString, string& dnaCharacters);
