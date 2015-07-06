//
// Created by Lingurar Petru-Mugurel on 06.07.2015.
//

#include "Numbered.h"


Numbered::Numbered() : serialNo(serialNoCount++) { }


// putting such an initialization in the header file would duplicate the
// initialization code in every place where the header is included.
int Numbered::serialNoCount = 135;


#ifdef ex_fifteen

Numbered::Numbered(const Numbered &copyFromMe_) {
    serialNo = serialNoCount++;
}

Numbered&
Numbered::operator=(const Numbered &copyFromMe_) {
    /*this->*/ serialNo = copyFromMe_.serialNo + 1;
    return *this;
}

#endif