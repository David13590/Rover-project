#ifndef DECISION_HPP_
#define DECISION_HPP_

class decision{
    public:
        struct decisionReturnPercent{
            int motorPercentLeft;
            int motorPercentRight;
        };
        decisionReturnPercent* get_decision();
    private:
        decisionReturnPercent myMotorPercent;
};
#endif