GCC=g++ -std=c++11 

run: testes
	./$^

testes: teste.o bignumber.o
	$(GCC) -o $@ $^

teste.o: teste.cpp 
	$(GCC) -c $^ -o $@

bignumber.o: bignumber.cpp
	$(GCC) -c $^ -o $@

clean: 
	rm -rf testes *.o

help:
	@printf "\n\tEngenharia de Software - UFMG 2020/2\n"
	@printf "\tImplementacao de testes para as bibliotecas em C++.\n\n"
	@printf "\tModo de usar:\n\n"
	@printf "\tmake [Targets]\n\n"
	@printf "\tLista de Targets:\n"
	@printf "\t       : compilar e executar testes\n"
	@printf "\thelp   : mostrar esta ajuda\n\n"

