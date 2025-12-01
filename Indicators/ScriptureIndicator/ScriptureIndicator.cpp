#include "ScriptureIndicator.h"

namespace scrptm {
    ScriptureIndicator::ScriptureIndicator(unsigned char scriptureCode) : scriptureCode(scriptureCode) {
    }

    unsigned char ScriptureIndicator::getScriptureCode() const {
        return this->scriptureCode;
    }
} // scrptm
