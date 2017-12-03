#ifndef TSUBJECT_H
#define TSUBJECT_H
#include <vector>

/* A note on InfoType and StateType:
 
 We have separated the collection of fields into two parts:  its Info
 and its State.
 
 Info is for the parts of the subjject inherent to what it is:  its position
 and its colour.
 
 State is for the parts of the subject that, when changed, trigger
 notifications.  This is the information that the Observer "gets" when it
 calls getState on the subject.  It comprises the type of state, a direction,
 and a colour.  For more details, see state.h.
 */

// DO NOT MODIFY THIS FILE!

template <typename InfoType, typename StateType> class Observer;

template <typename InfoType, typename StateType> class TSubject {
    std::vector<Observer<InfoType, StateType>*> Tobservers;
    StateType tState;
protected:
    void setTState(StateType newS);
public:
    void Tattach(Observer<InfoType, StateType> *o);
    void notifyTObservers();
    virtual InfoType getTInfo() const = 0;
    StateType getTState() const;
};

template <typename InfoType, typename StateType>
void TSubject<InfoType, StateType>::Tattach(Observer<InfoType, StateType> *o) {
    Tobservers.emplace_back(o);
}

template <typename InfoType, typename StateType>
void TSubject<InfoType, StateType>::notifyTObservers(TInfo tinfo) {
    for (auto &ob : Tobservers) ob->notify(tinfo);
}

template <typename InfoType, typename StateType>
void TSubject<InfoType, StateType>::setTState(StateType newS) { tState = newS; }

template <typename InfoType, typename StateType>
StateType TSubject<InfoType, StateType>::getTState() const { return tState; }
#endif
