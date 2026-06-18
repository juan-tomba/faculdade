JAVAC = javac
JAVA = java
CLASSE_PRINCIPAL = trabalhos.trabalho7.Main

all: run

compile:
	$(JAVAC) *.java

run: compile
	$(JAVA) -cp ../.. $(CLASSE_PRINCIPAL)

clean:
	rm -f *.class