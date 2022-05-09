#include "ComponentConfidence.h"
#include <stdlib.h>

const int ComponentConfidence::DEFAULT_CONFIDENCE = 100;
const bool ComponentConfidence::DEFAULT_UNBREAKABLE = false;
const int ComponentConfidence::CONFIDENCE_THRESHOLD = 9;

ComponentConfidence::ComponentConfidence() : ComponentConfidence(DEFAULT_CONFIDENCE) {}
ComponentConfidence::ComponentConfidence(int maxConfidence) 
    : ComponentConfidence(maxConfidence, maxConfidence) {}
ComponentConfidence::ComponentConfidence(int maxConfidence, int confidence) 
    : ComponentConfidence (maxConfidence, confidence, DEFAULT_UNBREAKABLE) {}
ComponentConfidence::ComponentConfidence(int maxConfidence, bool unbreakable) 
    : ComponentConfidence(maxConfidence, maxConfidence, DEFAULT_UNBREAKABLE) {}
ComponentConfidence::ComponentConfidence(int maxConfidence, int confidence, bool unbreakable)
    : Component(1), maxConfidence(abs(maxConfidence)), confidence(confidence), unbreakable(unbreakable) {
    this->confidence = __max(-maxConfidence, this->confidence);
    this->confidence = __min(maxConfidence, this->confidence);
}
ComponentConfidence::ComponentConfidence(const ComponentConfidence& original) 
    : ComponentConfidence(original.maxConfidence, original.confidence, original.unbreakable) {}
ComponentConfidence::~ComponentConfidence() {}

ComponentConfidence* ComponentConfidence::copy() {
    return new ComponentConfidence(*this);
}

int ComponentConfidence::getMaxConfidence() {
    return maxConfidence;
}
int ComponentConfidence::increaseMaxConfidence(int amount) {
    maxConfidence+=amount;
    maxConfidence = __max(amount, 0); //cannot be less than 0
    return maxConfidence;
}
int ComponentConfidence::getConfidence() {
    return confidence;
}
int ComponentConfidence::increaseConfidence(int amount) {
    confidence += amount;
    confidence = __max(-maxConfidence, confidence);
    confidence = __min(maxConfidence, confidence);
    return confidence;
}

// not affected by confidence value while unbreakable
void ComponentConfidence::makeUnbreakable(bool unbreakable) {
    this->unbreakable = unbreakable;
}

// less than -9: flee, -9 to 9: neutral, greater than 9: approach
// if unbreakable, always approach
int ComponentConfidence::getBehaviour() {
    int result = 0;
    if(!unbreakable && confidence < -CONFIDENCE_THRESHOLD)
        result = -1;
    else if (unbreakable || confidence > CONFIDENCE_THRESHOLD)
        result = 1;
    return result;
} 