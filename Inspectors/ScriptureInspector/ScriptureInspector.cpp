#include "ScriptureInspector.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <format>


namespace scrptm {
    ScriptureInspector::ScriptureInspector() {
    }


    unsigned char ScriptureInspector::getUserInput(unsigned char max_value, char &selection_char) const {
        selection_char = 0;
        unsigned long input_value = 0;
        std::string input_line;

        std::cout << "Please enter a number between 1 and " << static_cast<unsigned int>(max_value)
                << " or 'q' to quit: ";

        while (std::getline(std::cin, input_line)) {
            input_line.erase(0, input_line.find_first_not_of(" \t\n\r"));
            input_line.erase(input_line.find_last_not_of(" \t\n\r") + 1);

            if (input_line.length() == 1 && (input_line[0] == 'q' || input_line[0] == 'Q')) {
                selection_char = 'q';
                return 0;
            }

            try {
                size_t pos;

                input_value = std::stoul(input_line, &pos);

                if (pos != input_line.length() || input_value == 0 || input_value > max_value) {
                    if (pos != input_line.length() || input_value == 0) {
                        std::cerr << "Invalid input format or value is zero. Please enter a valid integer (1-" <<
                                static_cast<int>(max_value) << ") or 'q'.\n";
                    } else {
                        std::cerr << "Error: Input " << input_value << " is out of range (1-" << static_cast<int>(
                                    max_value) <<
                                ").\n";
                    }

                    std::cout << "Input: ";
                    continue;
                }

                return static_cast<unsigned char>(input_value);
            } catch ([[maybe_unused]] const std::invalid_argument &e) {
                std::cerr << "Invalid input format (non-numeric characters found). Please enter an integer or 'q'.\n";
            } catch ([[maybe_unused]] const std::out_of_range &e) {
                std::cerr << "Input number is too large. Please enter a value between 1 and "
                        << static_cast<unsigned int>(max_value) << ".\n";
            }

            std::cout << "Input: ";
        }

        return 0;
    }

    using namespace tabulate;


    void ScriptureInspector::inspect(const Scripture &scripture) const {
        std::cout << "\n--- Scripture Inspection Interface ---\n";
        std::cout << "Scripture Name: " << scripture.getName() << std::endl;

        std::string meaningStr{};
        for (const auto &meaning: scripture.getMeanings()) {
            meaningStr += std::format("(Meaning: {}, Language: {}); ",
                                      meaning->getMeaning(),
                                      meaning->getLanguage().getLanguageEnglish());
        }
        std::cout << "Meanings: " << meaningStr << "\n";
        std::cout << "--------------------------------------\n";

        const unsigned char MAX_CHOICE = 1;
        char exit_flag = 0;
        unsigned char selection = 0;

        while (exit_flag != 'q') {
            std::cout << "\n[MENU] Available Options:\n";
            std::cout << "1. Inspect Sections Detail\n";
            std::cout << "Enter (1) or 'q' to quit: ";

            selection = this->getUserInput(MAX_CHOICE, exit_flag);

            if (exit_flag == 'q') {
                std::cout << "[INFO] Exiting Scripture Inspector.\n";
                break;
            }

            if (selection > 0) {
                switch (selection) {
                    case 1: {
                        std::cout << "[ACTION] Displaying all sections summary...\n";

                        const auto &sections = scripture.getSections();
                        this->printSections(sections);

                        this->runSectionSelection(sections);

                        break;
                    }
                    default:
                        std::cout << "[INFO] Please select an option from the menu.\n";
                        break;
                }
            }
        }
    }

    void ScriptureInspector::runChapterSelection(const Section &section) const {
        std::cout << "\n--- CHAPTER SELECTION (Section: " << section.getName() << ") ---\n";

        const auto &chapters = section.getChapters();
        if (chapters.empty()) {
            std::cout << "[WARNING] No chapters found in this section.\n";
            return;
        }

        const unsigned char MAX_CHAPTER_ID = static_cast<unsigned char>(chapters.size());
        char sub_exit_flag = 0;
        unsigned char chapter_number = 0;

        while (sub_exit_flag != 'q') {
            std::cout << std::format("[MENU] Enter Chapter number (1-{}) or 'q' to go back: ", MAX_CHAPTER_ID);

            chapter_number = this->getUserInput(MAX_CHAPTER_ID, sub_exit_flag);

            if (sub_exit_flag == 'q') {
                std::cout << "[INFO] Returning to Section Selection Menu.\n";
                break;
            }

            if (chapter_number > 0) {
                size_t index = chapter_number - 1;

                if (index < chapters.size() && chapters.at(index)) {
                    const Chapter &selectedChapter = *chapters.at(index);

                    this->printChapterDetails(selectedChapter);


                    std::cout << "--------------------------------\n";
                } else {
                    std::cout << "Something went unexpectedly wrong" << std::endl;
                }
            }
        }
    }

