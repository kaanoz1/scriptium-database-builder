#include "ScriptureIndicator.h"

namespace scrptm {
    ScriptureIndicator::ScriptureIndicator(char scriptureCode) : scriptureCode(scriptureCode) {
    }

    char ScriptureIndicator::getScriptureCode() const {
        return this->scriptureCode;
    }
} // scrptm
