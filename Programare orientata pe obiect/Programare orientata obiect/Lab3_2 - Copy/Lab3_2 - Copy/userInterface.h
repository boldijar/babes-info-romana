#ifndef USERINTERFACE_H
#define USERINTERFACE_H


#include "controller.h"


using namespace std;

class UserInterface
{
    public:

        /** Default constructor */
        UserInterface();
        /** Default destructor */
        virtual ~UserInterface();
        /** Access m_ctrl
         * \return The current value of m_ctrl
         */
        Controller& GetController() { return m_ctrl; }
        /** Set m_ctrl
         * \param val New value to set
         */
        void SetController(Controller& val) { m_ctrl = val; }

        /** Show commands method **/
        void DisplayMenu();
        /** **/
        void AnalyzeCommand(int);
        /** **/

        /** **/
        void GetCommand(int&);
        /** **/
    protected:
    private:
        Controller m_ctrl; //!< Member variable "m_ctrl"
};

#endif // USERINTERFACE_H
