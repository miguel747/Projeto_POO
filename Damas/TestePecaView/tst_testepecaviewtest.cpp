#include <QString>
#include <QtTest>

#include "pecasView.h"

class TestePecaViewTest : public QObject
{
    Q_OBJECT
    
public:
    TestePecaViewTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase2();
};

TestePecaViewTest::TestePecaViewTest()
{

}

void TestePecaViewTest::initTestCase()
{
}

void TestePecaViewTest::cleanupTestCase()
{
}

void TestePecaViewTest::testCase1()
{
    QPosF pos =
}

void TestePecaViewTest::testCase2()
{
    QVERIFY2(false,"Failure");
}

QTEST_APPLESS_MAIN(TestePecaViewTest)

#include "tst_testepecaviewtest.moc"
