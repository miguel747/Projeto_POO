#include <QString>
#include <QtTest>

#include "Casa.h"
#include <stdlib.h>
#include <time.h>

class CasaTesteTest : public QObject
{
    Q_OBJECT
    
public:
    CasaTesteTest();
    


private Q_SLOTS:
    void testcalcDistance();
    void testConstrutores();
};

CasaTesteTest::CasaTesteTest()
{
}

void CasaTesteTest::testcalcDistance()
{
    srand(time(NULL));

    Casa a(0,0,true,NULL);
    Casa b(0,0,true,NULL);

    QCOMPARE(a.Distancia(b)  ,float(.0));

    b.SetX(1);
    b.SetY(1);
    QCOMPARE(a.Distancia(b)  ,float(sqrt(2)));

    b.SetX(2);
    b.SetY(2);
    QCOMPARE(a.Distancia(b)  ,float(2*sqrt(2)));

    b.SetX(5);
    b.SetY(4);

    QCOMPARE(a.Distancia(b),float(sqrt(pow(5,2)+pow(4,2))));

    for(int i = 0;i<1000;i++){
        int auxX = rand()%8;
        int auxY = rand()%8;
        b.SetX(auxX);
        b.SetY(auxY);

        QCOMPARE(a.Distancia(b),float(sqrt(pow(auxX,2)+pow(auxY,2))));
    }
}
void CasaTesteTest::testConstrutores()
{
    Casa a(0,0,true,NULL);

    QVERIFY2(a.GetCor() == true,"Failure");
    QVERIFY2(a.GetPedra() == NULL,"Failure");
    QVERIFY2(a.GetX()== 0,"Failure");
    QVERIFY2(a.GetY()== 0,"Failure");

    Casa b;

    QVERIFY2(b.GetPedra() == NULL,"Failure");
}

QTEST_APPLESS_MAIN(CasaTesteTest)

#include "tst_casatestetest.moc"
