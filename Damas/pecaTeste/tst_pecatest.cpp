#include <QString>
#include <QtTest>

#include "Pecas.h"
class PecaTest : public QObject
{
    Q_OBJECT
    
public:
    PecaTest(){}

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testGetsSets();
    void testConstrutorComParamentro();
    void testConstrutorComParamentro_data();
};

void PecaTest::initTestCase()
{
}

void PecaTest::cleanupTestCase()
{
}

void PecaTest::testGetsSets()
{
    Pecas *peca = new Pecas();
    peca->setDama(true);
    peca->setCor(true);
    QVERIFY2(peca->GetEhDama() == true, "Failure");
    QVERIFY2(peca->GetCor() == true, "Failure");
}

void PecaTest::testConstrutorComParamentro_data()
{
    QTest::addColumn<bool>("Argumento");
    QTest::addColumn<bool>("result");

    QTest::newRow("true") << true << true;
    QTest::newRow("false")<< false << false;
}

void PecaTest::testConstrutorComParamentro()
{
    QFETCH(bool,Argumento);
    QFETCH(bool,result);
    QVERIFY2((new Pecas(Argumento))->GetCor() == Argumento,"Failure");
}

QTEST_APPLESS_MAIN(PecaTest)

#include "tst_pecatest.moc"
