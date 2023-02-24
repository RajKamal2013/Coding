#include <iostream>
#include <string>
using namespace std;

using namespace std;

int levenshteinDistanceInt(string str1, int idx1, string str2, int idx2) {
    if (idx1 >= str1.length()) {
        return str2.length();

    }

    if (idx2 >= str2.length()) {
        return str1.length();
    }

    int cost = 0;
    if (str1[idx1] == str2[idx2]) {
        cost = 0;
    } else {
        cost = 1;
    }

    int right, left, mid;
    
    right = levenshteinDistanceInt(str1, idx1 + 1, str2, idx2);
    left = levenshteinDistanceInt(str1, idx1, str2, idx2 + 1);
    mid = levenshteinDistanceInt(str1, idx1 + 1, str2, idx2 + 1) + cost; 
   
	    int ret = min(right, left);
    return min(ret, mid);
}

int levenshteinDistance(string str1, string str2) {
  if (str1.length() == 0) {
      return str2.length();
  }

  if (str2.length() == 0) {
      return str1.length();
  }

  return levenshteinDistanceInt(str1, 0, str2, 0);
}

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
