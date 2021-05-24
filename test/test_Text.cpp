#include <gtest.h>
#include "text.h"
#include "text_node.h"

TEST(TText, can_create_empty_text)
{
  ASSERT_NO_THROW(TText A());
}

TEST(TText, can_create_non_empty_text)
{
    char* const temp = "Hello World";
    ASSERT_NO_THROW(TText A(temp));
}

TEST(TText, get_the_first_character_of_the_next_word) {
    char* const temp = "Hello World";
    TText A(temp);
    TTextIter iter = A.GetRoot();

    while (iter.Get()->GetC() != ' ')
        iter.GoNextChar();


    iter.GoNextChar();
    ASSERT_EQ(iter.Get()->GetC(), 'W');
}


TEST(TTextIter, get_the_first_character) 
{
  char* const temp = "Hello World";
  TText A(temp);
  TTextIter iter = A.GetRoot();
  iter.GoNextChar();
  ASSERT_EQ(iter.Get()->GetC(), 'H');
}


TEST(TTextIter, cannot_get_the_next_character_if_there_is_none) 
{
  char* const temp = "A";
  TText A(temp);
  TTextIter iter = A.GetRoot();
  iter.GoNextChar();

  ASSERT_EQ(iter.GoNextChar(), false);
}

TEST(TTextIter, can_go_next) 
{
  char* const temp = "Hello World";
  TText A(temp);
  TTextIter iter = A.GetRoot();
  ASSERT_EQ(iter.GoNext(), true);
}

TEST(TText, can_find_the_letter)
{
  char* const temp = "Hello World";
  TText A(temp);
  TTextIter iter = A.Find('e');
  iter.GoNextChar();
  ASSERT_EQ(iter.Get()->GetC(), 'l');
}

TEST(TText, can_insert_a_letter)
{
  char* const temp = "Hello World";
  TText A(temp);
  TTextIter iter = A.GetRoot();
  
  ASSERT_NO_THROW(A.Insert("Q", iter));
}

TEST(TText, can_insert_a_word_in_empty_space)
{
    char* const temp = "Hello World";   
    TText A(temp);
    TTextIter iter = A.GetRoot();
    TTextIter B = A.Find("o");

    ASSERT_NO_THROW(A.InsertData("this big and beautifull", B));
}

TEST(TText, can_insert_a_word_in_word)
{
    char* const temp = "Hello World\n   ";
    TText A(temp);
    TTextIter iter = A.GetRoot();
    TTextIter B = A.Find("l");

    ASSERT_NO_THROW(A.InsertLine("this big and beautifull", B));
}

TEST(TText, can_find_the_word) 
{
  char* const temp = "Hello World";
  TText A(temp);

  char* const temp_find = "Hello";
  TTextIter iter = A.FindWord(temp_find);
  iter.GoNextChar();
  ASSERT_EQ(iter.Get()->GetC(), 'H');
}

TEST(TText, text_find_word_3)
{
  char* const temp = "Hello World";
  TText A(temp);

  char* const temp_find = "qwe";
  TTextIter iter = A.FindWord(temp_find);
  ASSERT_EQ(iter.IsEnd(), true);
}

TEST(TText, text_delete)
{
  char* const temp = "Hello World";
  TText A(temp);

  char* const temp_find = "World";
  TTextIter iter = A.FindWord(temp_find);
  ASSERT_NO_THROW(A.Delete(1, iter));
}

TEST(TText, can_copy) 
{
  char* const temp = "Hello World";
  TText A(temp);

  char temp_find = 'd';
  TTextIter iter = A.Find(temp_find);
  
  ASSERT_NO_THROW(char* res = A.Copy(1, iter));
}