
#include <iostream>

#include "ModelHierarchies/ScriptureHierarchy/ChapterMeaning/ChapterMeaning.h"

int main() {
     int x = 5;

     scrptm::ChapterMeaning meaning{ scrptm::Meaning("meaning", scrptm::Language("laja", "asdf", "jhasdklf")), };

     std::cout << meaning.getLanguage().getLanguageCode() << std::endl;

     return 0;
}
