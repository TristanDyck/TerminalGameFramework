#pragma once
#include "Component.h"

class ComponentConfidence : public Component {
public:
    ComponentConfidence();
    ComponentConfidence(int maxConfidence);
    ComponentConfidence(int maxConfidence, int confidence);
    ComponentConfidence(int maxConfidence, bool unbreakable);
    ComponentConfidence(int maxConfidence, int confidence, bool unbreakable);
    ComponentConfidence(const ComponentConfidence&);
    virtual ComponentConfidence* copy() override;
    ~ComponentConfidence();

    int getMaxConfidence();
    int increaseMaxConfidence(int);
    int getConfidence();
    int increaseConfidence(int);
    void makeUnbreakable(bool);
    // less than -9: flee, -9 to 9: neutral, greater than 9: approach
    int getBehaviour();
private:
    int maxConfidence;
    int confidence;
    bool unbreakable;

    const static int DEFAULT_CONFIDENCE;
    const static bool DEFAULT_UNBREAKABLE;
    const static int CONFIDENCE_THRESHOLD;
};