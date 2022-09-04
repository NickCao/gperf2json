#include "input.h"
#include <iostream>

class KeywordExt_Factory : public Keyword_Factory {
  virtual Keyword *create_keyword(const char *allchars, int allchars_length,
                                  const char *rest);
};

Keyword *KeywordExt_Factory::create_keyword(const char *allchars,
                                            int allchars_length,
                                            const char *rest) {
  return new KeywordExt(allchars, allchars_length, rest);
}

int main() {
  KeywordExt_Factory factory;
  Input inputter(stdin, &factory);
  inputter.read_input();
  KeywordExt_List *list = static_cast<KeywordExt_List *>(inputter._head);
  for (KeywordExt_List *temp = list; temp; temp = temp->rest()) {
    auto head = temp->first();
    fwrite(head->_allchars, sizeof(char), head->_allchars_length, stdout);
    std::cout << head->_rest << std::endl;
  };
}
