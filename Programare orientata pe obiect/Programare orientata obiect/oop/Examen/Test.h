#ifndef TEST_H
#define TEST_H
class Test {
public:
    Test(int i, int c, int a , int m) : id(i), correctAnswers(c), questionCount(q), maxQuestionCount(m) {}

    void setId(int i);
    const int getId() const;

    void setCorrectAnswer(int c);
    const int getCorrectAnswer() const;

    void setQuestionCount(int q);
    const int getQuestionCount() const;

    void setMaxQuestionCount(int q);
    const int getMaxQuestionCount() const;

    bool operator <(const Test &other) const;
    bool isValid();
private:
    int id,c,q,m;
};
#endif // TEST_H
