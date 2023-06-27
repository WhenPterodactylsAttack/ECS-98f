/*
 * Unit tests for the pig latin translator using the CUnit framework.
 */
#include <CUnit/Basic.h>

#include "translator_tools.h"

void TestSplitSentenceIntoWords()
{
	CU_ASSERT(**SplitSentenceIntoWords("who what when where"));
	CU_ASSERT(**SplitSentenceIntoWords("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	CU_ASSERT(**SplitSentenceIntoWords("abcdefghijklmnopqrstuvwxyz"));
	CU_ASSERT(**SplitSentenceIntoWords("wh0 what wh3n where"));
	CU_ASSERT(**SplitSentenceIntoWords(" ok"));
}

void TestWordHasOnlyLetters()
{
	CU_ASSERT(WordHasOnlyLetters("the"));
	CU_ASSERT(WordHasOnlyLetters("who"));
	CU_ASSERT(WordHasOnlyLetters("Jimothy"));
	CU_ASSERT(!WordHasOnlyLetters("wh0"));
	CU_ASSERT(!WordHasOnlyLetters("123"));
	CU_ASSERT(!WordHasOnlyLetters("*"));
}

void TestToLowerCase()
{	   
	char w1[] = "WOAH";
	ToLowerCase(w1);
	CU_ASSERT(strcmp(w1,"woah") == 0);
}

void TestIsVowel()
{
	// positive
	CU_ASSERT(IsVowel('a'));
	CU_ASSERT(!IsVowel('A'));
	CU_ASSERT(IsVowel('e'));
	CU_ASSERT(IsVowel('i'));
	CU_ASSERT(IsVowel('o'));
	CU_ASSERT(IsVowel('u'));
	// negative
	CU_ASSERT(!IsVowel('p'));
}

void TestGetConsonantCluster()
{
	CU_ASSERT(strcmp(GetConsonantCluster("string"), "str") == 0);
	CU_ASSERT(GetConsonantCluster("")  == NULL); 
	CU_ASSERT(strcmp(GetConsonantCluster("BCDFGHJKLMNPQRSTVWXZ"), "BCDFGHJKLMNPQRSTVWXZ") == 0);
}

void TestStripString()
{
	CU_ASSERT(strcmp(StripString("foobarbaz", 3), "barbaz") == 0);
}

void TestStringConcat()
{
	CU_ASSERT(strcmp(StringConcat("hello", "there"), "hellothere") == 0);
}

int main(void)
{
	// Initialize CUnit
	CU_initialize_registry();
	CU_pSuite pSuite = CU_add_suite("TranslatorToolsTests", NULL, NULL);

	// Register unit tests
	CU_add_test(pSuite, "SplitSentenceIntoWords", TestSplitSentenceIntoWords);
	CU_add_test(pSuite, "WordHasOnlyLetters", TestWordHasOnlyLetters);
	CU_add_test(pSuite, "ToLowerCase", TestToLowerCase);
	CU_add_test(pSuite, "IsVowel", TestIsVowel);
	CU_add_test(pSuite, "GetConsonantCluster", TestGetConsonantCluster);
	CU_add_test(pSuite, "StripString", TestStripString);
	CU_add_test(pSuite, "StringConcat", TestStringConcat);

	// Run all tests
	CU_basic_run_tests();

	// Clean up & exit
	CU_cleanup_registry();
	return 0;
}