    void ScriptureInspector::printChapterDetails(const Chapter &chapter) const {
        std::cout << "\n=================================================================\n";
        std::cout << std::format("CHAPTER DETAILS: {} (ID: {})\n", chapter.getName(), chapter.getNumber());
        std::cout << std::format("Total Verse Count in Chapter: {}\n", chapter.getVerseCount());
        std::cout << "=================================================================\n";

        Table table;

        table.add_row({"Verse No.", "Text", "Simplified Text", "No Vowel Text", "Word Count"});

        const auto &verses = chapter.getVerses();
        for (const auto &verse_ptr: verses) {
            if (!verse_ptr) continue;

            const size_t wordCount = verse_ptr->getWords().size();

            table.add_row({
                std::to_string(verse_ptr->getNumber()),
                std::string(verse_ptr->getText()),
                std::string(verse_ptr->getTextSimplified()),
                std::string(verse_ptr->getTextWithoutVowel()),
                std::to_string(wordCount)
            });
        }


        table.format();

        table[0].format()
                .font_color(Color::green)
                .background_color(Color::grey)
                .font_align(FontAlign::center);


        table.column(0).format().font_align(FontAlign::right);
        table.column(4).format().font_align(FontAlign::right);

        std::cout << "\nVERSE BREAKDOWN:\n";
        std::cout << table << std::endl;
    }


    void ScriptureInspector::runSectionSelection(
        const std::vector<std::unique_ptr<Section> > &sections) const {
        if (sections.empty()) {
            std::cout << "[WARNING] No sections found to inspect.\n";
            return;
        }

        const unsigned char MAX_SECTION_ID = static_cast<unsigned char>(sections.size());
        char sub_exit_flag = 0;
        unsigned char section_number = 0;

        std::cout << "\n--- SECTION SELECTION (Press 'q' to return to Main Menu) ---\n";

        while (sub_exit_flag != 'q') {
            std::cout << std::format("\n[MENU] Enter Section number (1-{}) or 'q' to go back: ", MAX_SECTION_ID);
            section_number = this->getUserInput(MAX_SECTION_ID, sub_exit_flag);

            if (sub_exit_flag == 'q') {
                std::cout << "[INFO] Returning to Main Inspector Menu.\n";
                break;
            }

            if (section_number > 0) {
                size_t index = section_number - 1;

                if (index < sections.size() && sections.at(index)) {
                    const Section &selectedSection = *sections.at(index);

                    this->printSection(sections.at(index));

                    this->runChapterSelection(selectedSection);

                    std::cout << "--------------------------------\n";
                } else {
                    std::cout << "Something went unexpectedtly wrong." << std::endl;
                }
            }
        }
    }

    void ScriptureInspector::printSection(const std::unique_ptr<Section> &section) const {
        std::cout << "\n======================================================\n";
        std::cout << std::format("SECTION DETAILS: {} (ID: {})\n", section->getName(), section->getNumber());
        std::cout << std::format("Total Chapter Count: {}\n", section->getChapterCount());
        std::cout << std::format("Total Verse Count in Section: {}\n", section->getVerseCount());
        std::cout << "======================================================\n";

        Table table;

        table.add_row({"Chapter Number", "Chapter Name", "Verse Count"});

        const auto &chapters = section->getChapters();
        for (const auto &chapter_ptr: chapters) {
            if (!chapter_ptr) continue;

            table.add_row({
                std::to_string(chapter_ptr->getNumber()),
                std::string(chapter_ptr->getName()),
                std::to_string(chapter_ptr->getVerseCount())
            });
        }


        table.format()
                .font_style({FontStyle::bold});

        table[0].format()
                .font_color(Color::cyan)
                .background_color(Color::grey)
                .font_align(FontAlign::center);

        table.column(0).format().font_align(FontAlign::right);
        table.column(2).format().font_align(FontAlign::right);


        std::cout << "\nCHAPTER BREAKDOWN:\n";
        std::cout << table << std::endl;
    }


    void ScriptureInspector::printSections(const std::vector<std::unique_ptr<Section> > &sections) const {
        Table table;

        table.add_row({"Section Number", "Section Name", "Section Meaning English", "Chapter Count", "Verse Count"});

        size_t totalChapterCount = 0;
        size_t totalVerseCount = 0;

        for (const auto &section: sections) {
            auto sectionMeaningMeaningEnglish = section->getMeanings().at(0)->getMeaning();

            const auto chapterCount = section->getChapterCount();
            const auto verseCount = section->getVerseCount();

            totalChapterCount += chapterCount;
            totalVerseCount += verseCount;

            table.add_row({
                std::to_string(section->getNumber()),
                section->getName(),
                sectionMeaningMeaningEnglish,
                std::to_string(chapterCount),
                std::to_string(verseCount)
            });
        }

        table.add_row({"Sum:", "", "TOTAL:", std::to_string(totalChapterCount), std::to_string(totalVerseCount)});


        table.format()
                .font_style({FontStyle::bold});


        table.format()
                .padding_left(1)
                .padding_right(1);


        table[0].format()
                .font_color(Color::yellow)
                .background_color(Color::blue)
                .font_align(FontAlign::center);

        table.column(0).format().font_align(FontAlign::right);
        table.column(1).format().font_align(FontAlign::right);
        table.column(3).format().font_align(FontAlign::right);
        table.column(4).format().font_align(FontAlign::right);

        table.column(2).format().font_align(FontAlign::left);

        const size_t last_row_index = table.size() - 1;
        table[last_row_index].format()
                .font_color(Color::green)
                .background_color(Color::grey)
                .font_style({FontStyle::bold, FontStyle::underline});


        std::cout << table << std::endl;
    }
}
