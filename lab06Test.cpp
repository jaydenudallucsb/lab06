#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "WordCount.h"
#include "tddFuncs.h"
int main () {

    std::string testing = "Hello. My name is Jay and I'm a student at the University of \
    California, Santa Barbara studying Computer Engineering and minoring in Statistical \
    Science. I love the gym, the beach, and all sorts of nature activities.";
    
    std::string testing2 = "H";
    WordCount myTable;
    std::istringstream stream(testing);
    std::string word;

    while (stream >> word) {
        myTable.incrWordCount(word);
    }
    std::string test1 = "Test 1: testing size";
    std::string test2 = "Test2: testing word count";
    assertTrue((myTable.getTotalWords() == 36), test1, 20);
    assertTrue((myTable.getWordCount("and") == 3), test2, 23);
    assertTrue((myTable.getWordCount("donkey") == 0), "Test word that doesn't exist", 25);
    myTable.decrWordCount("and");
    assertTrue((myTable.getWordCount("and")) == 2, "Testing word count after removal", 27);
    assertTrue((myTable.decrWordCount("cat") == -1), "Testing decrement word that doesnt exist", 28);

    stream.clear();
    stream.str(testing);
    std::string word2;
    while (stream >> word2) {
        myTable.decrWordCount(word2);
    }
    std::string test3 = "Test 3";
    assertTrue((myTable.getTotalWords() == 0), test3, 31);

    WordCount table;

    std::string longWord(1000, 'a'); // string of 1000 'a's
    table.incrWordCount(longWord);
    assertEquals("1", std::to_string(table.getTotalWords()), "Extremely Long Word Count", __LINE__);
    assertEquals("1", std::to_string(table.getWordCount(longWord)), "Count of Long Word", __LINE__);

    // No Valid Words
    std::string noWords = "!@#$%^&*()1234567890";
    std::istringstream stream2(noWords);
    std::string word3;
    while (stream2 >> word3) {
        table.incrWordCount(word3);
    }
    assertEquals("1", std::to_string(table.getTotalWords()), "Total Words After No Valid Words", __LINE__);

    // Test 3: Very High Frequency
    for (int i = 0; i < 1000000; ++i) {
        table.incrWordCount("test");
    }
    assertEquals("1000000", std::to_string(table.getWordCount("test")), "High Frequency Word Count", __LINE__);
    assertEquals("1000001", std::to_string(table.getTotalWords()), "Total Words After High Frequency", __LINE__);
}

