#ifndef TESTREPOSITORY_H
#define TESTREPOSITORY_H
class TestRepository {
public:
    TestRepository();
    void add(Test t);
    QList<Test> getList();
    void removeById(int id);

private:
    QList<Test> aList;
    int lastId;
};
#endif // TESTREPOSITORY_H
