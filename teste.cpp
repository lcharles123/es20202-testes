#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "bignumber.h"

std::string BIGINT = "1267650600228229401496703205376"; //== 2^100 -> OEIS.org/A002416

TEST_CASE("Teste 1: Metodos aritmeticos:") 
{
    BigNumber a(BIGINT);
    BigNumber b(11);
    
    BigNumber c(0);
    BigNumber res(0);
    
    c = a.add(11);          res = "1267650600228229401496703205387";
    CHECK( c == res );
    
    c = a.subtract(11);     res = "1267650600228229401496703205365";
    CHECK( c == res );
    
    c = b.multiply(11);     res = "121";
    CHECK( c == res );
    
    c = a.divide(BIGINT);   res = "1";
    CHECK( c == res );
    
    c = b.pow(11);          res = "285311670611";
    CHECK( c == res );
}

TEST_CASE("Teste 2: Operadores aritimeticos infix:") 
{   
    BigNumber c(0);
    BigNumber res(0);

    c = BigNumber(BIGINT) + BigNumber(10);          res = "1267650600228229401496703205386";
    CHECK( c == res );
    
    c = BigNumber(0) - BigNumber(BIGINT);           res = "-1267650600228229401496703205376";
    CHECK( c == res );
    
    c = BigNumber(BIGINT) * BigNumber("-2") ;       res = "-2535301200456458802993406410752";
    CHECK( c == res );
    
    c = BigNumber("-2") / BigNumber(BIGINT);        res = "0";
    CHECK( c == res );
}

TEST_CASE("Teste 3: Logica") 
{
    CHECK_FALSE( BigNumber(BIGINT) == BigNumber("-24"));
    CHECK_FALSE( BigNumber("2") < BigNumber(-345) );
    CHECK(  BigNumber(BIGINT) > BigNumber(54) );
    CHECK(  BigNumber("34") >= BigNumber("22") );
    CHECK(  BigNumber("383") <= BigNumber("383") );
}

TEST_CASE("Teste 4: Checar caracteristicas do numero") 
{
    CHECK( BigNumber("-1267650600228229401496703205376").isNegative() );
    CHECK( BigNumber(BIGINT).isPositive() );
    CHECK( BigNumber(BIGINT).isEven() );
    CHECK_FALSE( BigNumber(BIGINT).isOdd() );
}

TEST_CASE("Teste 5: acucar sintatico") 
{
    BigNumber inc("100");
    
    BigNumber mais("111");    
    mais += inc;
    CHECK( mais == BigNumber(211));
    
    BigNumber menos("222");
    menos -= inc;
    CHECK( menos == BigNumber(122));
    
    BigNumber vezes("333");
    vezes *= inc;
    CHECK( vezes == BigNumber(33300));
    
    BigNumber div("444");
    div /= inc;
    CHECK( div == BigNumber(4));
}

TEST_CASE("Teste 6: Incremento") 
{
    BigNumber a("0");
    BigNumber b("0");
    BigNumber c("0");
    BigNumber d("0");

    CHECK( ++a == BigNumber(1));
    CHECK( --b == BigNumber(-1));
    CHECK( c++ == BigNumber(0));
    CHECK( d-- == BigNumber(0));
 }
 
TEST_CASE("Teste 7: Funcoes") 
{ 
    BigNumber att("0");
    att = BigNumber(BIGINT);
    CHECK(att == BigNumber(BIGINT));
    
    CHECK( BigNumber(1110).getString() == "1110" );
    
    BigNumber a("0");
    a.setString("1233");
    CHECK( a == BigNumber(1233) );
    
    CHECK( BigNumber(BIGINT).digits() == 31 );

    BigNumber c(0);       BigNumber bn(-567);    
    c = bn.abs();   
    CHECK( c == BigNumber("567"));
}

TEST_CASE("Teste 8: Misc") 
{
    std::stringstream ss;
    ss << BigNumber(45634576324);
    CHECK( ss.str() == "45634576324" );
    
    CHECK( BigNumber(2333)[0] == 2 );
    CHECK( BigNumber(BIGINT) == BigNumber("-1267650600228229401496703205376").negate() );
}

/**
como usar os macros do doctest:

    CHECK(true);
    REQUIRE(1 < 42);
    <LEVEL> is one of 3 possible: REQUIRE/CHECK/WARN.

    <LEVEL>_EQ(left, right) - same as <LEVEL>(left == right)
    <LEVEL>_NE(left, right) - same as <LEVEL>(left != right)
    <LEVEL>_GT(left, right) - same as <LEVEL>(left > right)
    <LEVEL>_LT(left, right) - same as <LEVEL>(left < right)
    <LEVEL>_GE(left, right) - same as <LEVEL>(left >= right)
    <LEVEL>_LE(left, right) - same as <LEVEL>(left <= right)
    <LEVEL>_FALSE(left, right) 
    <LEVEL>_UNARY(expr) - same as <LEVEL>(expr)
    <LEVEL>_UNARY_FALSE(expr) - same as <LEVEL>_FALSE(expr)
    
    <LEVEL>_THROWS(expression)
    <LEVEL>_THROWS_AS(expression, exception_type)
    <LEVEL>_THROWS_WITH_AS(expression, c_string, exception_type)
    <LEVEL>_NOTHROW(expression)
    
    REQUIRE(22.0/7 == doctest::Approx(3.141).epsilon(0.01)); // allow for a 1% error
    REQUIRE(i():float == doctest::Approx(2.1));
*/

