//functions for find DNA script
//contributors: Anthony
//progress: complete
#include "func.h"
using std::string;

//solves what precent of the tring is made of either G or C.
double get_gc_content(const string& dnaString){
    double dnaStringLegth,      //character length of string
           dnaGCammount = 0,   //count of 'G' 'C' 'g' & 'c' in the string
           dnaGCprecent;      //(dnaGCammount/dnaStringLegth)*100

    //gets string length
    dnaStringLegth = dnaString.length();

    //counts number of G & C's in the tring
    for (int i = 0; i < dnaString.size(); i++)
        if (dnaString[i] == 'G') dnaGCammount++;
    for (int i = 0; i < dnaString.size(); i++)
        if (dnaString[i] == 'C') dnaGCammount++;
    for (int i = 0; i < dnaString.size(); i++)
        if (dnaString[i] == 'g') dnaGCammount++;
    for (int i = 0; i < dnaString.size(); i++)
        if (dnaString[i] == 'c') dnaGCammount++;

    //calculates precent
    dnaGCprecent = (dnaGCammount/dnaStringLegth)*100;

return dnaGCprecent;
}

//makes every 'A' a 'T', every 'T' an 'A', every 'G' a 'C', and every 'C' a 'G'
string get_dna_complement(string dnaString){
    string dnaStringComplement;
    for (char c : dnaString) {
        switch (c) {
            case 'A': dnaStringComplement += 'T'; break;
            case 'T': dnaStringComplement += 'A'; break;
            case 'C': dnaStringComplement += 'G'; break;
            case 'G': dnaStringComplement += 'C'; break;
            case 'a': dnaStringComplement += 't'; break;
            case 't': dnaStringComplement += 'a'; break;
            case 'c': dnaStringComplement += 'g'; break;
            case 'g': dnaStringComplement += 'c'; break;
            default: dnaStringComplement += c;
        }
    }
    dnaStringComplement = reverse_string(dnaStringComplement);
return dnaStringComplement;
}

//reverses the string
string reverse_string(string dnaStringComplement){

std::reverse(dnaStringComplement.begin(), dnaStringComplement.end());

return dnaStringComplement;
}

//check if our string only has 'A' 'T' 'G' 'C' 'a' 't' 'g' 'c' characters
bool onlyConsistsOf(string& dnaString, string dnaCharacters)
//2nd string doesn't have an & (& is binding reference) because you can't bind a non constat to a constant
{
    // Both empty?
    if (dnaString.length() == 0 && dnaCharacters.length() == 0) {
        return true;
    }

    // Text empty and pattern obviously not?
    if (dnaString.length() == 0) {
        return false;
    }

    // Pattern empty and text obviously not?
    if (dnaCharacters.length() == 0) {
        return false;
    }

    // For each char in text
    for (unsigned int i = 0; i < dnaString.length(); ++i)
    {
        // Check if it is one of the chars in the pattern
        bool valid = false;
        for (unsigned int j = 0; j < dnaCharacters.length(); ++j)
        {
            if (dnaString.at(i) == dnaCharacters.at(j))
            {
                valid = true;
                break;
            }
        }

        if (!valid)
        {
            return false;
        }
    }

    return true;
}
