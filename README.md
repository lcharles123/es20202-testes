# es20202-testes
Exercicios sobre implementação de testes - UFMG 20202 - Engenharia de software

Nestre exercicio foi testado uma biblioteca em C++ chamada [BigNumber](https://github.com/Limeoats/BigNumber), ela eh usada na manipulacao de numeros com precisao arbitraria, a lista de metodos testados encontra-se no README do repositorio da biblioteca.

Foi usado o framework de testes [doctest.h](https://github.com/onqtam/doctest).

Tanto o doctest quanto a biblioteca sao "header-only" e nao possuem dependencias, bastando baixar este codigo e
```sh
make
```
Sao 8 TEST_CASEs, cada um checa funcionalidades similares e alguns corner cases. 

Note que um dos testes falha, indicando um problema no codigo da biblioteca.

