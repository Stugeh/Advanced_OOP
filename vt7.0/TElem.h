#ifndef VT7_0_TELEM_H
#define VT7_0_TELEM_H

template <typename T>
class TElem{
private:
    T val;
public:
    TElem(T pVal): val(pVal) {}

    T getVal() const {
        return val;
    }
};



#endif //VT7_0_TELEM_H
