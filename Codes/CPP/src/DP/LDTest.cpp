#include "LD.h"
#include <iostream>
#include <string>
using namespace std;

void
test_LD() {
    string s1("abc");
    string s2("yabd");
    int count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 2" << endl;

    s1 = "biting";
    s2 = "mitten";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count <<  " -> Expected: 4 " << endl;

    s1 = "abbbbbbbbb";
    s2 = "bbbbbbbbba";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count <<" -> Expected: 2" << endl;

    s1 = "aaaabbbb";
    s2 = "aabbaabb";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 4" <<endl;


    s1 = "cereal";
    s2 = "saturday";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 6" << endl;

    s1 = "";
    s2 = "abc";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 3" << endl;

    s1 = "123";
    s2 = "abc";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 3" << endl;


    s1 = "xabc";
    s2 = "abcx";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 2" << endl;

    s1 = "table";
    s2 = "bal";
    count = LevenshteinDistance(s1, s2);
    cout << "S1: " << s1 << " Len: " << s1.length() << endl;
    cout << "S2: " << s2 << " Len: " << s2.length() << endl;

    cout <<"Operations required to convert S1 to S2: " << count << " -> Expected: 3" << endl;

}

int main() {
    test_LD();
    return 0;
}