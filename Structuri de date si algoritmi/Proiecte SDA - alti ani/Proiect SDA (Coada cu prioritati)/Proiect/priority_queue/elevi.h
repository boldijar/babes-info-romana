#ifndef ELEVI_H_INCLUDED
#define ELEVI_H_INCLUDED

#include<string>

namespace domain{
class Elev {


    std:: string nume , prenume;
    float priority;

public:

    Elev(   const std:: string& _nume="" , const std:: string& _prenume="", const float& _priority=0  ):
        nume(_nume ) , prenume(_prenume) , priority( _priority )
        {

        }

    const std:: string& getNume() const;
    const std:: string& getPrenume() const;
    float getPriority()  const;






};

}

#endif // ELEVI_H_INCLUDED
