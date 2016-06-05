#ifndef MYTESTS_H
#define MYTESTS_H
class Tests : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTests(TestController *c, QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void addAppointment (QString t, QString d);
    void remRow(int row);
private:
    TestController *ctrl;

};
#endif // MYTESTS_H
