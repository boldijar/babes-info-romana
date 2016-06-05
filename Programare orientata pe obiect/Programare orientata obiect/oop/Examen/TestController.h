#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H
class TestController {
public:
    TestController(TestRepository* r);
    QList<Test> getList();
    void add(QString t, QString d);
    void removeById(int id);
private:
    TestRepository* repo;
};
#endif // TESTCONTROLLER_H
