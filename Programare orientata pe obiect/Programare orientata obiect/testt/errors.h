#ifndef ERRORS_H
#define ERRORS_H
class Error {
public:
    Error(QString message) :
            msg(message) {
    }
    const QString& getMessage() const {
        return msg;
    }
private:
    QString msg;
};
#endif // ERRORS_H
