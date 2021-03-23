# es20202-testes
Exercicios sobre implementação de testes - UFMG 20202 - Engenharia de software

Nestre exercicio foi testado uma biblioteca em C++ chamada [BigNumber](https://github.com/Limeoats/BigNumber), ela eh usada na manipulacao de numeros com precisao arbitraria.

Foi usado o framework de testes [doctest.h](https://github.com/onqtam/doctest).

Tanto o doctest quanto a biblioteca sao "header-only" e nao possui dependencias, bastando baixar o codigo e
```sh
make
```
Sao 8 TEST_CASEs, cada um testa funcionalidades similares e alguns corner cases. 

Note que um dos testes falha, indicando um problema no codigo da biblioteca.

