#include "input.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

using json = nlohmann::json;

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
  std::unordered_map<std::string, std::string> directives;
  for (KeywordExt_List *temp = list; temp; temp = temp->rest()) {
    auto head = temp->first();
    auto rest = std::string(head->_rest);
    auto begin = std::find_if(rest.begin(), rest.end(), [](unsigned char ch) {
      return !std::isspace(ch);
    });
    rest.erase(rest.begin(), begin);
    directives.emplace(std::string(head->_allchars, head->_allchars_length),
                       rest.substr(0, rest.find(",")));
  };
  json a = directives;
  std::cout << a.dump() << std::endl;
}
