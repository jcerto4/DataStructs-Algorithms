//Joe Certo
//ThreeState.h
//9/18/2025

using namespace std;

#ifndef THREESTATE_H
#define THREESTATE_H

class ThreeState{

private:
    int _state;
public:
    ThreeState() : ThreeState(0) {}
    ThreeState(ThreeState& ts){
        this->_state = ts._state;
    }
    ThreeState(int state){
        _state = state;
    }
    ThreeState& up(){
        if(_state == 2){
            return *this;
        }
        ++_state;
        return *this;
    }
    ThreeState& down(){
        if(_state == 0){
            return *this;
        }
        --_state;
        return *this;
    }
    int state(){
        return _state;
    }

    friend ostream& operator<<(ostream& os, const ThreeState &ts);
};

    ostream& operator<<(ostream& os, const ThreeState &ts){
        string tmp;
        if(ts._state > 1){
            tmp = "high";
        }else if(ts._state == 1){
            tmp = "low";
        }else{
            tmp = "off";
        }
        os << tmp;
        return os; 
    }


#endif
